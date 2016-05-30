#ifndef GROUND_H
#define GROUND_H


#include <QGraphicsPixmapItem>
#include "../AbsClasses/GameItem.h"

class Ground : public GameItem
{
    public:
        Ground(b2World * inputWorld);
};

#endif // GROUND_H
