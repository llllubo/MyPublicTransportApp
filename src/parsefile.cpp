//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#include "parsefile.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>


/**
 * @brief ParseFile::ParseFile Konštruktor objektu analyzátora naplní objekt zadanými údajmi zo súboru.
 * V prípade nesprávnej štruktúry JSON vstupného súboru, sa program ukončí s chybou.
 * @param parent Ukazateľ na rodičovský objekt.
 */
ParseFile::ParseFile()
{
    QString jsonString = parseJson();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8());
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        qFatal("CHYBA! Nespravny format JSON vstupneho suboru.");
        exit(EXIT_FAILURE);
    }

    QJsonObject links;
    links = jsonDoc.object();                   // Obsah súboru JSON je v objekte.

    getInfos(links);                            // Naplnenie objektu analyzator zadanymi udajmi o linkach.
}


/**
 * @brief Analýza súboru formátu JSON, v ktorom sú uložené linky a informácie o nich.
 * @return Vracia sa obsah JSON súboru v reťazci.
 */
QString ParseFile::parseJson()
{
    QFile file;
    file.setFileName("../examples/data.json");
    file.open(QFile::ReadOnly);
    QString jsonString = file.readAll();
    file.close();
    return jsonString;
}


/**
 * @brief ParseFile::getInfos Naplní sa analyzátor (objekt) vektorom štruktúr, kde každá štruktúra nesie údaje o jednej zadanej linke.
 * @param links JSON objekt získaného obsahu zo súboru.
 */
void ParseFile::getInfos(QJsonObject links)
{
    // Pripravenie vektora prazdnych struktur a získanie názvov liniek.
    struct lineInfo_t tmp;
    QList<QString> keysList = links.keys();
    for (int i = 0; i < links.keys().size(); i++)
    {
        linesInfos.append(tmp);
        linesInfos[i].nameLine = keysList[i];
    }

    // Naplnenie štruktúr vo vektore s informáciami o linkách zadané v súbore JSON.
    int j;
    QJsonObject::const_iterator i;               // Iterátor (ukazateľ) cez všetky linky definované v JSON súbore.
    for (i = links.begin(), j = 0; i != links.end(); i++, j++)
    {
        if ((*i).toObject().value("Number of links").isUndefined())
        {
            qFatal("CHYBA! Nespravny identifikator 'Number of links' vo vstupnom subore.");
            exit(EXIT_FAILURE);
        }
        else if ((*i).toObject().value("Departure frequency").isUndefined())
        {
            qFatal("CHYBA! Nespravny identifikator 'Departure frequency' vo vstupnom subore.");
            exit(EXIT_FAILURE);
        }
        else if ((*i).toObject().value("Time-Stop").isUndefined())
        {
            qFatal("CHYBA! Nespravny identifikator 'Time-Stop' vo vstupnom subore.");
            exit(EXIT_FAILURE);
        }
        linesInfos[j].numofLinks = (*i).toObject().value("Number of links").toInt();
        linesInfos[j].depFreq = (*i).toObject().value("Departure frequency").toInt();
        linesInfos[j].timesStops = (*i).toObject().value("Time-Stop").toVariant().toMap();
    }
}
