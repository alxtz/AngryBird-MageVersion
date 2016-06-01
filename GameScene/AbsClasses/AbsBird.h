#ifndef ABSBIRD_H
#define ABSBIRD_H


#include <cstring>
#include <Box2D/Box2D.h>
#include <QObject>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include "GameItem.h"

using namespace std;

class AbsBird : public GameItem
{
    Q_OBJECT

    public:
        AbsBird();

        int health;

    public slots:
        virtual void setPullPos(int x , int y);
        void updatePos ();
        virtual void specialAbility();
        void releaseBird(int forceX , int forceY);
};

#endif // ABSBIRD_H
