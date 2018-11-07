#ifndef BULLES_H
#define BULLES_H
#include"imageR.h"


class bulles : public ImageR
{
protected:
    qreal posy;
public:
    bulles(PageG * ptPage, InfoForme & infos);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent *evt);
    void timerEvent(QTimerEvent *);
};

#endif // BULLES_H
