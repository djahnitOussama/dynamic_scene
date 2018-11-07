#ifndef FIGUREACTIVE_H
#define FIGUREACTIVE_H
#include<QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <Qt>
#include "image.h"
#include<QTimerEvent>


// Image Réactive : affichage d'une seconde image lors du survol par la souris

class ImageR : public Image
{
    Q_OBJECT

protected:
    QImage image1;
    QImage image2;
    QPointF oldPosition;
    int directionMovex;
    qreal posx ;
    bool directionx;
    bool bool1;

    qreal posy;

public:
    ImageR(PageG * ptPage, InfoForme & infos);
    virtual void timerEvent(QTimerEvent *);


};

#endif // FIGUREACTIVE_H
