#include "RedBird.h"

RedBird::RedBird(b2World * inputWorld)
{
    //基本設定
    setPos(100 , 400);
    inWorld = inputWorld;
    setPixmap(QPixmap("./GameData/DefaultResources/Images/BirdImages/redBird.png"));
    setTransformOriginPoint(0 , 0);
    //ObjectType = new string("Bird");
    objectType = "Bird";

    //設定鳥的physicBody

    //設定鳥的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0 ;

    //設定鳥的物體的定製器

        //設定一種形狀
        b2CircleShape * circleShape = new b2CircleShape();
        circleShape->m_p.Set(15 , -14);
        circleShape->m_radius = 15 ;

    bodyFixture->shape = circleShape ;
    bodyFixture->density = 1;
    bodyFixture->friction = 1.0f ;
    bodyFixture->restitution = 0.75f;

    //把物體跟定製器加進inWorld裡做運算
    //physicBody = inWorld->CreateBody(bodyStruct);
    //physicBody->SetUserData ( ObjectType );
}
