//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "street.h"
#include <math.h>


/**
 * @brief Street::Street Konštruktor logického objektu ulice incializuje tento objekt.
 * @param id Identifikátor ulice.
 * @param start Referencia na objekt počiatočné súradnice ulice.
 * @param end Referencia na objekt koncové súradnice ulice.
 */
Street::Street(QString id, Coordinate *start, Coordinate *end)
{
    this->id = id;

    // Vytvorenie novych objektov pre suradnice ulice
    this->start = new Coordinate(start->getX(), start->getY());
    this->end = new Coordinate(end->getX(), end->getY());

}

/**
 * @brief Street::addStop Pridanie zastávky na ulicu.
 * @param stop Referencia na objekt ulica.
 */
void Street::addStop(Stop *stop)
{
    for (int i = 0; i < this->stops.size(); i++)
    {
        if (this->stops.at(i)->getId() == stop->getId())
        {
            return;
        }
    }

    this->stops.push_back(stop);
}

/**
 * @brief Street::getStart Vráti počiatočné súradnice ulice.
 * @return Referencia na objekt počiatočné súradnice ulice.
 */
Coordinate *Street::getStart()
{
    return this->start;
}

/**
 * @brief Street::getEnd Vráti počiatočné súradnice ulice.
 * @return Referencia na objekt koncové súradnice ulice.
 */
Coordinate *Street::getEnd()
{
    return this->end;
}

/**
 * @brief Street::getId Vráti identifikátor ulice.
 * @return ID ulice.
 */
QString Street::getId()
{
    return this->id;
}

/**
 * @brief Street::getTraffic Vráti stupeň prejazdu danej ulice.
 * @return Stupeň prejazdu ulice.
 */
int Street::getTraffic()
{
    return this->traffic;
}

/**
 * @brief Street::getLength Vráti dĺžku ulice.
 * @return Dĺžka ulice.
 */
int Street::getLength()
{
    return this->length;
}

/**
 * @brief Street::setTraffic Nastaví nový stupeň prejazdu ulice.
 * @param traffic Novź stupeň prejazdu ulice.
 */
void Street::setTraffic(int traffic)
{
    this->traffic = traffic;
}
