#ifndef REQUIN_H
#define REQUIN_H
#include<imageR.h>
#include<QTimerEvent>
#include "Monpoisson.h"
#include<QKeyEvent>

class requin : public ImageR
{
protected:

public:
    requin(PageG * ptPage, InfoForme & infos);
    void keyReleaseEvent(QKeyEvent *evt);

};

#endif // REQUIN_H
