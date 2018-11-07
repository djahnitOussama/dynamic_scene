#ifndef ELEMENTG_H
#define ELEMENTG_H

#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsObject>
#include <vector>

const int MAX_LIENS=5;

struct InfoForme
{
    int id;
    QString type;
    QRect rect;     // position et dimension du Bloc délimitant la form
    QString texte;   // texte
    int liensTo[MAX_LIENS];   // tableau de 5 identifiants maximum
};

class PageG;

class ElementG : public QGraphicsObject
{
    Q_OBJECT

protected:
    PageG * laPage;
    int id;
    QRectF dimensions;
    QString texte;



    // données graphique
    QColor bkgColor;
    QColor penColor;
    int epaisseurStylo;
    QString nomImage;

public:
    std::vector <ElementG*> maList;
    ElementG(PageG * ptPage, InfoForme & infos);
    int getId();
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)=0;

    bool isId(int a);

    void CreationLien(ElementG* el);
    qreal getX();
    qreal getY();
    virtual void setdirection();
};

#endif // ELEMENTG_H
