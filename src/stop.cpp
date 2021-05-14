//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "stop.h"


/**
 * @brief Stop::Stop Konštruktor logického objektu zastávka inicializuje tento objekt.
 * @param id Identifikátor zastávky.
 * @param position Pozícia zastávky.
 * @param street Referencia na objekt ulica, na ktorej leží zastávka.
 */
Stop::Stop(QString id, Coordinate *position, Street *street)
{

    this->id = id;
    this->position = new Coordinate(position->getX(), position->getY());
    this->street = street;

}


/**
 * @brief Stop::addLine K zastávke sa pridá linka ktorá ňou prechádza.
 * @param line Pridaná linka k zastávke.
 */
void Stop::addLine(BusLine *line)
{
    // Cyklus prechadza celym zoznamom zastavky,
    // ak pridavana linka je rovnaka ako ta, ktora je uz v zozname,
    // metoda sa ukonci a nespravi nic.
    for (int i = 0; i < this->lines.size(); i++)
    {
        if (this->lines.at(i)->getId() == line->getId())
        {
            return;
        }
    }

    this->lines.push_back(line);
}



/**
 * @brief Stop::getT Vráti identifikátor ulice.
 * @return ID zastávky.
 */
QString Stop::getId()
{
    return this->id;
}


/**
 * @brief Stop::getPosition Vráti pozíciu zastávky.
 * @return Referencia na objekt súradnice zastávky.
 */
Coordinate *Stop::getPosition()
{
    return this->position;
}


/**
 * @brief Stop::getStreet Vráti ulicu, na ktorej sa zastávka nachádza.
 * @return Referencia na objekt ulice.
 */
Street *Stop::getStreet()
{
    return this->street;
}
