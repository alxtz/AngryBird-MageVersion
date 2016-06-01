#ifndef GAMEITEM_H
#define GAMEITEM_H


#include <string>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <Box2D/Box2D.h>
#include "ItemData.h"

using namespace std;

class GameItem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GameItem();

        string objectType;
        ItemData * itemData;
        b2Body * physicBody;
        b2World * inWorld;
        b2BodyDef * bodyStruct;
        b2FixtureDef * bodyFixture;

    public slots:
        virtual void updatePos();

    protected:

        float PixToMeter_x(float Pix);
        float MeterToPix_x(float Meter);

        float PixToMeter_y(float Pix);
        float MeterToPix_y(float Meter);

        float RadToDeg(float Rad);
        float DegToRad(float Deg);
        
        void addPhysics();
};

#endif // GAMEITEM_H
