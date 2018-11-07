#ifndef POISSONROUGE_H
#define POISSONROUGE_H
#include"imageR.h"


class poissonR : public ImageR
{
protected:
int directionMovey;
bool directiony;
bool changer_axe;
public:
    poissonR(PageG *ptPage, InfoForme &infos);
    void timerEvent(QTimerEvent *);
    void setdirection() override;
};

#endif // POISSONROUGE_H
