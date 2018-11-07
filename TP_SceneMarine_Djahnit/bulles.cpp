#include "bulles.h"
#include<imageR.h>

bulles::bulles(PageG * ptPage, InfoForme & infos)
               : ImageR(ptPage, infos)
{
startTimer(400);
directionMovex=-1;

}
void bulles::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    image = image1;
    update();
}
void bulles::mousePressEvent(QGraphicsSceneMouseEvent *evt)
{
    if ( evt->button() == Qt::LeftButton){
       maList[0]->hide();
    }


}
void bulles::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    image = image2;
    update();
}
void bulles::timerEvent(QTimerEvent *)
{
    posy=this->y();
    this->moveBy(0,8*directionMovex);
    this->show();
        update();
        if ( posy < -70){
            this->hide();
            this->setPos(0,100);
            update();
        }


}
