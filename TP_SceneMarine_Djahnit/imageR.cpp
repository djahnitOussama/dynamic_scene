#include <QMessageBox>
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<QTimerEvent>
#include "imageR.h"


#include <iostream>

ImageR::ImageR(PageG * ptPage, InfoForme & infos)
    : Image(ptPage,infos)
{
    // le fonctionnement d'une figure active suppose qu'il existe 2 fichiers image
    // par convention le nom de la vue initiale se termine par 1
    // c'est le nom désigné dans le fichier ini il a donc été chargé par le constructeur
    // de la classe mère 'Figure'
    // la vue alternative se termine par 2 
    bool1=true;
    image1 = image;  // déjà initialisée
    this->setFlag(GraphicsItemFlag::ItemIsFocusable);
    setFocus();

    // vérification du nom de la vue initiale :
    bool ok = true;
    int pos = nomFichier.lastIndexOf(".");
    if (pos < 0)
        ok = false;

    if (ok && (nomFichier.at(pos-1)!='1'))
        ok = false;
    if (!ok)
    {
        QMessageBox::warning(NULL,"Création FigureActive","nom de fichier ne respecte pas convention = terminé par '1'");
        return;
    }


    // modification du nom pour la vue alternative
    QString nomFichier2 = nomFichier;
    nomFichier2[pos-1] = '2';
    QString fileName = QString("img/")+nomFichier2;

    // chargement de l'image et vérification
    image2 = QImage(fileName);
    if (image2.isNull())
        QMessageBox::warning(NULL,"Création FigureActive",QString("figure '<i> %1 </i>' n'existe pas").arg(fileName));
        setAcceptHoverEvents(true);

}
void ImageR::timerEvent(QTimerEvent *)
{
 if (bool1==true){
        posx=this->x() ;
        if (posx <= 0  - this->dimensions.x() && directionx == true )
        {
            directionMovex=1;
            image = image1;
            update();
            directionx = false;
            std::cout<<this->dimensions.x()<<std::endl;
    }

        if (posx >= 1000 - this->dimensions.x() && directionx==false)
            {
            directionMovex= -1;
            image = image2;
            update();
            directionx = true;

            }

this->moveBy(6*directionMovex,0);

    update();
 }
}


