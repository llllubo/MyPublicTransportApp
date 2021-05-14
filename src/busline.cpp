//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "busline.h"
#include "coordinate.h"

using namespace std;


/**
 * @brief BusLine::BusLine Konštruktor objektu Autobusová linka predá referenciu linke na hlavné okno.
 * @param mainwindow Referencia na objekt hlavné okno.
 */
BusLine::BusLine(MainWindow *mainwindow)
{
    this->mainwindow = mainwindow;
}


/**
 * @brief BusLine::getId Získanie identifikátora linky.
 * @return Identifikátor linky.
 */
QString BusLine::getId()
{
    return this->id;
}

/**
 * @brief BusLine::setId Nastavenie identifikátora linky.
 * @param id Identifikátor linky.
 */
void BusLine::setId(QString id)
{
    this->id = id;
}


/**
 * @brief BusLine::getPosition Získanie pozície spoja.
 * @return Vracia sa súradnica spoja.
 */
Coordinate *BusLine::getPosition()
{
    return this->position;
}


/**
 * @brief BusLine::setPosition Nastavenie pozície spoja.
 * @param c Nové súradnice spoja.
 */
void BusLine::setPosition(Coordinate *c)
{
    this->position = c;
}


/**
 * @brief BusLine::getStops Získanie všetkých zastávok danej linky.
 * @return Vektor referencii na zastávky danej linky.
 */
QVector<Stop *> BusLine::getStops()
{
    return this->stops;
}

/**
 * @brief BusLine::getStreets Získanie trasy danej linky.
 * @return Vektor referencii na ulice, ktorými prechádzajú spoje danej linky.
 */
QVector<Street *> BusLine::getStreets()
{
    return this->streets;
}

/**
 * @brief BusLine::getBreakPoints Získanie súradníc cesty danej linky.
 * @return Vektor súradníc, ktoré predstavujú zlomové body.
 */
QVector<Coordinate *> BusLine::getBreakPoints()
{
    return this->break_points;
}


/**
 * @brief BusLine::addStop Pridanie zastávky na koniec postupnosti zastávok danej linky.
 * @param s Referencia na pridavanú zastávku.
 */
void BusLine::addStop(Stop *s)
{
    this->stops.append(s);
}


/**
 * @brief BusLine::getNumofLinks Získanie počtu spojov danej linky.
 * @return Počet spojov danej linky.
 */
int BusLine::getNumofLinks()
{
    return this->numofLinks;
}


/**
 * @brief BusLine::setNumofLinks Nastavenie počtu spojov danej linky.
 * @param num Nový počet spojov danej linky.
 */
void BusLine::setNumofLinks(int num)
{
    this->numofLinks = num;
}


/**
 * @brief BusLine::getDepFreq Získanie frekvencie jazdy spojov danej linky.
 * @return Frekvencia jazdy spojov v simulovaných sekundách.
 */
int BusLine::getDepFreq()
{
    return this->depFreq;
}


/**
 * @brief BusLine::setDepFreq Nastavenie novej frekvencie jazdy spojov danej linky.
 * @param freq Nová frekvencia jazdy spojov v simulovaných sekundách.
 */
void BusLine::setDepFreq(int freq)
{
    this->depFreq = freq;
}


/**
 * @brief BusLine::getStreets Naplnenie vektora ulíc pre linku zo zastávok linky.
 */
void BusLine::setStreets()
{

    for (int i = 0; i < this->stops.size(); i++)
    {
        if (i != 0)
        {
            if (this->stops.at(i)->getStreet() != this->stops.at(i-1)->getStreet())
            {
                this->streets.append(this->stops.at(i)->getStreet());
            }
        }
        else
        {
            this->streets.append(this->stops.at(i)->getStreet());
        }
    }

}

/**
 * @brief BusLine::getStreets Metóda naplní vektor zlomových bodov pre linku z priesečníkov ulíc linky.
 */
bool BusLine::setBreakPoints()
{
    if (streets.empty() || stops.empty())
    {
        return false;
    }

    QVector<Coordinate *> break_points_temp;

    Coordinate *stop_coordinate_start = new Coordinate(this->stops.at(0)->getPosition()->getX(), this->stops.at(0)->getPosition()->getY());
    break_points_temp.append(stop_coordinate_start);

    for (int i = 0; i < streets.size()-1; i++)
    {
        Coordinate *c = nullptr;
        try
        {
            c = Coordinate::cross_point(this->streets.at(i)->getStart(), this->streets.at(i)->getEnd(),
                                        this->streets.at(i+1)->getStart(), this->streets.at(i+1)->getEnd());
        }
        catch(...)
        {
            return false;
        }

        // Ak sa nejedna o nullptr(znamena ze usecky su rovnake),  prida novy zlomovy bod
        if (c)
            break_points_temp.append(c);

    }

    Coordinate *stop_coordinate_end = new Coordinate(this->stops.at(this->stops.size()-1)->getPosition()->getX(), this->stops.at(this->stops.size()-1)->getPosition()->getY());
    break_points_temp.append(stop_coordinate_end);

    this->break_points.clear();
    this->break_points.append(break_points_temp);
    return true;
}

/**
 * @brief BusLine::setBusGUI Nastaví grafický objekt linky.
 * @param buslineGUI Referencia na grafický objekt linky.
 */
void BusLine::setBusGUI(BusLineGUI *buslineGUI)
{
    this->busGUI = buslineGUI;
}

void BusLine::setTimeStop(QList<QString> timeList)
{
    for (int i = 0; i < timeList.size(); i++)
    {
       int minuty = timeList.at(i).mid(0,2).toInt();
       int sekundy = timeList.at(i).mid(3,5).toInt();

       sekundy = (minuty * 60 + sekundy) * 10 + this->depFreq;
       this->timesStops.append(sekundy);
    }

}

/**
 * @brief BusLine::getTimeStops
 * @return Vektor časov k zastávkam linky
 */
QVector<int> BusLine::getTimeStops()
{
    return this->timesStops;
}

/**
 * @brief BusLine::setStreetsDeroute Upraví linku, nastaví nové ulice z obchádzky a vymaže zastávky, ktoré uživateľ zadal.
 * @param DerouteStreets
 * @param DerouteDeletedStops
 * @param closed_street_id
 */
void BusLine::setStreetsDeroute(QVector<Street *> DerouteStreets, QVector<Stop *> DerouteDeletedStops, QString closed_street_id)
{

    int closed_street_index = -1;
    for (int i = 0; i < this->streets.size(); i++)
    {
        if ( this->streets.at(i)->getId() == closed_street_id)
        {
            closed_street_index = i;
            break;
        }
    }

    // Ulica sa nenachadza v trase linky
    if (closed_street_index == -1)
    {
        return;
    }


    // Zmazanie zastavok z uzatvorenej ulice
    int number_of_deleted_stops = 0;
    for (int i = 0; i < DerouteDeletedStops.size(); i++)
    {

        for (int j = 0; j < this->stops.size(); j++)
        {
            if (DerouteDeletedStops.at(i)->getId() == this->stops.at(j)->getId())
            {
                this->stops.erase(this->stops.begin() + j);
                this->timesStops.erase(this->timesStops.begin() + j);
                number_of_deleted_stops++;
            }
        }

    }


    // Zmena vektora ulic danej linky
    QVector <Street *> split_left;
    QVector <Street *> split_right;

    for (int i = 0; i < this->streets.size(); i++)
    {
        if (i == closed_street_index)
            continue;
        if (i < closed_street_index)
                    split_left.push_back(this->streets.at(i));
        else
                    split_right.push_back(this->streets.at(i));
    }
    this->streets.clear();
    this->streets.append(split_left);
    this->streets.append(DerouteStreets);
    this->streets.append(split_right);

    // Unikatnost ulic v zozname
    for (int i = 0; i < this->streets.size(); i++)
    {
        if (i != 0)
        {
            if (this->streets.at(i)->getId() == this->streets.at(i-1)->getId())
            {
                this->streets.erase(this->streets.begin() + i);
            }
        }
    }

    setBreakPoints();

    this->position->setX(this->stops.at(0)->getPosition()->getX());
    this->position->setY(this->stops.at(0)->getPosition()->getY());
    this->street_index = -1;
    this->stop_index = 0;
    this->break_points_index = 0;


}

/**
 * @brief BusLine::getStopIndex
 * @return
 */
int BusLine::getStopIndex()
{
    return this->stop_index;
}

/**
 * @brief BusLine::getStreetIndex
 * @return
 */
int BusLine::getStreetIndex()
{
    return this->street_index;
}

/**
 * @brief BusLine::getDelay
 * @return
 */
int BusLine::getDelay()
{
    return this->delay;
}




/**
 * @brief BusLine::takeStep Vykoná krok pre následujúcu zmenu polohy - pohybu spoja.
 */
void BusLine::takeStep()
{


    // Linky, ktore este nemaju vyrazit budu cakat, na zaklade frekvencie
    if (this->mainwindow->getSec() <= this->depFreq)
    {
        return;
    }
    else
    {
        this->busGUI->setOpacity(1);
    }


    if (this->position->getX() == this->break_points.at(this->break_points_index)->getX() &&
        this->position->getY() == this->break_points.at(this->break_points_index)->getY())
    {
          this->break_points_index++;
          this->street_index++;

            // Ak narazil na posledny zlomovy bod
          if (break_points_index == this->break_points.size())
          {
              this->break_points_index = 0;
              this->street_index = -1;

              this->new_times_stops.clear();

              if (this->stops.at(0)->getId() != this->stops.at(this->stops.size()-1)->getId())
              {
                  reverse(this->streets.begin(),this->streets.end());
                  reverse(this->stops.begin(),this->stops.end());
                  reverse(this->break_points.begin(),this->break_points.end());

                  for (int j = this->timesStops.size()-1; j >= 0; j--)
                  {
                      this->new_times_stops.append(2*this->timesStops.at(timesStops.size()-1) - this->timesStops.at(j));
                  }
                  this->timesStops.clear();
                  this->timesStops.append(this->new_times_stops);
              }
              else
              {
                  this->new_times_stops.append(this->timesStops.at(this->timesStops.size()-1));
                  int add_time = this->timesStops.at(this->timesStops.size()-1) - this->timesStops.at(0);

                  for (int j = 1; j < this->timesStops.size(); j++)
                  {
                      this->new_times_stops.append(this->timesStops.at(j) +  add_time);
                  }
                  this->timesStops.clear();
                  this->timesStops.append(this->new_times_stops);
              }
          }

    }


     // Zmeranie rychlosti spoja na zaklade ulice, kde sa nachadza
     if ((this->street_index > -1) && (this->street_index < this->streets.size()))
        this->step_size = 10 - this->streets.at(this->street_index)->getTraffic();

    // Ak je spoj blizko zastavky

    if (Coordinate::distance(this->position, this->stops.at(this->stop_index)->getPosition()) <= step_size)
    {

        if (Coordinate::distance(this->position, this->stops.at(this->stop_index)->getPosition()) <= this->eps)
        {

            // Ak zastal na zastavke, pocka 5 tikov a potom sa pohne
            if (this->stop_wait < 5)
            {
                this->stop_wait++;
                return;
            }
            else
            {
                this->stop_wait = 0;

                // Ak Spoj prisiel na zastavku skor pocka do svojho odchodoveho casu
                if (this->mainwindow->getSec() < this->timesStops.at(stop_index))
                    return;

                // Urci nove meskanie spoja
                if (this->mainwindow->getSec() >= this->timesStops.at(stop_index))
                    this->delay = this->mainwindow->getSec() - this->timesStops.at(stop_index);



                int hours = this->mainwindow->getSec() / 600;
                int minutes = this->mainwindow->getSec() /10 % 60;
                QString hourStr = QString("%1").arg(hours, 2, 10, QChar('0'));
                QString minStr = QString("%1").arg(minutes, 2, 10, QChar('0'));

                QString str = hourStr + "." + minStr;

                this->stop_index++;

                if (stop_index == stops.size()-1)
                {

                    this->stop_index = 0;
                }


            }
        }

        else
        {
            this->step_size = this->step_size/2; // Ak spoj je blizsie k zastavke ale nie dostatocne blizko, spomali
        }

    }


    if (Coordinate::distance(this->position, this->break_points.at(this->break_points_index)) <= this->step_size)
    {
        this->position->setXY(this->break_points.at(this->break_points_index)->getX(), this->break_points.at(this->break_points_index)->getY());
    }

    // Pohyb
    if (this->position->getX() < this->break_points.at(this->break_points_index)->getX())
    {
            this->position->setX(this->position->getX() + this->step_size);
    }

    else if (this->position->getX() > this->break_points.at(this->break_points_index)->getX())
    {

            this->position->setX(this->position->getX() - this->step_size);
    }



    if (this->position->getY() < this->break_points.at(this->break_points_index)->getY())
    {

            this->position->setY(this->position->getY() + this->step_size);
    }

    else if (this->position->getY() > this->break_points.at(this->break_points_index)->getY())
    {

            this->position->setY(this->position->getY() - this->step_size);
    }


}
