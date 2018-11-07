#ifndef IMAGE_H
#define IMAGE_H


#include "elementG.h"


class Image : public ElementG
{
    Q_OBJECT

protected:
    QString nomFichier;
    QImage image;

public:
    Image(PageG * ptPage, InfoForme & infos);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

};

#endif // IMAGE_H
