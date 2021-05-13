//************************************************************************//
//**                        ICP | FIT VUT                               **//
//**                                                                    **//
//**    PROJECT:    DISPLAY AND MONITORING OF PUBLIC TRANSPORT          **//
//**    VERSION:    1.0                                                 **//
//**    DATE:       17.05.2020                                          **//
//**    AUTHORS:    Lubos Vajcovec, xvajco00 | Samuel Gajdos, xgajdo26  **//
//************************************************************************//

#ifndef PARSEFILE_H
#define PARSEFILE_H

#include <QObject>
#include <QVector>
#include <QMap>
#include <QVariant>

class ParseFile : public QObject
{
    Q_OBJECT
public:
    explicit ParseFile();

    struct lineInfo_t {                                 /// Informácie o linke.
        QString nameLine;                               /// Nazov linky.
        int numofLinks;                                 /// Počet spojov danej linky.
        int depFreq;                                    /// Frekvencia spojov linky.
        QMap<QString,QVariant> timesStops;              /// Dvojice (čas príchodu na zastávku | názov zastávky) pre danú linku.
    };
    QVector<struct lineInfo_t> linesInfos;              /// Informácie o linkách .

private:
    QString parseJson();
    void getInfos(QJsonObject links);

signals:

};

#endif // PARSEFILE_H
