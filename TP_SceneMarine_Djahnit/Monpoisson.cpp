#include "Monpoisson.h"
#include<QMessageBox>
#include<QKeyEvent>
#include<iostream>
Monpoisson::Monpoisson(PageG * ptPage, InfoForme & infos)
    :ImageR(ptPage, infos)
{
}
void Monpoisson::mousePressEvent(QGraphicsSceneMouseEvent * evt)
{
    // événément clic souris, on teste les boutons
    if ( evt->button() == Qt::LeftButton)
    {
        oldPosition = evt->scenePos();      // mémorise la position de la souris
        update();

    }
}
void Monpoisson::mouseMoveEvent(QGraphicsSceneMouseEvent * evt)
{
if ( evt->buttons() == Qt::LeftButton)
{
    // détermine le décalage de la souris par rapport à sa dernière position
    QPointF delta = evt->scenePos()-oldPosition;

    setPos(pos()+delta);            // applique le même décalage à l'objet
    oldPosition = evt->scenePos();  // mémorise la position de la souris

    update();
}
}
void Monpoisson::keyReleaseEvent(QKeyEvent *event)
{
         int offset=11;
         switch (event->key()) {
         case Qt::Key_Up:
             moveBy(0,-offset);
             maList[1]->moveBy(0,-6);
             if (maList[1]->y()<10 - maList[1]->getY()){
               maList[1]->moveBy(0,6);
             }

             update();


             if (this->y()<=10-this->dimensions.y())
             {
             moveBy(0,+offset);
             update();
             }

             break;
         case Qt::Key_Down:
             maList[2]->setdirection();
             moveBy(0,+offset);

             update();
             if (this->y()>=600 - this->dimensions.y())
             {
              moveBy(0,-offset);
              update();
             }


             break;
         case Qt::Key_Right:
             moveBy(+offset,0);
             image=image1;
             if (this->x()>=1100-this->dimensions.x())
             {
               moveBy(-offset,0);
               update();
             }
             break;
         case Qt::Key_Left:
             moveBy(-offset,0);
             image=image2;
             update();

             std::cout<<"poisson"<<this->x()<<"     "<<this->y()<<std::endl;
         if (this->x()<=10- this -> dimensions.x())
         {
             moveBy(+offset,0);
             update();
         }

             break;
         case Qt::Key_K:
             maList[0]->setParentItem(this);
             break;
         case Qt::Key_B:
             maList[0]->setParentItem(0);
             break;
         }


      //std::cout<<this->x()<<"   "<<this->y()<<std::endl;

    }
void Monpoisson::timerEvent(QTimerEvent *)
{
}



