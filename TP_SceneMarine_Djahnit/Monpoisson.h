#ifndef MONPOISSON_H
#define MONPOISSON_H
#include<QMouseEvent>
#include <Qt>
#include<QKeyEvent>
#include"imageR.h"
class Monpoisson :  public ImageR
{

public:
    Monpoisson(PageG * ptPage, InfoForme & infos);
     void mousePressEvent(QGraphicsSceneMouseEvent *);
     void mouseMoveEvent(QGraphicsSceneMouseEvent *);
     void keyReleaseEvent(QKeyEvent *event);
     void timerEvent(QTimerEvent *);


};

#endif // MONPOISSON_H

