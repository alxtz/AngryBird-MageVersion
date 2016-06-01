#ifndef BIGBIRD_H
#define BIGBIRD_H


#include <Box2D/Box2D.h>
#include "../AbsClasses/ItemData.h"
#include "../AbsClasses/AbsBird.h"

class BigBird : public AbsBird
{
    Q_OBJECT

    public:
        BigBird(b2World * inputWorld);

    public slots:
        void setPullPos (int x , int y);
        void updatePos ();
        void specialAbility();
};

#endif // BIGBIRD_H
