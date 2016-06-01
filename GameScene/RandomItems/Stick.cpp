#include <iostream>
#include "Stick.h"

using namespace std;

Stick::Stick(b2World * inputWorld , int inputX , int inputY)
{
    //基本設定
    setPixmap(QPixmap("./GameData/DefaultResources/Images/stick.png"));
    inWorld = inputWorld;
    setPos(inputX , inputY);
    setTransformOriginPoint(0 , 0);
    objectType = "Stick";

    //設定鳥的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;

    //設定鳥的物體的定製器

        //設定一種形狀(20x203)
        b2Vec2 vertices[4];
        vertices[0].Set(0 , 0);
        vertices[1].Set(0 , -50 );
        vertices[2].Set(5 , -50 );
        vertices[3].Set(5 , 0);

        b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->Set (vertices , 4);

    bodyFixture->shape = polygonShape;
    bodyFixture->density = 0.5;
    bodyFixture->friction = 1.0f;
    bodyFixture->restitution = 0.3f;

    //丟進世界裡
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (&objectType);
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
