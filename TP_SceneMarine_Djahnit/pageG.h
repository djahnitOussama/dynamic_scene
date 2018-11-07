#ifndef PAGEG_H
#define PAGEG_H

#include <QGraphicsScene>
#include <QString>
#include <QMouseEvent>

#include "elementG.h"

class ElementG;

// classe de gestion de la scène graphique

class PageG : public QGraphicsScene
{
    Q_OBJECT


    QString repertoire;     // mémorise le chemin de l'application

    // méthodes private (usage exclusivement interne)
    InfoForme LigneToInfo(QString ligne);
    void AlerteIni(int indLigne, const QString &t);

public:
    PageG(QObject *parent, QString FichierIni);

    ElementG*  ChercheElementById(int id);
};

#endif // PAGEG_H
