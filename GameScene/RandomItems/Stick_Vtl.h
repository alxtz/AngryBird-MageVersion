#ifndef STICK_VTL_H
#define STICK_VTL_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick_Vtl : public GameItem
{
    public:
        Stick_Vtl(b2World * inputWorld , int inputX , int inputY);
};


#endif // STICK_VTL_H
