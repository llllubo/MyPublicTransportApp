//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "coordinate.h"


Coordinate::Coordinate(QObject *parent) : QObject(parent)
{

}

/**
 * @brief Coordinate::Coordinate Konštruktor objektu súradnice.
 * @param x Súradnica x.
 * @param y Súradnica y.
 */
Coordinate::Coordinate(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Coordinate::getX Vráti súradnicu x daného objektu.
 * @return Súradnica x - celé číslo.
 */
int Coordinate::getX()
{
    return this->x;
}

/**
 * @brief Coordinate::getY Vráti súradnicu y daného objektu.
 * @return Súradnica y - celé číslo.
 */
int Coordinate::getY()
{
    return this->y;
}

/**
 * @brief Coordinate::setX Nastaví súradnicu x daného objektu.
 * @param x Nová súradnica x.
 */
void Coordinate::setX(int x)
{
    this->x = x;
}

/**
 * @brief Coordinate::setY Nastaví súradnicu y daného objektu.
 * @param y Nová súradnica y.
 */
void Coordinate::setY(int y)
{
    this->y = y;
}

/**
 * @brief Coordinate::setXY Nastaví súradnice x, y daného objektu.
 * @param x Nová súradnica x.
 * @param y Nová súradnica y.
 */
void Coordinate::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

/**
 * @brief Coordinate::distance Statická metóda, vypočíta vzdialenosť medzi dvoma súradnicami.
 * @param first
 * @param second
 * @return
 */
int Coordinate::distance(Coordinate *first, Coordinate *second)
{
    // Calculating distance
    return round(sqrt(pow(second->getX() - first->getX(), 2) +
                pow(second->getY() - first->getY(), 2) * 1.0));

}

/**
 * @brief Coordinate::cross_point Statická metóda, nájde spoločný bod dvoch úsečiek |AB| a |CD|. V prípade zhodných úsečiek vracia nullptr. Ak nemajú spoločný bod, vyhodí výnimku.
 * @param A
 * @param B
 * @param C
 * @param D
 * @return
 */
Coordinate *Coordinate::cross_point(Coordinate *A, Coordinate *B, Coordinate *C, Coordinate *D)
{

       if (A->getX() == C->getX() && A->getY() == C->getY() && B->getX() == D->getX() && B->getY() == D->getY())
       {
           return nullptr;
       }

       int a1 = B->getY() - A->getY();
       int b1 = A->getX() - B->getX();
       int c1 = a1*(A->getX()) + b1*(A->getY());

       // Usecka CD reprezentovana ako a2x + b2y = c2
       int a2 = D->getY() - C->getY();
       int b2 = C->getX() - D->getX();
       int c2 = a2*(C->getX())+ b2*(C->getY());

       int determinant = a1*b2 - a2*b1;

       // úsečky sú rovnobežné
       if (determinant == 0)
       {

           if (A->getX() == D->getX() && A->getY() == D->getY())
           {
               return new Coordinate(A->getX(), A->getY());
           }
           else if (B->getX() == C->getX() && B->getY() == C->getY())
           {
               return new Coordinate(B->getX(), B->getY());
           }
           else
           {
               throw "Ulice na seba nenadväzujú!";
           }
       }
       else
       {
           int x = round((b2*c1 - b1*c2)/determinant);
           int y = round((a1*c2 - a2*c1)/determinant);
           return new Coordinate(x, y);
       }
}


