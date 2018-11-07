#include <QtWidgets>

#include "pageG.h"
#include "elementG.h"
#include "image.h"
#include "imageD.h"
#include "Monpoisson.h"
#include<bulles.h>
#include"requin.h"
#include"poissonR.h"
#include"poisson.h"

void PageG::AlerteIni(int indLigne,const QString &t )
{
    // Pour affichage de messages d'alerte en cas d'anomalies dans le fichier ini

    QMessageBox::critical(qApp->activeWindow() ,"Erreur fichier ini",
                          QString("pour <b>id %1</b> ligne incorrecte %2").arg(indLigne).arg(t));
}

InfoForme PageG::LigneToInfo(QString ligne)
{
    // la fonction remplit les attributs de la structure InfoForme
    // en parcourant le texte d'une ligne (du fichier ini)

    QTextStream flux(&ligne);
    InfoForme info;
    int x,y,w,h;

    flux >> info.id >> info.type;

    // coordonnées et taille du Bloc
    char c;
    flux.skipWhiteSpace();
    flux >> c;
    if (c!='[')
        AlerteIni(info.id,"caractère '['");

    flux >> x >>y >> w >> h ;
    if(flux.status() == QTextStream::ReadCorruptData)
        AlerteIni(info.id,"");

    flux.skipWhiteSpace();
    flux >> c;
    if ( c!=']')
        AlerteIni(info.id,"caractère ']'");

    info.rect = QRect(x,y,w,h);



    // donnée facultative :  liste d'indice de liens
    memset(info.liensTo,0,sizeof(info.liensTo)); // tout à 0 valeur par défaut
    info.texte = "";

    flux.skipWhiteSpace();
    flux >> c;
    if ( c=='{')    // le champ facultatif 'liens' est présent, on le traite
    {
        for (int i=0;i<5;i++)
            flux >> info.liensTo[i];    // si aucun nombre n'est détecté, valeur = 0
        flux.skipWhiteSpace();
        flux >> c;
        if ( c!='}')
            AlerteIni(info.id,"caractère '}'");
    }

    // donnée facultative :  texte  (
    //      il faut prendre soit de restaurer le caractère c qui a été lu pour les tests précédents
    flux.skipWhiteSpace();
    if (!flux.atEnd())
        info.texte=flux.readLine() ;
    if (c && c!='}')
        info.texte.prepend(c);

    return info;

}




PageG::PageG(QObject *parent, QString nameIni)
    : QGraphicsScene(parent)
{
    // le constructeur ouvre et parcourt le fichier ini
    // pour créer les elements graphiques

    // vérification du chemin et de l'existence du fichier inui
    QFile fichier;
    fichier.setFileName(nameIni);

    repertoire = QDir::currentPath();
    if( !fichier.exists())
    {
        repertoire = QFileInfo(qApp->applicationFilePath()).absolutePath();
        QDir::setCurrent(repertoire);
    }
    if( !fichier.exists())
    {
        // on demande à l'utilisateur de chercher le chemin
        QString fName = QFileDialog::getOpenFileName(NULL,"Recherchez le fichier",
                                                     repertoire, "fichier (*.ini)");
        fichier.setFileName(fName);
        repertoire = QFileInfo(fichier).absoluteDir().absolutePath();
        QDir::setCurrent(repertoire);
    }

    if( !fichier.open(QIODevice::ReadOnly))
    {
        QString texte = QString("fichier '<i>")+nameIni +"</i>' inaccessible";
        QMessageBox::critical(NULL ,"Erreur accès",texte);
    }

    // lecture du fichier
    QString ligne;
    QTextStream flux(&fichier);
    QMap <ElementG*,int> LiensDifferes;

    while(!flux.atEnd())
    {
        // on parcourt le fichier ligne après ligne
        ligne = flux.readLine();
        if (ligne.isEmpty() || !ligne[0].isDigit())
            continue;           // ligne de commentaire à ignorer

        // collecte des informations de la ligne dans une structure InfoForme
        InfoForme infoF = LigneToInfo(ligne);

        // création d'un objet de la classe correspondante
        ElementG *r = NULL;

        if (infoF.type == "Image")
            r = new Image(this,infoF);
        if (infoF.type == "ImageD")
            r = new imageD(this,infoF);
        if (infoF.type == "poisson")
            r = new poisson(this,infoF);
        if (infoF.type == "Monpoisson")
            r = new Monpoisson(this,infoF);
        if (infoF.type == "bulles")
            r = new bulles(this,infoF);
        if (infoF.type == "requin")
            r = new requin(this,infoF);
        if (infoF.type == "poissonR")
            r = new poissonR(this,infoF);



        // insertion du nouvel objet dans la scène
        addItem(r);

        // gestion des liens (champ optionnel)
        if (!infoF.liensTo[0])
            continue;   // pas de lien à créer

        // parcourt de la liste des liens à créer
        // si l'élément existe déjà --> création immédiate du lien
        // sinon on stocke les informations pour création différée

        for (int i=0; i<MAX_LIENS;i++)
        {
            ElementG* el=ChercheElementById(infoF.liensTo[i]);
            if (el){
                r->CreationLien(el);

            }
            else
            {
                if (infoF.liensTo[i])
                    LiensDifferes.insertMulti(r,infoF.liensTo[i]);
            }
        }
    }

    // une fois que tous les éléments sont crées, on reprend la création de liens différés si besoin
    if (! LiensDifferes.empty())
    {
        QMapIterator<ElementG*, int> iter(LiensDifferes);  while (iter.hasNext())
        {
            iter.next();
            ElementG* el=ChercheElementById(iter.value());
            if (el)
                iter.key()->CreationLien(el);
        }
    }
}


ElementG*  PageG::ChercheElementById(int id)
{
    // la fonction permet de retrouver l'adresse d'un élément à partir de son index
    if (!id)
        return NULL;

    QList <QGraphicsItem *> liste = this->items();  // liste des éléments de la scène

    for(int i = 0; i< liste.size(); i++)            // on parcourt la liste
    {
        QGraphicsItem *it = liste[i];
        if(((ElementG*)it)->isId(id))               // en testant l'index de chaque élément
            return ((ElementG*)it);                 // trouvé -> retourne l'adresse de l'objet
    }

    // si aucun element n'a cet identifiant
    return NULL;
}
