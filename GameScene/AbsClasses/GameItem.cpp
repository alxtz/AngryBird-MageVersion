#include "GameItem.h"

GameItem::GameItem()
{
    bodyStruct = new b2BodyDef();
    bodyFixture = new b2FixtureDef();
    itemData = new ItemData();
}

void GameItem::updatePos()
{
    b2Vec2 pos;
    pos = physicBody->GetPosition();
    setPos(MeterToPix_x(pos.x) , MeterToPix_y(pos.y));

    float angle;
    angle = physicBody->GetAngle();
    setRotation(-RadToDeg(angle));
}

float GameItem::PixToMeter_x(float Pix)
{
    return Pix;
}

float GameItem::MeterToPix_x(float Meter)
{
    return Meter;
}

float GameItem::PixToMeter_y(float Pix)
{
    return 600-Pix;
}

float GameItem::MeterToPix_y(float Meter)
{
    return 600-Meter;
}

float GameItem::RadToDeg(float Rad)
{
    return Rad * 180 /3.1415926f;
}

float GameItem::DegToRad(float Deg)
{
    return 3.1415926 / 180 * Deg;
}

void GameItem::addPhysics()
{
    
}
