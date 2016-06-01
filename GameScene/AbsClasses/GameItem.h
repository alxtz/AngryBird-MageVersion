#ifndef GAMEITEM_H
#define GAMEITEM_H


#include <cstring>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <Box2D/Box2D.h>

using namespace std;

class GameItem : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        GameItem();

        string objectType;

    public slots:
        virtual void updatePos();

    protected:
        b2Body * physicBody;
        b2BodyDef * bodyStruct;
        b2FixtureDef * bodyFixture;

        b2World * inWorld;

        float PixToMeter_x(float Pix);
        float MeterToPix_x(float Meter);

        float PixToMeter_y(float Pix);
        float MeterToPix_y(float Meter);

        float RadToDeg(float Rad);
        float DegToRad(float Deg);
        
        void addPhysics();
};

#endif // GAMEITEM_H
