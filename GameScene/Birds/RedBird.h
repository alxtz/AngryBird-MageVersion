#ifndef REDBIRD_H
#define REDBIRD_H


#include <string>
#include <Box2D/Box2D.h>
#include "../AbsClasses/ItemData.h"
#include "../AbsClasses/AbsBird.h"

using namespace std;

class RedBird : public AbsBird
{
    Q_OBJECT

    public:
        RedBird(b2World * inputWorld);

    public slots:
        void updatePos ();
};

#endif // REDBIRD_H
