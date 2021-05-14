//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Bever | Samuel Gajdos                         **//
//************************************************************************//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QtGui>
#include "mymap.h"

/**
 * @brief MainWindow::MainWindow Konštruktor inicializuje hlavné okno.
 * @param parent Referencia na rodičovský objekt.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->map_scene = new MyMap(this);


    ui->graphicsView->setScene(this->map_scene);

    auto org =  ui->graphicsView->transform();
    ui->graphicsView->setTransform(QTransform(
                                       0.4, org.m12(), org.m21(), 0.4, org.dx(), org.dy()));
    ui->graphicsView->show();

    connect(ui->verticalSlider, &QSlider::valueChanged, this, &MainWindow::zoom);
    connect(ui->verticalSlider_2, &QSlider::valueChanged, this, &MainWindow::setTraffic);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Vytvorenie časovača - jeden tik každú sekundu.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerEvent()));
    timer->start(100);
}

/**
 * @brief MainWindow::~MainWindow Deštruktor hlavného okna.
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief MainWindow::zoom Realizácia približenia/oddialenia mapy na základe zmeny posuvného tlačidla.
 * @param a Koeficient priblíženia/oddialenia - hodnota nastavená na posuvnom tlačidle.
 */
void MainWindow::zoom(int a)
{
    auto org =  ui->graphicsView->transform();
    qreal scale = a / 10.0;
    ui->graphicsView->setTransform(QTransform(
                                       scale, org.m12(), org.m21(), scale, org.dx(), org.dy()));
}

/**
 * @brief MainWindow::setTraffic Realizácia zaťaženia ulice na základe zmeny posuvného tlačidla, pre ulicu, ktorá bola označená
 * @param a Koeficient zaťaženia ulice -> 0 : najmenej zaťažená, 10 : neprejazdná
 */

void MainWindow::setTraffic(int a)
{
    for (int i = 0; i < this->map_scene->getStreetsGUI().size(); i++)
    {

        if (this->map_scene->getStreetsGUI().at(i)->Pressed)
        {
            this->map_scene->getStreetsGUI().at(i)->getStreet()->setTraffic(a);

            if (a == 10) // Max hodnota pre slider -> uzavreta ulica
            {
                this->map_scene->setEditingMode(true);
                this->map_scene->setClosedStreet(this->map_scene->getStreetsGUI().at(i));
                this->map_scene->getStreetsGUI().at(i)->setPen(QPen(Qt::gray, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }
            else if (this->map_scene->getClosedStreet() == this->map_scene->getStreetsGUI().at(i))
            {
                this->map_scene->setEditingMode(false);
                this->map_scene->setClosedStreet(nullptr);
                this->map_scene->getStreetsGUI().at(i)->setPen(QPen(Qt::black, 8, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
            }

            return;
        }
    }
}


/**
 * @brief MainWindow::TimerEvent Výpis simulácie času. Metóda taktiež volá metódu pre pohyb všetkých spojov.
 */
void MainWindow::TimerEvent()
{
    sec++;
    if (sec % 600 == 0)
    {
        min++;
        if (min == 24)
            min = 0;
    }
    // Nastavenie hodín a minút na dve cifry ('Zero padding').
    QString minStr = QString("%1").arg(min, 2, 10, QChar('0'));
    QString secStr = QString("%1").arg(sec / 10 % 60, 2, 10, QChar('0'));

    // Prevod času na reťazec.
    QString timeStr = minStr + " : " + secStr;

    // Výpis času.
    ui->labelTime->setText(timeStr);

    // Vykonanie pohybu
    for (int i = 0; i < this->map_scene->getLinksGUI().size(); i++)
    {
        this->map_scene->getLinksGUI().at(i)->changePosition();

        // Zvýraznenie linky, ktorá je zakliknutá
        if (this->map_scene->getLinksGUI().at(i)->Pressed)
        {
            this->map_scene->getMainwindow()->listBusLineInfos(this->map_scene->getLinksGUI().at(i)->getLine());
            for (int j = 0; j < this->map_scene->getLinksGUI().at(i)->markers.size(); j++)
            {
                this->map_scene->getLinksGUI().at(i)->markers.at(j)->setOpacity(1);
            }

        }
    }

}

/**
 * @brief MainWindow::listStreetInfos Výpis informácii o ulici na bočný panel v hlavnom okne.
 * @param idStreet Identifikátor ulice.
 * @param traffic Stupeň prejazdu na ulici.
 */
void MainWindow::listStreetInfos(QString idStreet, int traffic)
{
    this->ui->label_3->setText("Street:\t" + idStreet + "\n\n" + "Degree of Traffic:\t" + QString::number(traffic));
}

/**
 * @brief MainWindow::listStopInfos Výpis informácii o zastávke na bočný panel v hlavnom okne.
 * @param idStop Identifikátor zastávky.
 * @param idStreet Identifikátor ulice.
 */
void MainWindow::listStopInfos(QString idStop, QString idStreet)
{
    this->ui->label_3->setText("Stop:\t" + idStop + "\n\n" + "at Street:\t" + idStreet);
}

/**
 * @brief MainWindow::listBusLineInfos Výpis informácii o linke na bočný panel v hlavnom okne.
 * @param line Referencia na logický objekt linky.
 */
void MainWindow::listBusLineInfos(BusLine *line)
{

    QString stops = "| ";
    for (int i = 0; i < line->getStops().size(); i++)
    {

        int hours = line->getTimeStops().at(i) / 600;
        int minutes = line->getTimeStops().at(i) /10 % 60;
        QString hourStr = QString("%1").arg(hours, 2, 10, QChar('0'));
        QString minStr = QString("%1").arg(minutes, 2, 10, QChar('0'));

        stops += line->getStops().at(i)->getId() + ", " + hourStr + "." + minStr + " | ";
    }

    // V pripade presahu sa vypis neaktualizuje
    if (line->getStopIndex() >= line->getStops().size() || line->getStopIndex() < 0)
    {
        return;
    }

    if (line->getStreetIndex() >= line->getStreets().size() || line->getStreetIndex() < 0)
    {
        return;
    }


    QString next_stop = "Next Stop is " + line->getStops().at(line->getStopIndex())->getId() + "\n";
    QString actual_street = "Actual Street: " + line->getStreets().at(line->getStreetIndex())->getId() + "\n";

    int minutes_delay = line->getDelay() / 10;
    QString delay = "Delay: " + QString::number(minutes_delay) + " minute(s)\n";

    this->ui->label_3->setText(line->getId() + "\n" + next_stop + "\n" + actual_street + "" + delay + "\n" + stops);
    this->ui->label_3->setFrameStyle(2);
}


/**
 * @brief MainWindow::getMap_Scene Vráti referenciu na objekt grafická scéna.
 * @return Referencia na objekt grafická scéna.
 */
QGraphicsScene *MainWindow::getMap_Scene()
{
    return map_scene;
}

/**
 * @brief MainWindow::getSec Vráti aktuálny čas v sekundách.
 * @return Aktuálny čas v sekundách.
 */
int MainWindow::getSec()
{
    return this->sec;
}

/**
 * @brief MainWindow::getUi Vráti ukazateľ na grafické rozhranie.
 * @return Referencia grafického rozhrania.
 */
Ui::MainWindow *MainWindow::getUi()
{
    return this->ui;
}

/**
 * @brief MainWindow::setLines Nastaví hlavnému oknu vektor grafických objektov liniek.
 * @param lines Vektor referencií na grafické objekty liniek.
 */
void MainWindow::setLines(QVector<BusLineGUI *> lines)
{
    this->lines = lines;
}
