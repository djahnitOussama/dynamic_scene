#include "poisson.h"

poisson::poisson(PageG * ptPage, InfoForme & infos):ImageR(ptPage, infos)
{

directionx = false;
directionMovex=1;
startTimer(60);
}
