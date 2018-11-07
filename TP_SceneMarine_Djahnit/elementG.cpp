#include <QtWidgets>
#include "elementG.h"

ElementG::ElementG(PageG *ptPage, InfoForme &infos)
    :laPage(ptPage), id(infos.id), dimensions(infos.rect), texte(infos.texte)
{
    penColor.fromRgb(220,220,220);
    bkgColor.fromRgb(220,220,180);
    epaisseurStylo = 3;
}

QRectF ElementG::boundingRect() const
{
    // la définition de la fonction doit retourner sous forme de Bloc les limites externes de la forme
    double  demiStylo=epaisseurStylo/2;
    QRectF rect(dimensions);
    rect.adjust(-demiStylo,-demiStylo-15,demiStylo,demiStylo);
    return rect;
}

void ElementG::paint(QPainter *painter,const QStyleOptionGraphicsItem *, QWidget * )
{
    painter->setBrush(QBrush(bkgColor,Qt::FDiagPattern));
    painter->setPen(QPen(penColor,epaisseurStylo));
    painter->drawRect(dimensions);
}


 bool ElementG::isId(int a)
 {
     return id==a;
 }

 int ElementG::getId(){
     return this->id;
 }
 qreal ElementG::getX(){
     return this->dimensions.x();
 }
 qreal ElementG::getY(){
     return this->dimensions.y();
 }

 void ElementG::CreationLien(ElementG *el){

      maList.push_back(el);


 }
 void ElementG::setdirection(){}
