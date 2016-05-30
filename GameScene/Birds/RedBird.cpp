#include "RedBird.h"

RedBird::RedBird(b2World * inputWorld)
{
    //基本設定
    setPos(0 , 300);
    inWorld = inputWorld;
    setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/redBird.png"));
    setTransformOriginPoint(0 , 0);

    //設定鳥的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0 ;

    //設定鳥的物體的定製器

        //設定一種形狀
        b2CircleShape * circleShape = new b2CircleShape();
        circleShape->m_p.Set(15 , -15);
        circleShape->m_radius = 15 ;

    bodyFixture->shape = circleShape ;
    bodyFixture->density = 1;
    bodyFixture->friction = 1.0f ;
    bodyFixture->restitution = 0.75f;

    /*
    //把物體跟定製器加進inWorld裡做運算
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->CreateFixture(bodyFixture);

    //設定鳥受重力的幅度
    physicBody->SetGravityScale(1);

    //設定速度，測試用
    //physicBody->SetLinearVelocity(b2Vec2(300 , 100));

    //設定角速度遞減跟線速度遞減
    physicBody->SetAngularDamping(0.3);
    physicBody->SetLinearDamping(0.07);
    */
}
