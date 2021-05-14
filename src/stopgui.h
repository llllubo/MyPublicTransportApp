//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#ifndef STOPGUI_H
#define STOPGUI_H


#include "coordinate.h"
#include "stop.h"
#include "mymap.h"
#include <QGraphicsRectItem>

class Stop;
class MyMap;

class StopGUI : public QGraphicsRectItem
{
  //Q_OBJECT
public:
  //explicit stopGUI(Q_OBJECT *parent = nullptr);
    explicit StopGUI(Coordinate *c, MyMap *scene);
    void setStop(Stop *stop);
    Stop *getStop();

    int type() const override;
    enum { Type = UserType + 2 };

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    Stop *stop;                     /// Odkaz na logicku triedu Stop.
    MyMap* map_scene;               /// Odkaz na scénu mapy.

signals:

};

#endif // STOPGUI_H
