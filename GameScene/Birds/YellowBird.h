#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H


#include <Box2D/Box2D.h>
#include "../AbsClasses/ItemData.h"
#include "../AbsClasses/AbsBird.h"

class YellowBird : public AbsBird
{
    Q_OBJECT

    public:
        YellowBird(b2World * inputWorld);

    public slots:
        void updatePos ();
        void specialAbility();
};

#endif // YELLOWBIRD_H
