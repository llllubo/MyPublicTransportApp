//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#include "buslinegui.h"


/**
 * @brief BusLineGUI::BusLineGUI Konštruktor grafického objektu linky inicializuje tento objekt.
 * @param c Súradnice grafického objektu na grafickej scéne.
 * @param color Farba grafických objektov predstavujúcich spoje linky.
 * @param scene Referencia na grafickú scénu, v ktorej sa vykreslí tento objekt - mapa.
 */
BusLineGUI::BusLineGUI(Coordinate *c, QColor color, MyMap *scene)
{
    this->setRect(c->getX()-10, c->getY()-10, 20, 20);
    scene->addItem(this);

    QPen blackpen(Qt::black);
    blackpen.setWidth(3);


    this->setPen(blackpen);
    this->setBrush(color);
    this->line_color = color;

    this->setOpacity(0);


}

/**
 * @brief BusLineGUI::setLine Grafický objekt získa referenciu na príslušný logický objekt linky.
 * @param line Referencia na logický objekt linky.
 */
void BusLineGUI::setLine(BusLine *line)
{
    this->line = line;
}

/**
 * @brief BusLineGUI::changePosition .
 */
void BusLineGUI::changePosition()
{
    /* Nastavi poziciu GUI spoja na zaklade logickeho spoja. */
    this->setRect(this->line->getPosition()->getX()-10, this->line->getPosition()->getY()-10, 20, 20);

    /* Vykona krok pre nasledujucu zmenu polohy -> pohyb. */
    this->line->takeStep();
}

/**
 * @brief BusLineGUI::getLine Vráti sa referencia na logický objekt daného grafického objektu linky.
 * @return Logický objekt linky.
 */
BusLine *BusLineGUI::getLine()
{
    return this->line;
}


/**
 * @brief BusLineGUI::mousePressEvent Funkcia je zavolaná pri každom kliku na grafický objekt linky (spoj).
 * @param event Vykonaná udalosť.
 */
void BusLineGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->Pressed = true;
    //update();
    QGraphicsRectItem::mousePressEvent(event);
}



