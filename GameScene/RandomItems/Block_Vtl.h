#ifndef BLOCK_VTL_H
#define BLOCK_VTL_H


#include <QObject>
#include "../AbsClasses/GameItem.h"

class Block_Vtl : public GameItem
{
    Q_OBJECT

    public:
        Block_Vtl(b2World * inputWorld , int inputX , int inputY);
};

#endif // BLOCK_VTL_H
