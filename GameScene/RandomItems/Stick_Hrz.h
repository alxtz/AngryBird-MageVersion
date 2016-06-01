#ifndef STICK_HRZ_H
#define STICK_HRZ_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick_Hrz : public GameItem
{
    Q_OBJECT

    public:
        Stick_Hrz(b2World * inputWorld , int inputX , int inputY);
};

#endif // STICK_HRZ_H
