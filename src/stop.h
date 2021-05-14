//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#ifndef STOP_H
#define STOP_H

#include "coordinate.h"
#include "street.h"
#include "busline.h"
#include <math.h>

#include <QObject>
#include <QVector>

class Street;
class BusLine;

class Stop : public QObject
{
    Q_OBJECT
public:
    explicit Stop(QString id, Coordinate *position, Street *street);
    void addLine(BusLine *line);

    QString getId();
    Coordinate *getPosition();
    Street *getStreet();

private:
    QString id;                     /// Identifikátor zastávky - jej názov.
    Coordinate *position;           /// Súradnica zastávky na ulici.
    Street *street;                 /// Ulica na ktorej zastávka leží.
    QVector<BusLine*> lines;        /// Zoznam liniek, ktoré má zastávka.

signals:

};

#endif // STOP_H
