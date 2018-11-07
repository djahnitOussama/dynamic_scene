#include <QImage>
#include <QMessageBox>
#include "image.h"


Image::Image(PageG * ptPage, InfoForme & infos)
    :ElementG(ptPage,infos),nomFichier(infos.texte)
{
    // par convention toutes les images sont dans un sous-dossier
    // du répertoire courant
    QString fileName = QString("img/")+nomFichier;

    // chargement de l'image et vérification
    image = QImage(fileName);
    if (image.isNull())
        QMessageBox::warning(NULL,"Création Figure",QString("figure '<i> %1 </i>' n'existe pas").arg(fileName));

}

void Image::paint(QPainter *painter,const QStyleOptionGraphicsItem *, QWidget * )
{

    painter->drawImage(dimensions,image);
}
