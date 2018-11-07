#ifndef IMAGED_H
#define IMAGED_H
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include"image.h"
#include <Qt>

class imageD : public Image
{
protected :
    QPointF oldPosition;

public:
    imageD(PageG * ptPage, InfoForme & infos);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *evt);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *evt);


};

#endif // IMAGED_H
