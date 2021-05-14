//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#ifndef MYMAP_H
#define MYMAP_H

#include <QGraphicsScene>
#include "mainwindow.h"
#include "busline.h"
#include "buslinegui.h"
#include "stopgui.h"
#include "coordinate.h"
#include <QKeyEvent>
#include <QVector>

class QKeyEvent;
class MainWindow;
class BusLine;
class BusLineGUI;
class Street;
class StreetGUI;
class Stop;
class StopGUI;
class Coordinate;

class MyMap : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyMap(QObject *parent = nullptr);
    explicit MyMap(MainWindow *mainwindow);

    void MapObjectsInit(void);
    QVector<BusLine*> getLinks();
    void addLink(BusLine *link);
    QVector<BusLineGUI*> getLinksGUI();
    void addLinkGUI(BusLineGUI *link);
    QVector<StreetGUI *> getStreetsGUI();
    void setClosedStreet(StreetGUI *streetGUI);
    StreetGUI *getClosedStreet();
    MainWindow *getMainwindow();
    void setEditingMode(bool mode);
    bool getEditingMode();
    void addDetourItems(QList<QGraphicsItem*> items);
    void AppendNewStreetsToLine();
    void makeMarkers();
    void makeMarker(int buslineGUI_index);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;


private:
    MainWindow* mainwindow = nullptr;           /// Referencia na hlavné okno.
    QVector<BusLine*> vecLinks;                 /// Vektor ukazateľov na všetky spoje liniek.
    QVector<BusLineGUI*> vecLinksGUI;           /// Vektor ukazateľov na všetky GUI spoje liniek.
    QVector<StreetGUI*> vecStreetsGUI;          /// Vektor ukazateľov na všetky GUI ulice.

    bool EditingMode = false;                   /// Bool hodnota udáva či sa scéna nachádza v editovacom móde -> zadávanie obchádzky
    StreetGUI *closedstreet = nullptr;          /// Ukazateľ na grafický objekt ulice, ktorá je uzatvorená

    QVector<StreetGUI*> detour_streets;         /// Vektor ulíc obchádzky
    QVector<StopGUI*> detour_deleted_stops;     /// Vektor zastávok, ktoré sa zmažú z linky pri obchádze

signals:

};

#endif // MAP_H
