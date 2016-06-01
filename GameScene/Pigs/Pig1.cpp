#include "Pig1.h"

Pig1::Pig1(b2World *inputWorld, int inputX, int inputY)
{
    //基本設定
    setPixmap(QPixmap("./GameData/DefaultResources/Images/pig1.png"));
    inWorld = inputWorld;
    setPos(inputX , inputY);
    setTransformOriginPoint( 0 , 0 );
    objectType = "Pig";

    //設定pig1的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;

    //設定pig1的物體的定製器

        //設定一種形狀(圓形)
        b2CircleShape * circleShape = new b2CircleShape();
        circleShape->m_p.Set(15 , -15);
        circleShape->m_radius = 15;

    bodyFixture->shape = circleShape;
    bodyFixture->density = 0.5;
    bodyFixture->friction = 1.0f;
    bodyFixture->restitution = 0.0f;

    //丟進世界裡
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (&objectType);
    physicBody->CreateFixture(bodyFixture);

    //設定角速度遞減跟線速度遞減
    physicBody->SetAngularDamping(1);
    physicBody->SetLinearDamping(0.07);
}
