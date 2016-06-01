#include "Stick2_Vtl.h"

Stick2_Vtl::Stick2_Vtl(b2World *inputWorld, int inputX, int inputY)
{
    //基本設定
    setPixmap(QPixmap("./GameData/DefaultResources/Images/stick2_vtl.png"));
    inWorld = inputWorld;
    setPos(inputX , inputY);
    setTransformOriginPoint( 0 , 0);

    //設定stick的itemData
    itemData->objectType =  "Stick";
    itemData->sceneObject = this;
    itemData->bodyObject = physicBody;

    //設定stick的物體結構
    bodyStruct->type = b2_dynamicBody;
    bodyStruct->position.Set( PixToMeter_x(x()) , PixToMeter_y(y()) );
    bodyStruct->angle = 0;

    //設定stick的物體的定製器

        //設定一種形狀(5x100)
        b2Vec2 vertices[4];
        vertices[0].Set(0 , 0);
        vertices[1].Set(0 , -100 );
        vertices[2].Set(5 , -100 );
        vertices[3].Set(5 , 0);

        b2PolygonShape * polygonShape = new b2PolygonShape();
        polygonShape->Set (vertices , 4);

    bodyFixture->shape = polygonShape;
    bodyFixture->density = 5;
    bodyFixture->friction = 1.0f;
    bodyFixture->restitution = 0.3f;

    //丟進世界裡
    physicBody = inWorld->CreateBody(bodyStruct);
    physicBody->SetUserData (itemData);
    physicBody->CreateFixture(bodyFixture);
}
