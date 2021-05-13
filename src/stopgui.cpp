//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#include "stopgui.h"


/**
 * @brief StopGUI::StopGUI Konštruktor grafického objektu zastávky inicializuje tento objekt.
 * @param c Súradnice zastávky v grafickej scéne.
 * @param scene Referencia na grafickú scénu.
 */
StopGUI::StopGUI(Coordinate *c, MyMap *scene)
{
   this->setRect(c->getX(), c->getY(), 53, 53);
   scene->addItem(this);
   this->setBrush(QColor::fromRgbF(0, 1, 0, 1));
   this->setOpacity(0.03);
   this->map_scene = scene;
}


/**
 * @brief StopGUI::setStop Nastaví logický objekt zastávky ku grafickému objektu ten istej zastávky.
 * @param stop Referncia na logický objekt zastávky.
 */
void StopGUI::setStop(Stop *stop)
{
    this->stop = stop;
}


/**
 * @brief StopGUI::getStop
 * @return Vektor zastávok
 */
Stop *StopGUI::getStop()
{
    return this->stop;
}


/**
 * @brief StopGUI::type override, zdroj: https://doc.qt.io/qt-5/qgraphicsitem.html#type
 * @return Typ grafického objektu (UserType + 2)
 */
int StopGUI::type() const
{
    return Type;
}


/**
 * @brief StopGUI::mousePressEvent Funkcia sa volá pri každom kliklnutí na grafický objekt zastávky.
 * @param event Referencia na udalosť.
 */
void StopGUI::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->map_scene->getMainwindow()->listStopInfos(this->stop->getId(), this->stop->getStreet()->getId());

    QGraphicsRectItem::mousePressEvent(event);
}
