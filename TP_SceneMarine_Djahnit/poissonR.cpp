#include "poissonR.h"
#include<iostream>

poissonR::poissonR(PageG * ptPage, InfoForme & infos):ImageR(ptPage, infos)
{
    directionx = true;
    directiony=true;
    directionMovex=-1;
    directionMovey=-1;
    startTimer(15);
    image=image2;
    changer_axe=true;

}
void poissonR::timerEvent(QTimerEvent *)
{
    posx=this->x();
    if (changer_axe == true){
        if (posx <= 10 - this->dimensions.x()  && directionx == true )
        {
            directionMovex=1;
            image = image1;
            update();
            directionx = false;
    }

        if (posx >= 1000 - this->dimensions.x() && directionx==false)
            {
            directionMovex= -1;
            image = image2;
            update();
            directionx = true;

            }
          this->moveBy(6*directionMovex,0);
        //std::cout<<posx<<std::endl;

         update();
    }
    if(changer_axe==false){
        posy=this->y();
        if (posy <= 10 - this->dimensions.y()  && directiony == true )
        {
            directionMovey=1;

            update();
            directiony = false;

    }
        if (posy >= 600 - this->dimensions.y()  && directiony == false)
        {
            directionMovey=-1;

            update();
            directiony = true;

    }

        this->moveBy(0,4*directionMovey);
    }




}
void poissonR::setdirection(){
     changer_axe=!changer_axe ;
}


