#ifndef REDBIRD_H
#define REDBIRD_H


#include <Box2D/Box2D.h>
#include "../AbsClasses/AbsBird.h"

class RedBird : public AbsBird
{
    Q_OBJECT

    public:
        RedBird(b2World * inputWorld);
};

#endif // REDBIRD_H
