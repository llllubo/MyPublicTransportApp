//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#ifndef BUSLINEGUI_H
#define BUSLINEGUI_H

#include "busline.h"
#include "coordinate.h"
#include "mymap.h"
#include <QGraphicsRectItem>
#include <QPainter>

class BusLine;
class MyMap;

class BusLineGUI : public QGraphicsRectItem
{
    //Q_OBJECT
public:
    //explicit BusLineGUI(QObject *parent = nullptr);
    explicit BusLineGUI(Coordinate *c, QColor color, MyMap *scene);
    void setLine(BusLine *line);
    void changePosition();
    BusLine *getLine();

    bool Pressed = false;                /// Indikácia kliku na spoj.
    QColor line_color;                   /// Farba linky
    QVector<QGraphicsLineItem*> markers; /// Vektor farebný čiar linky, ktoré sa zvýraznia pri zakliknutí na spoj

    MyMap *map_scene;                    /// Odkaz na scénu mapy


protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);


private:
    BusLine *line;                       /// Odkaz na logickú triedu BusLine.



signals:

};

#endif // BUSLINEGUI_H
