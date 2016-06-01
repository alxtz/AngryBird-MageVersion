#include "Block_Vtl.h"

Block_Vtl::Block_Vtl(b2World *inputWorld, int inputX, int inputY)
{
    //基本設定
    setPixmap(QPixmap("./GameData/DefaultResources/Images/block_vtl.png"));
    inWorld = inputWorld;
    setPos(inputX , inputY);
    setTransformOriginPoint( 0 , 0);
    objectType = "Block";

    //設定block的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;

    //設定stick的物體的定製器

        //設定一種形狀(12x25)
        b2Vec2 vertices[4];
        vertices[0].Set(0 , 0);
        vertices[1].Set(0 , -25 );
        vertices[2].Set(12 , -25 );
        vertices[3].Set(12 , 0);

        b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->Set (vertices , 4);

    bodyFixture->shape = polygonShape;
    bodyFixture->density = 5;
    bodyFixture->friction = 1.0f;
    bodyFixture->restitution = 0.3f;

    //丟進世界裡
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (&objectType);
    physicBody->CreateFixture(bodyFixture);
}
