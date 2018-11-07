#ifndef POISSON_H
#define POISSON_H

#include "imageR.h"


class poisson : public ImageR
{
    Q_OBJECT
    public:
         poisson(PageG * ptPage, InfoForme & infos);
};


#endif // POISSON_H
