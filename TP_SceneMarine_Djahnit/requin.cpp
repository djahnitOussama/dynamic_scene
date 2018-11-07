#include "requin.h"
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>
#include<QKeyEvent>
#include <iostream>

requin::requin(PageG *ptPage, InfoForme &infos):ImageR(ptPage, infos)
{
    directionx = false;
    directionMovex=1;
    bool1=true;
    startTimer(15);
    this->setFlag(GraphicsItemFlag::ItemIsFocusable);
    setFocus();



}
void requin ::keyReleaseEvent(QKeyEvent *evt)
{
    switch (evt->key()) {
    case Qt::Key_A:
        this->moveBy(-4,-5);
        posy=this->y();
        if (posy <= 20-this->dimensions.y() )
        {
           moveBy(4,5);
           }
        update();
        break;
    case Qt::Key_Q:
        this->moveBy(4,5);
        posy=this->y();
        if (posy >= 600 - this->dimensions.y())
        {
           moveBy(-4,-5);

           }

        break;
    case Qt::Key_S:
        if (bool1==true){
            bool1=false;
            std::cout<<"requin  "<<this->x()<<"     "<<this->y()<<std::endl;
        }
        break;
    case Qt::Key_D:
        if (bool1==false){
            bool1=true;
        }
        break;



        update();

    }
}


