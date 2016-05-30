#include "Stick.h"

Stick::Stick(b2World * inputWorld)
{
    //基本設定
    setPixmap(QPixmap("./GameData/DefaultResources/Images/stick.png"));
    inWorld = inputWorld;
    setPos(800 , 0);
    setTransformOriginPoint(0 , 0);

    //設定鳥的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;

    //設定鳥的物體的定製器

        //設定一種形狀(20x203)
        b2Vec2 vertices[4];
        vertices[0].Set(0 , 0);
        vertices[1].Set(0 , -203 );
        vertices[2].Set(20 , -203 );
        vertices[3].Set(20 , 0);

        b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->Set (vertices , 4);

    bodyFixture->shape = polygonShape;
    bodyFixture->density = 0.5;
    bodyFixture->friction = 1.0f;
    bodyFixture->restitution = 0.3f;

    //丟進世界裡
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->CreateFixture(bodyFixture);

}

void Stick::updatePos()
{
    b2Vec2 pos;
    pos = physicBody->GetPosition();
    setPos(MeterToPix_x(pos.x) , MeterToPix_y(pos.y));

    //b2Vec2 vel;
    //vel = physicBody->GetLinearVelocity();

    float angle;
    angle = physicBody->GetAngle();
    setRotation(-RadToDeg(angle));
}
