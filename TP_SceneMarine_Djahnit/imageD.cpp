#include "imageD.h"
#include <QMessageBox>
#include<QMouseEvent>
#include<QGraphicsSceneMouseEvent>

imageD::imageD(PageG *ptPage, InfoForme &infos) :Image(ptPage,infos)
{
    this->setFlag(GraphicsItemFlag::ItemIsFocusable);
    setFocus();
}
void imageD::mousePressEvent(QGraphicsSceneMouseEvent * evt)
{
    // événément clic souris, on teste les boutons
    if ( evt->button() == Qt::LeftButton)
    {
        oldPosition = evt->scenePos();      // mémorise la position de la souris
        update();
    }
}
void imageD::mouseMoveEvent(QGraphicsSceneMouseEvent * evt)
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
