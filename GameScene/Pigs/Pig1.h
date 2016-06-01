#ifndef PIG1_H
#define PIG1_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Pig1 : public GameItem
{
    Q_OBJECT

    public:
        Pig1(b2World * inputWorld , int inputX , int inputY);
};

#endif // PIG1_H
