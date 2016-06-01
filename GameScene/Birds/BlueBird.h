#ifndef BLUEBIRD_H
#define BLUEBIRD_H


#include <Box2D/Box2D.h>
#include "../AbsClasses/ItemData.h"
#include "../AbsClasses/AbsBird.h"

class BlueBird : public AbsBird
{
    Q_OBJECT

    public:
        BlueBird(b2World * inputWorld , int inputX=0 , int inputY=0);

    public slots:
        void updatePos ();
        void specialAbility();

    signals:
        void spawnBlueChild(int x , int y);
};

#endif // BLUEBIRD_H
