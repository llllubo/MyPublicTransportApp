//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#ifndef STREETGUI_H
#define STREETGUI_H

#include "coordinate.h"
#include "mymap.h"
#include "street.h"
#include <QGraphicsLineItem>

class Street;
class MyMap;

class StreetGUI : public QGraphicsLineItem

{

public:
    explicit StreetGUI(Coordinate *begin, Coordinate *end, QString street_id, MyMap *scene);
    explicit StreetGUI(Coordinate *begin, Coordinate *end, QString street_id, MyMap *scene, QString type);
    Street *getStreet();
    void setStreet(Street *street);

    int type() const override;



    bool Pressed = false;                   /// Indikátor kliknutia na ulicu.
    enum { Type = UserType + 1 };

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
    QGraphicsTextItem *streetName;          /// Premenna pre nazov ulice.
    Street *street;                         /// Odkaz na logicku triedu Street.
    MyMap *map_scene;                       /// Odkaz na scénu mapy.

signals:

};

#endif // STREETGUI_H
