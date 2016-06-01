#ifndef STICK2_VTL_H
#define STICK2_VTL_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick2_Vtl : public GameItem
{
    Q_OBJECT

    public:
        Stick2_Vtl(b2World * inputWorld , int inputX , int inputY);
};

#endif // STICK2_VTL_H
