//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "buslinegui.h"
#include "busline.h"
#include "mymap.h"
#include "streetgui.h"
#include "street.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

class StreetGUI;
class BusLineGUI;
class BusLine;
class MyMap;
class Street;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *getMap_Scene();
    int getSec();
    Ui::MainWindow *getUi();
    void setLines(QVector<BusLineGUI*> lines);
    void listStreetInfos(QString idStreet, int traffic);
    void listStopInfos(QString idStop, QString idStreet);
    void listBusLineInfos(BusLine *line);

private:
    Ui::MainWindow *ui;                 /// Referencia na užívateľské okno.
    MyMap *map_scene;                   /// Referencia na grafickú scénu - mapu.
    QTimer *timer;                      /// Ukazateľ na objekt - časovač.
    QVector<BusLineGUI*> lines;         /// Ukazateľ na vektor všetkých spojov na mape.

    int min = 10;                       /// Minúty globálneho času, premenná pre timer
    int sec = 6000;                     /// Sekundy globálneho času, premenná pre timer

private slots:
    void zoom(int a);
    void TimerEvent();
    void setTraffic(int a);

signals:

};
#endif // MAINWINDOW_H
