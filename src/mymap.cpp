//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "mymap.h"
#include "streetgui.h"
#include "stopgui.h"
#include "coordinate.h"
#include "busline.h"
#include "buslinegui.h"
#include "street.h"
#include "stop.h"
#include "parsefile.h"
#include "mainwindow.h"
#include <QGraphicsSceneMouseEvent>
#include <QMessageBox>

using namespace std;

/**
 * @brief MyMap::MyMap .
 * @param parent Refrencia na rodičovský objekt mapy.
 */
MyMap::MyMap(QObject *parent) : QGraphicsScene(parent)
{
    QPixmap pixmap("../examples/mapa.png");
    this->addPixmap(pixmap);

    this->MapObjectsInit();

}

/**
 * @brief MyMap::MyMap .
 * @param mainwindow Referencia na hlavné okno.
 */
MyMap::MyMap(MainWindow* mainwindow)
{
    QPixmap pixmap("../examples/mapa.png");
    this->addPixmap(pixmap);
    this->mainwindow = mainwindow;

    this->MapObjectsInit();
}

/**
 * @brief MyMap::MapObjectsInit Inicializácia všetkých grafických objektov mapy.
 */
void MyMap::MapObjectsInit()
{

    // Street Initialization
    Coordinate *beginning = new Coordinate(133,432);
    Coordinate *end = new Coordinate(414,713);


    StreetGUI *train_street_GUI = new StreetGUI(beginning, end, "Train St.", this);
    Street *train_street = new Street("Train Street", beginning, end);
    train_street_GUI->setStreet(train_street);

    beginning->setXY(415,713);
    end->setXY(1940,713);
    StreetGUI *main_street_GUI = new StreetGUI(beginning, end, "Main St.", this, "main");
    Street *main_street = new Street("Main Street", beginning, end);
    main_street_GUI->setStreet(main_street);


    beginning->setXY(415,133);
    end->setXY(415,713);
    StreetGUI *stadium_street_GUI = new StreetGUI(beginning, end, "Stadium St.", this);
    Street *stadium_street = new Street("Stadium Street", beginning, end);
    stadium_street_GUI->setStreet(stadium_street);

    beginning->setXY(415,133);
    end->setXY(811,133);
    StreetGUI *university_street_GUI = new StreetGUI(beginning, end, "University St.", this);
    Street *university_street = new Street("University Street", beginning, end);
    university_street_GUI->setStreet(university_street);

    beginning->setXY(811,133);
    end->setXY(811,713);
    StreetGUI *hospital_street_GUI = new StreetGUI(beginning, end, "Hospital St.", this);
    Street *hospital_street = new Street("Hospital Street", beginning, end);
    hospital_street_GUI->setStreet(hospital_street);

    beginning->setXY(160,968);
    end->setXY(415,713);
    StreetGUI *industry_street_GUI = new StreetGUI(beginning, end, "Industry St.", this);
    Street *industry_street = new Street("Industry Street", beginning, end);
    industry_street_GUI->setStreet(industry_street);

    beginning->setXY(160,968);
    end->setXY(549,1357);
    StreetGUI *selfcare_street_GUI = new StreetGUI(beginning, end, "Self Care St.", this);
    Street *selfcare_street = new Street("Self Care Street", beginning, end);
    selfcare_street_GUI->setStreet(selfcare_street);

    beginning->setXY(549,1357);
    end->setXY(1112,794);
    StreetGUI *long_street_GUI = new StreetGUI(beginning, end, "Long St.", this);
    Street *long_street = new Street("Long Street", beginning, end);
    long_street_GUI->setStreet(long_street);

    beginning->setXY(890,713);
    end->setXY(890,1016);
    StreetGUI *short_street_GUI = new StreetGUI(beginning, end, "Short St.", this);
    Street *short_street = new Street("Short Street", beginning, end);
    short_street_GUI->setStreet(short_street);

    beginning->setXY(549,1357);
    end->setXY(1090,1357);
    StreetGUI *farewell_street_GUI = new StreetGUI(beginning, end, "Farewell St.", this);
    Street *farewell_street = new Street("Farewell Street", beginning, end);
    farewell_street_GUI->setStreet(farewell_street);

    beginning->setXY(557,877);
    end->setXY(793,1113);
    StreetGUI *downtown_street_GUI = new StreetGUI(beginning, end, "Downtown St.", this);
    Street *downtown_street = new Street("Downtown Street", beginning, end);
    downtown_street_GUI->setStreet(downtown_street);

    beginning->setXY(313,1121);
    end->setXY(557,877);
    StreetGUI *racing_street_GUI = new StreetGUI(beginning, end, "Racing St.", this);
    Street *racing_street = new Street("Racing Street", beginning, end);
    racing_street_GUI->setStreet(racing_street);

    beginning->setXY(557,713);
    end->setXY(557,877);
    StreetGUI *pet_street_GUI = new StreetGUI(beginning, end, "Pet St.", this);
    Street *pet_street = new Street("Pet Street", beginning, end);
    pet_street_GUI->setStreet(pet_street);

    beginning->setXY(964,713);
    end->setXY(1410,267);
    StreetGUI *water_street_GUI = new StreetGUI(beginning, end, "Water St.", this);
    Street *water_street = new Street("Water Street", beginning, end);
    water_street_GUI->setStreet(water_street);

    beginning->setXY(1246,103);
    end->setXY(1410,267);
    StreetGUI *residential_street_GUI = new StreetGUI(beginning, end, "Residential St.", this);
    Street *residential_street = new Street("Residential Street", beginning, end);
    residential_street_GUI->setStreet(residential_street);

    beginning->setXY(1034,713);
    end->setXY(1420,1099);
    StreetGUI *garden_street_GUI = new StreetGUI(beginning, end, "Garden St.", this);
    Street *garden_street = new Street("Garden Street", beginning, end);
    garden_street_GUI->setStreet(garden_street);

    beginning->setXY(1420,1099);
    end->setXY(1625,1099);
    StreetGUI *tunnel_street_GUI = new StreetGUI(beginning, end, "Tunnel", this, "tunnel");
    Street *tunnel_street = new Street("Tunnel", beginning, end);
    tunnel_street_GUI->setStreet(tunnel_street);

    beginning->setXY(1625,713);
    end->setXY(1625,1099);
    StreetGUI *animal_street_GUI = new StreetGUI(beginning, end, "Animal St.", this);
    Street *animal_street = new Street("Animal Street", beginning, end);
    animal_street_GUI->setStreet(animal_street);

    beginning->setXY(1940,153);
    end->setXY(1940,713);
    StreetGUI *millionaires_street_GUI = new StreetGUI(beginning, end, "Millionaires St.", this);
    Street *millionaires_street = new Street("Millionaires Street", beginning, end);
    millionaires_street_GUI->setStreet(millionaires_street);

    beginning->setXY(1625,153);
    end->setXY(1940,153);
    StreetGUI *forest_street_GUI = new StreetGUI(beginning, end, "Forest st.", this);
    Street *forest_street = new Street("Forest Street", beginning, end);
    forest_street_GUI->setStreet(forest_street);

    beginning->setXY(1625,153);
    end->setXY(1625,713);
    StreetGUI *basic_street_GUI = new StreetGUI(beginning, end, "Basic st.", this);
    Street *basic_street = new Street("Basic Street", beginning, end);
    basic_street_GUI->setStreet(basic_street);

    beginning->setXY(1940,713);
    end->setXY(1940,835);
    StreetGUI *shopping_street_GUI = new StreetGUI(beginning, end, "Shopping st.", this);
    Street *shopping_street = new Street("Shopping Street", beginning, end);
    shopping_street_GUI->setStreet(shopping_street);

    beginning->setXY(1517,1);
    end->setXY(1517,1500);
    StreetGUI *highway_street_GUI = new StreetGUI(beginning, end, "Highway", this, "highway");
    Street *highway_street = new Street("Highway", beginning, end);
    highway_street_GUI->setStreet(highway_street);

    // Vektor všetkých ulíc mapy
    this->vecStreetsGUI = {train_street_GUI, main_street_GUI, stadium_street_GUI, university_street_GUI, hospital_street_GUI, industry_street_GUI, pet_street_GUI,
                           selfcare_street_GUI, racing_street_GUI, downtown_street_GUI, long_street_GUI, short_street_GUI, tunnel_street_GUI, animal_street_GUI,
                           water_street_GUI, residential_street_GUI, millionaires_street_GUI, forest_street_GUI, basic_street_GUI, shopping_street_GUI, garden_street_GUI,
                           farewell_street_GUI};

    // Stop initialization
    beginning->setXY(141,373);
    StopGUI *train_station_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(133,432);
    Stop *train_station_stop = new Stop("Train Station", beginning, train_street);
    train_station_stop_GUI->setStop(train_station_stop);


    beginning->setXY(353,482);
    StopGUI *westhouse_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(415,512);
    Stop *westhouse_stop = new Stop("West House", beginning, stadium_street);
    westhouse_stop_GUI->setStop(westhouse_stop);

    beginning->setXY(353,313);
    StopGUI *stadium_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(415,337);
    Stop *stadium_stop = new Stop("Stadium", beginning, stadium_street);
    stadium_stop_GUI->setStop(stadium_stop);

    beginning->setXY(451,139);
    StopGUI *university_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(476,133);
    Stop *university_stop = new Stop("University", beginning, university_street);
    university_stop_GUI->setStop(university_stop);

    beginning->setXY(721,73);
    StopGUI *northchurch_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(745,133);
    Stop *northchurch_stop = new Stop("North Church", beginning, university_street);
    northchurch_stop_GUI->setStop(northchurch_stop);

    beginning->setXY(819,278);
    StopGUI *northpark_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(811,302);
    Stop *northpark_stop = new Stop("North Park", beginning, hospital_street);
    northpark_stop_GUI->setStop(northpark_stop);

    beginning->setXY(820,489);
    StopGUI *hospital_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(811,512);
    Stop *hospital_stop = new Stop("Hospital", beginning, hospital_street);
    hospital_stop_GUI->setStop(hospital_stop);

    beginning->setXY(564,753);
    StopGUI *veterinary_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(557,780);
    Stop *veterinary_stop = new Stop("Veterinary", beginning, pet_street);
    veterinary_stop_GUI->setStop(veterinary_stop);

    beginning->setXY(666,922);
    StopGUI *nearbyhotel_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(663,983);
    Stop *nearbyhotel_stop = new Stop("Nearby Hotel", beginning, downtown_street);
    nearbyhotel_stop_GUI->setStop(nearbyhotel_stop);

    beginning->setXY(900,722);
    StopGUI *post_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(921,713);
    Stop *post_stop = new Stop("Post", beginning, main_street);
    post_stop_GUI->setStop(post_stop);

    beginning->setXY(1020,897);
    StopGUI *theatre_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1013,892);
    Stop *theatre_stop = new Stop("Theatre", beginning, long_street);
    theatre_stop_GUI->setStop(theatre_stop);

    beginning->setXY(878,1037);
    StopGUI *museum_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(874,1032);
    Stop *museum_stop = new Stop("Museum", beginning, long_street);
    museum_stop_GUI->setStop(museum_stop);

    beginning->setXY(749,1167);
    StopGUI *field_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(743,1163);
    Stop *field_stop = new Stop("Field", beginning, long_street);
    field_stop_GUI->setStop(field_stop);

    beginning->setXY(559,1364);
    StopGUI *food_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(582,1357);
    Stop *food_stop = new Stop("Food", beginning, farewell_street);
    food_stop_GUI->setStop(food_stop);

    beginning->setXY(800, 1364);
    StopGUI *southhouses_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(823,1357);
    Stop *southhouses_stop = new Stop("South Houses", beginning, farewell_street);
    southhouses_stop_GUI->setStop(southhouses_stop);

    beginning->setXY(1034, 1364);
    StopGUI *cemetery_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1058,1357);
    Stop *cemetery_stop = new Stop("Cemetery", beginning, farewell_street);
    cemetery_stop_GUI->setStop(cemetery_stop);

    beginning->setXY(291,846);
    StopGUI *factories_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(287,841);
    Stop *factories_stop = new Stop("Factories", beginning, industry_street);
    factories_stop_GUI->setStop(factories_stop);

    beginning->setXY(126,996);
    StopGUI *spa_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(181,989);
    Stop *spa_stop = new Stop("Spa", beginning, selfcare_street);
    spa_stop_GUI->setStop(spa_stop);

    beginning->setXY(366,952);
    StopGUI *garage_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(424,1010);
    Stop *garage_stop = new Stop("Garage", beginning, racing_street);
    garage_stop_GUI->setStop(garage_stop);

    beginning->setXY(361,1231);
    StopGUI *fitness_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(418,1226);
    Stop *fitness_stop = new Stop("Fitness", beginning, selfcare_street);
    fitness_stop_GUI->setStop(fitness_stop);

    beginning->setXY(430,652);
    StopGUI *cross_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(453,713);
    Stop *cross_stop = new Stop("Cross", beginning, main_street);
    cross_stop_GUI->setStop(cross_stop);

    beginning->setXY(1031,652);
    StopGUI *police_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1022,713);
    Stop *police_stop = new Stop("Police", beginning, main_street);
    police_stop_GUI->setStop(police_stop);

    beginning->setXY(1309,723);
    StopGUI *firehouse_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1332,713);
    Stop *firehouse_stop = new Stop("Firehouse", beginning, main_street);
    firehouse_stop_GUI->setStop(firehouse_stop);

    beginning->setXY(828,651);
    StopGUI *bank_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(851,713);
    Stop *bank_stop = new Stop("Bank", beginning, main_street);
    bank_stop_GUI->setStop(bank_stop);

    beginning->setXY(1187,376);
    StopGUI *pool_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1243,434);
    Stop *pool_stop = new Stop("Pool", beginning, water_street);
    pool_stop_GUI->setStop(pool_stop);

    beginning->setXY(1253,49);
    StopGUI *northhouses_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1246,103);
    Stop *northhouses_stop = new Stop("North Houses", beginning, residential_street);
    northhouses_stop_GUI->setStop(northhouses_stop);

    beginning->setXY(1657,652);
    StopGUI *busstation_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1680,713);
    Stop *busstation_stop = new Stop("Bus Station", beginning, main_street);
    busstation_stop_GUI->setStop(busstation_stop);

    beginning->setXY(1946,778);
    StopGUI *store_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1940,835);
    Stop *store_stop = new Stop("Store", beginning, shopping_street);
    store_stop_GUI->setStop(store_stop);

    beginning->setXY(1881,566);
    StopGUI *golfcourt_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1940,590);
    Stop *golfcourt_stop = new Stop("Golf Court", beginning, millionaires_street);
    golfcourt_stop_GUI->setStop(golfcourt_stop);

    beginning->setXY(1769,159);
    StopGUI *foresthill_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1793,153);
    Stop *foresthill_stop = new Stop("Forest Hill", beginning, forest_street);
    foresthill_stop_GUI->setStop(foresthill_stop);

    beginning->setXY(1225,970);
    StopGUI *lost_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1284,963);
    Stop *lost_stop = new Stop("Lost", beginning, garden_street);
    lost_stop_GUI->setStop(lost_stop);

    beginning->setXY(1567,951);
    StopGUI *zoo_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1625,974);
    Stop *zoo_stop = new Stop("Zoo", beginning, animal_street);
    zoo_stop_GUI->setStop(zoo_stop);

    beginning->setXY(1537,1108);
    StopGUI *underbridge_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1558,1099);
    Stop *underbridge_stop = new Stop("Under Bridge", beginning, tunnel_street);
    underbridge_stop_GUI->setStop(underbridge_stop);

    beginning->setXY(1565,281);
    StopGUI *shop_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1625,306);
    Stop *shop_stop = new Stop("Shop", beginning, basic_street);
    shop_stop_GUI->setStop(shop_stop);

    beginning->setXY(1114,731);
    StopGUI *shortgarden_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(1103,782);
    Stop *shortgarden_stop = new Stop("Short Garden", beginning, garden_street);
    shortgarden_stop_GUI->setStop(shortgarden_stop);

    beginning->setXY(832,911);
    StopGUI *middlepark_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(890,933);
    Stop *middlepark_stop = new Stop("Middle Park", beginning,short_street);
    middlepark_stop_GUI->setStop(middlepark_stop);

    beginning->setXY(594,652);
    StopGUI *government_stop_GUI = new StopGUI(beginning, this);
    beginning->setXY(617,713);
    Stop *government_stop = new Stop("Government", beginning,main_street);
    government_stop_GUI->setStop(government_stop);



    // Bus Line initialization
    // Busline dostane ukazatel na mainwindow

    auto *parser = new ParseFile();

    // Iterovanie cez vsetky zadane linky.
    int bus_counter = 0;
    for (int i = 0; i < parser->linesInfos.size(); i++)
    {

        QColor color = QColor(rand() % 256, rand() % 256, rand() % 256, 255); //nahodna farba pre linku
        int actualFreq = 0;      // Urcuje aktualnu dobu, kedy ma spoj vyrazit, pripocitava sa s frekvenciou

        // Iterovanie cez pocet spojov jednotlivych liniek.
        for (int j = 0; j < parser->linesInfos[i].numofLinks; j++)
        {
            vecLinks.append(new BusLine(this->mainwindow));             // Vytvori sa spoj
            vecLinks[bus_counter]->setId(parser->linesInfos[i].nameLine);         // Priradi sa ID linky pre spoj.
            vecLinks[bus_counter]->setNumofLinks(parser->linesInfos[i].numofLinks);  // Ulozi sa pocet spojov linky, do ktorej patri aj tento spoj

            if (j > 0) // prvy spoj zacina od zaciatku (0), frekvenciu zadame az nasledujucim spojom (druhy, treti..)
                vecLinks[bus_counter]->setDepFreq(actualFreq += parser->linesInfos[i].depFreq);     // Ulozi sa frekvencia jazdy spojov danej linky.

            vecLinks[bus_counter]->setTimeStop(parser->linesInfos[i].timesStops.keys()); // Ulozia sa casy k zastávkam

            // Iterovanie cez vsetky zastavky daneho spoja.
            for (QMap<QString,QVariant>::iterator iter = parser->linesInfos[i].timesStops.begin(); iter != parser->linesInfos[i].timesStops.end(); iter++)
            {
                if (iter.value() == "Train Station")
                {
                    vecLinks[bus_counter]->addStop(train_station_stop);
                }
                else if (iter.value() == "West House")
                {
                    vecLinks[bus_counter]->addStop(westhouse_stop);
                }
                else if (iter.value() == "Stadium")
                {
                    vecLinks[bus_counter]->addStop(stadium_stop);
                }
                else if (iter.value() == "University")
                {
                    vecLinks[bus_counter]->addStop(university_stop);
                }
                else if (iter.value() == "North Church")
                {
                    vecLinks[bus_counter]->addStop(northchurch_stop);
                }
                else if (iter.value() == "North Park")
                {
                    vecLinks[bus_counter]->addStop(northpark_stop);
                }
                else if (iter.value() == "Hospital")
                {
                    vecLinks[bus_counter]->addStop(hospital_stop);
                }
                else if (iter.value() == "Veterinary")
                {
                    vecLinks[bus_counter]->addStop(veterinary_stop);
                }
                else if (iter.value() == "Nearby Hotel")
                {
                    vecLinks[bus_counter]->addStop(nearbyhotel_stop);
                }
                else if (iter.value() == "Post")
                {
                    vecLinks[bus_counter]->addStop(post_stop);
                }
                else if (iter.value() == "Theatre")
                {
                    vecLinks[bus_counter]->addStop(theatre_stop);
                }
                else if (iter.value() == "Museum")
                {
                    vecLinks[bus_counter]->addStop(museum_stop);
                }
                else if (iter.value() == "Field")
                {
                    vecLinks[bus_counter]->addStop(field_stop);
                }
                else if (iter.value() == "Food")
                {
                    vecLinks[bus_counter]->addStop(food_stop);
                }
                else if (iter.value() == "South Houses")
                {
                    vecLinks[bus_counter]->addStop(southhouses_stop);
                }
                else if (iter.value() == "Cemetery")
                {
                    vecLinks[bus_counter]->addStop(cemetery_stop);
                }
                else if (iter.value() == "Factories")
                {
                    vecLinks[bus_counter]->addStop(factories_stop);
                }
                else if (iter.value() == "Spa")
                {
                    vecLinks[bus_counter]->addStop(spa_stop);
                }
                else if (iter.value() == "Garage")
                {
                    vecLinks[bus_counter]->addStop(garage_stop);
                }
                else if (iter.value() == "Fitness")
                {
                    vecLinks[bus_counter]->addStop(fitness_stop);
                }
                else if (iter.value() == "Cross")
                {
                    vecLinks[bus_counter]->addStop(cross_stop);
                }
                else if (iter.value() == "Police")
                {
                    vecLinks[bus_counter]->addStop(police_stop);
                }
                else if (iter.value() == "Firehouse")
                {
                    vecLinks[bus_counter]->addStop(firehouse_stop);
                }
                else if (iter.value() == "Bank")
                {
                    vecLinks[bus_counter]->addStop(bank_stop);
                }
                else if (iter.value() == "Pool")
                {
                    vecLinks[bus_counter]->addStop(pool_stop);
                }
                else if (iter.value() == "North Houses")
                {
                    vecLinks[bus_counter]->addStop(northhouses_stop);
                }
                else if (iter.value() == "Bus Station")
                {
                    vecLinks[bus_counter]->addStop(busstation_stop);
                }
                else if (iter.value() == "Store")
                {
                    vecLinks[bus_counter]->addStop(store_stop);
                }
                else if (iter.value() == "Golf Court")
                {
                    vecLinks[bus_counter]->addStop(golfcourt_stop);
                }
                else if (iter.value() == "Forest Hill")
                {
                    vecLinks[bus_counter]->addStop(foresthill_stop);
                }
                else if (iter.value() == "Lost")
                {
                    vecLinks[bus_counter]->addStop(lost_stop);
                }
                else if (iter.value() == "Zoo")
                {
                    vecLinks[bus_counter]->addStop(zoo_stop);
                }
                else if (iter.value() == "Shop")
                {
                    vecLinks[bus_counter]->addStop(shop_stop);
                }
                else if (iter.value() == "Government")
                {
                    vecLinks[bus_counter]->addStop(government_stop);
                }
                else if (iter.value() == "Under Bridge")
                {
                    vecLinks[bus_counter]->addStop(underbridge_stop);
                }
                else if (iter.value() == "Short Garden")
                {
                    vecLinks[bus_counter]->addStop(shortgarden_stop);
                }
                else if (iter.value() == "Middle Park")
                {
                    vecLinks[bus_counter]->addStop(middlepark_stop);
                }
                else
                {
                    qFatal("CHYBA! Zastavka '%s' sa na mape nenachadza.", iter.value().toString().toUtf8().constData());
                    exit(EXIT_FAILURE);
                }
            }

            Coordinate *c = new Coordinate(vecLinks[bus_counter]->getStops().at(0)->getPosition()->getX(),
                                           vecLinks[bus_counter]->getStops().at(0)->getPosition()->getY());

            vecLinks[bus_counter]->setPosition(c);

            vecLinksGUI.append(new BusLineGUI(c, color, this));

            // Naplni sa vetor ulic pre spoje linky. Nastavia sa jeho zlomové body
            vecLinks[bus_counter]->setStreets();
            vecLinks[bus_counter]->setBreakPoints();

            vecLinksGUI.at(bus_counter)->setLine(vecLinks.at(bus_counter));
            vecLinks.at(bus_counter)->setBusGUI(vecLinksGUI.at(bus_counter));

            bus_counter++;
        }
    }

    makeMarkers();

    if (this->mainwindow != nullptr)
    {
        this->mainwindow->setLines(vecLinksGUI);
    }
}

/**
 * @brief MyMap::getLinks Vráti logické objekty liniek na mape.
 * @return Vektor referencií logických objektov liniek.
 */
QVector<BusLine *> MyMap::getLinks()
{
    return this->vecLinks;
}


/**
 * @brief MyMap::addLink Pridá logický objekt linky do mapy.
 * @param link Referencia nas logický objekt linky.
 */
void MyMap::addLink(BusLine *link)
{
    this->vecLinks.append(link);
}


/**
 * @brief MyMap::getLinksGUI Vráti grafické objekty liniek na mape.
 * @return Vektor grafických objektov liniek na mape.
 */
QVector<BusLineGUI *> MyMap::getLinksGUI()
{
    return this->vecLinksGUI;
}


/**
 * @brief MyMap::addLinkGUI Pridá grafickź objekt linky do mapy.
 * @param link Referencia na grafický objekt linky.
 */
void MyMap::addLinkGUI(BusLineGUI *link)
{
    this->vecLinksGUI.append(link);
}

/**
 * @brief MyMap::getStreetsGUI Vráti grafické objekty ulíc na mape.
 * @return Vektor referencií grafických objektov ulíc.
 */
QVector<StreetGUI *> MyMap::getStreetsGUI()
{
    return this->vecStreetsGUI;
}

/**
 * @brief MyMap::getMainwindow Vráti objekt hlavné okno.
 * @return Referencia na hlavné okno.
 */
MainWindow *MyMap::getMainwindow()
{
    return this->mainwindow;
}


/**
 * @brief MyMap::setClosedStreet
 * @param streetGUI
 */
void MyMap::setClosedStreet(StreetGUI *streetGUI)
{
    this->closedstreet = streetGUI;

}

/**
 * @brief MyMap::getClosedStreet
 * @return
 */
StreetGUI *MyMap::getClosedStreet()
{
    return this->closedstreet;
}

/**
 * @brief MyMap::setEditingMode Nastaví indikátor editovacieho módu.
 * @param mode Indikátor editovacieho módu.
 */
void MyMap::setEditingMode(bool mode)
{
    this->EditingMode = mode;
}

/**
 * @brief MyMap::getEditingMode Vráti sa indikátor, či bol zapnutý editovací mód.
 * @return Indikátor editovacieho módu.
 */
bool MyMap::getEditingMode()
{
    return this->EditingMode;
}

/**
 * @brief MyMap::addDetourItems V prípade zadávania obchádzky. Kliknutá ulica sa pridá do zoznamu zastávok pre rožšírenie linky. Kliknutá zastávka sa pridá do zoznamu zmazaných zastávok linky.
 * @param items
 */
void MyMap::addDetourItems(QList<QGraphicsItem *> items)
{
    for (auto i : items)
    {
        // Ak ulica uz v zozname objizdky existuje alebo to je uzavreta ulica, neprida sa
        if (this->detour_streets.contains( (StreetGUI *) i ) || (StreetGUI *) i == this->closedstreet )
        {
            continue;
        }
        else
        {
            // Ak typ item objektu zodpoveda typu StreetGUI prida sa do zoznamu objizdky
            if (i->type() == StreetGUI::Type)
            {


                if (!this->detour_streets.empty())
                {

                    StreetGUI * current_street = (StreetGUI *) i;

                    // Skuska ci zadane ulice na seba nadvazuju, v pripade ze nie, vyskoci warovna hlaska a ulica sa do zoznam nepridá
                    try
                    {
                        Coordinate::cross_point(this->detour_streets.at(this->detour_streets.size()-1)->getStreet()->getStart(),
                                                             this->detour_streets.at(this->detour_streets.size()-1)->getStreet()->getEnd(),
                                                             current_street->getStreet()->getStart(),
                                                             current_street->getStreet()->getEnd());
                    }
                    catch (...)
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Warning, you can only add street that follows the previous one.");
                        msgBox.exec();
                        return;
                    }

                 }

                this->detour_streets.append((StreetGUI *) i);
            }

            else if (i->type() == StopGUI::Type)
            {
                this->detour_deleted_stops.append((StopGUI*) i);
            }

       }
   }
}

/**
 * @brief MyMap::AppendNewStreetsToLine Po zadaní objazdnej trasy sa nové ulice nastavia do linky.
 */
void MyMap::AppendNewStreetsToLine()
{
    // Ziskanie logickych objektov Street z StreetGUI
    QVector<Street *> streets;
    for(StreetGUI *streetGUI : this->detour_streets)
    {
        streets.append(streetGUI->getStreet());
    }

    QVector<Stop *> stops;
    for(StopGUI *stopGUI : this->detour_deleted_stops)
    {
        stops.append(stopGUI->getStop());
    }


    for (BusLineGUI *i : this->vecLinksGUI)
    {
        i->getLine()->setStreetsDeroute(streets, stops, this->closedstreet->getStreet()->getId());
    }
}

/**
 * @brief MyMap::makeMarkers Funkcia vytvorí farebnú trasu pre spoj, ktorá sa zobrazí na mape po kliknutí na spoj.
 */
void MyMap::makeMarkers()
{
    // Vytvorenie farebnej linky pre zobrazenie, ak sa klikne na spoj
    for (int j = 0; j < vecLinksGUI.size(); j++)
    {
        int size = vecLinksGUI.at(j)->getLine()->getBreakPoints().size();

        // Pripadne zmazanie uz existujucich objektov
        for (auto i : vecLinksGUI.at(j)->markers)
        {
            delete i;
        }
        vecLinksGUI.at(j)->markers.clear();

        for (int i = 0; i < size - 1; i++)
        {
            QGraphicsLineItem *l = new QGraphicsLineItem;
            l->setLine(vecLinksGUI.at(j)->getLine()->getBreakPoints().at(i)->getX(), vecLinksGUI.at(j)->getLine()->getBreakPoints().at(i)->getY(),
                          vecLinksGUI.at(j)->getLine()->getBreakPoints().at(i+1)->getX(), vecLinksGUI.at(j)->getLine()->getBreakPoints().at(i+1)->getY());
            l->setPen(QPen(vecLinksGUI.at(j)->line_color, 10, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            l->setOpacity(0);
            this->addItem(l);
            vecLinksGUI.at(j)->markers.append(l);

        }
    }
}


/**
 * @brief MyMap::mousePressEvent
 * @param event
 */
void MyMap::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (EditingMode)
    {
        addDetourItems(items(event->scenePos()));
    }

    // V prípade kliknutia do scény sa zvýraznená linka zmaže
    for (int i = 0; i < this->vecLinksGUI.size(); i++)
    {
        this->vecLinksGUI.at(i)->Pressed = false;

        for (int j = 0; j < this->vecLinksGUI.at(i)->markers.size(); j++)
        {
            this->vecLinksGUI.at(i)->markers.at(j)->setOpacity(0);
        }
    }

    // Nastaví všetky ulice na nestlačené
    for (int i = 0; i < this->vecStreetsGUI.size(); i++)
    {
        this->vecStreetsGUI.at(i)->Pressed = false;
    }


    QGraphicsScene::mousePressEvent(event);

}

/**
 * @brief MyMap::keyPressEvent Pri stlaceni tlačidla "enter" sa novo naklikaná trasa uloží do linky. Pri stlačení "escape" sa zruší výber ulíc a zastávok.
 * @param event
 */
void MyMap::keyPressEvent(QKeyEvent *event)
{
        if( (event->key() == Qt::Key_Return) || (event->key() == Qt::Key_Enter))
        {
            if (this->EditingMode && !this->detour_streets.empty() && !this->detour_deleted_stops.empty())
            {
                this->EditingMode = false;
                AppendNewStreetsToLine();
                makeMarkers();
            }
            else
            {
                QMessageBox msgBox;
                msgBox.setText("Warning, you need at least one street to add to the deroute and one stop to delete from the line.");
                msgBox.exec();
            }

            for (StreetGUI * street: this->getStreetsGUI())
            {
                street->Pressed = false;
            }

        }
        else if (event->key() == Qt::Key_Escape)
        {
            this->detour_streets.clear();
            this->detour_deleted_stops.clear();

            for (StreetGUI * street: this->getStreetsGUI())
            {
                street->Pressed = false;
            }
        }
        else
        {
        }

      QGraphicsScene::keyPressEvent(event);

}

