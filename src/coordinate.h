//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#ifndef COORDINATE_H
#define COORDINATE_H

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include <math.h>
#include <QObject>

class Coordinate : public QObject
{
    Q_OBJECT
public:
    explicit Coordinate(QObject *parent = nullptr);
    explicit Coordinate(int x, int y);
    int getX();
    int getY();
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);

    static int distance(Coordinate *first, Coordinate *second);
    static Coordinate *cross_point(Coordinate *A, Coordinate *B, Coordinate *C, Coordinate *D);

private:
    int x = 0;              /// Súradnica x.
    int y = 0;              /// Súradnica y.

signals:

};

#endif // COORDINATE_H
