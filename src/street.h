//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#ifndef STREET_H
#define STREET_H

#include "coordinate.h"
#include "stop.h"

#include <QObject>
#include <QVector>

class Stop;

class Street : public QObject
{
    Q_OBJECT
public:
    explicit Street(QString id, Coordinate *start, Coordinate *end);

    void addStop(Stop *stop);

    Coordinate *getStart();
    Coordinate *getEnd();
    float getT_Step();
    QString getId();
    int getTraffic();
    int getLength();

    void setTraffic(int traffic);

private:
    QString id;                 /// Identifikátor ulice.
    Coordinate *start;          /// Začiatok ulice.
    Coordinate *end;            /// Koniec ulice.

    int traffic = 0;           /// Celé číslo udáva preťaženie ulice.
    int length;                 /// Dĺžka ulice.

    QVector<Stop*> stops;       /// Zoznam zastávok ulice.


signals:

};

#endif // STREET_H
