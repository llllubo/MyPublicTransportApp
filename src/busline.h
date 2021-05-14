//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//



#ifndef BUSLINE_H
#define BUSLINE_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "stop.h"
#include "street.h"
#include "mainwindow.h"
#include "buslinegui.h"

#include <QObject>
#include <QVector>
#include <QPair>
#include <QList>

class Stop;
class Street;
class MainWindow;
class MyMap;
class BusLineGUI;

class BusLine : public QObject
{
    Q_OBJECT
public:
    explicit BusLine(QObject *parent = nullptr);
    explicit BusLine(MainWindow* mainwindow);
    QString getId();
    void setId(QString id);
    Coordinate *getPosition();

    void setPosition(Coordinate *c);
    QVector<Stop*> getStops();
    QVector<Street *> getStreets();
    QVector<Coordinate*> getBreakPoints();
    void addStop(Stop *s);
    int getNumofLinks();
    void setNumofLinks(int num);
    int getDepFreq();
    void setDepFreq(int freq);
    void setStreets();
    bool setBreakPoints();
    void setBusGUI(BusLineGUI *buslineGUI);
    void setTimeStop(QList<QString> timeList);
    QVector<int> getTimeStops();
    void setStreetsDeroute(QVector <Street *> DerouteStreets, QVector<Stop *> DerouteDeletedStops, QString closed_street_id);
    int getStopIndex();
    int getStreetIndex();
    int getDelay();


    void takeStep();

private:
    QString id;                                  /// Číslo linky.
    int numofLinks;                              /// Počet spojov danej linky.
    int depFreq = 0;                             /// Frekvencia príchodov linky na zastávky.

    QVector<Stop*> stops;                        /// Zastávky linky. Zastávka drží informáciu o tom, na akej ulici sa nachádza.
    QVector<Street*> streets;                    /// Ulice linky.
    QVector<Coordinate*> break_points;           /// Body zlomov linky, kde budú spoje odbočovať na ďalšiu ulicu.

    int stop_index = 0;                          /// Ukazateľ (číslo indexu) na akutálnu zastávku spoja.
    int street_index = -1;                       /// Ukazateľ (číslo indexu) na akutálnu ulicu spoja.
    int break_points_index = 0;                  /// Ukazateľ (číslo indexu) na akutálny bod zlomu.


    Coordinate *position;                        /// Pozícia spoja.

    int eps = 3;                                 /// Pomocná premenná pre odchílku vzdialenosti pozície spoja od pozície zastávky
    int step_size = 10;                          /// Veľkosť kroku spoja na ulici
    int stop_wait = 0;                           /// Int hodnota udáva, či spoj m.
    int delay = 0;                               /// Hodnota v sekundách, koľko daný spoj mešká

    BusLineGUI *busGUI;                          /// Odkaz na objekt GUI spoja, pre nastavenie viditeľnosti po tom čo vyrazí z počiatočného bodu
    MainWindow* mainwindow;                      /// Odkaz na objekt MainWindow, pre získanie časového údaju

    QVector<int> timesStops;                     /// V mape sú uložené dvojice zastávka a čas
    QVector<int> new_times_stops;                /// Vektor údajov o nových časoch v prípade otočenia linky


signals:

};

#endif // BUSLINE_H
