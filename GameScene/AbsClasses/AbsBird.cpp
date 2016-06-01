#include <iostream>
#include "AbsBird.h"

using namespace std;

AbsBird::AbsBird()
{

}

void AbsBird::setPullPos(int x, int y)
{
    setPos (x-15 , y-15);
}

void AbsBird::updatePos()
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

void AbsBird::releaseBird(int forceX , int forceY)
{
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );

    //把物體跟定製器加進inWorld裡做運算
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (&objectType);
    physicBody->CreateFixture(bodyFixture);

    //設定鳥受重力的幅度
    physicBody->SetGravityScale(1);

    //設定速度，測試用
    physicBody->SetLinearVelocity(b2Vec2(forceX*3 , forceY*3));

    //設定角速度遞減跟線速度遞減
    physicBody->SetAngularDamping(0.3);
    physicBody->SetLinearDamping(0.07);

    string * objectName = (string*)physicBody->GetUserData ();

    cout<<"物體的名字為"<<*objectName<<endl;
}
