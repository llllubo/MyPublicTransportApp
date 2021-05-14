//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "streetgui.h"
#include <QGraphicsSceneMouseEvent>
#include <QApplication>


/**
 * @brief StreetGUI::StreetGUI Konštruktor inicializuje grafický objekt ulice.
 * @param c_begin Referencia na objekt počiatočných súradníc grafického objektu ulice.
 * @param c_end Referencia na objekt koncových súradníc grafického objektu ulice.
 * @param street_id Identifikátor ulice.
 * @param scene Referencia na objekt grafickej scény, v ktorej sa grafický objekt vykreslí.
 */
StreetGUI::StreetGUI(Coordinate *c_begin, Coordinate *c_end, QString street_id, MyMap *scene)
{
    this->setLine(c_begin->getX(),c_begin->getY(),c_end->getX(),c_end->getY());
    this->map_scene = scene;

    scene->addItem(this);
    this->setPen(QPen(Qt::black, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    streetName = scene->addText(street_id);

    if ((c_end->getX()-c_begin->getX()) == 0) // Vertikalna ulica
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(90);
    }
    else if ((c_end->getY()-c_begin->getY()) == (c_end->getX()-c_begin->getX())) // Sikma ulica do 45 stupnov
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2 - street_id.length()*2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(45);
    }
    else if ((c_begin->getY()-c_end->getY()) == (c_end->getX()-c_begin->getX())) // Sikma ulica do 45 stupnov
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2 - street_id.length()*2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(-45);
    }
    else
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/4, c_begin->getY() + (c_end->getY()-c_begin->getY())/2);
    }


}


/**
 * @brief StreetGUI::StreetGUI Konštruktor inicializuje grafický objekt ulice.
 * @param c_begin Referencia na objekt počiatočných súradníc grafického objektu ulice.
 * @param c_end Referencia na objekt koncových súradníc grafického objektu ulice.
 * @param street_id Identifikátor ulice.
 * @param scene Referencia na objekt grafickej scény, v ktorej sa grafický objekt vykreslí.
 * @param type Typ objektu.
 */
StreetGUI::StreetGUI(Coordinate *c_begin, Coordinate *c_end, QString street_id, MyMap *scene, QString type)
{

    this->setLine(c_begin->getX(),c_begin->getY(),c_end->getX(),c_end->getY());
    this->map_scene = scene;

    scene->addItem(this);

    if (type == "tunnel")
    {
        this->setPen(QPen(Qt::black, 8, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else if (type == "highway")
    {
       this->setPen(QPen(Qt::yellow, 12, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else if (type == "main")
    {
       this->setPen(QPen(Qt::black, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
    else
    {
       this->setPen(QPen(Qt::black, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }


    streetName = scene->addText(street_id);

    if ((c_end->getX()-c_begin->getX()) == 0) // Vertikalna ulica
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(90);
    }
    else if ((c_end->getY()-c_begin->getY()) == (c_end->getX()-c_begin->getX())) // Sikma ulica do 45 stupnov
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2 - street_id.length()*2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(45);
    }
    else if ((c_begin->getY()-c_end->getY()) == (c_end->getX()-c_begin->getX())) // Sikma ulica do 45 stupnov
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/2 - street_id.length()*2, c_begin->getY() + (c_end->getY()-c_begin->getY())/2 - street_id.length()*2);
        streetName->setRotation(-45);
    }
    else
    {
        streetName->setPos(c_begin->getX() + (c_end->getX()-c_begin->getX())/4, c_begin->getY() + (c_end->getY()-c_begin->getY())/2);
    }

}



/**
 * @brief StreetGUI::getStreet Vráti logický objekt ulice daného grafického objektu ulice.
 * @return Referencia na logický objekt ulice.
 */
Street *StreetGUI::getStreet()
{
    return this->street;
}


/**
 * @brief StreetGUI::setStreet Nastaví logický objekt ulice grafickému objektu danej ulice.
 * @param street Referencia na logický objekt ulice.
 */
void StreetGUI::setStreet(Street *street)
{
    this->street = street;
}


/**
 * @brief StreetGUI::type Prepisanie metody type(), zdroj: https://doc.qt.io/qt-5/qgraphicsitem.html#type
 * @return Typ grafického objektu (UserType + 1)
 */
int StreetGUI::type() const
{
    // Enable the use of qgraphicsitem_cast with this item.
    return Type;
}

/**
 * @brief StreetGUI::mousePressEvent
 * @param event
 */
void StreetGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->map_scene->getMainwindow()->listStreetInfos(this->street->getId(), this->getStreet()->getTraffic());

    this->Pressed = true;

    if (this->map_scene->getEditingMode())
    {
        this->streetName->setDefaultTextColor(Qt::blue);
    }
    else
    {
        this->streetName->setDefaultTextColor(Qt::black);
    }

    update();
    QGraphicsLineItem::mousePressEvent(event);
}
