#ifndef STICK2_HRZ_H
#define STICK2_HRZ_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Stick2_Hrz : public GameItem
{
    Q_OBJECT

    public:
        Stick2_Hrz(b2World * inputWorld , int inputX , int inputY);
};

#endif // STICK2_HRZ_H
