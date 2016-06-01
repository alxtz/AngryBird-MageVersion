#ifndef REDBIRD_H
#define REDBIRD_H


#include <cstring>
#include <Box2D/Box2D.h>
#include "../AbsClasses/AbsBird.h"

using namespace std;

class RedBird : public AbsBird
{
    Q_OBJECT

    public:
        RedBird(b2World * inputWorld);
};

#endif // REDBIRD_H
