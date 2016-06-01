#include <iostream>
#include "CollisionListener.h"

using namespace std;

CollisionListener::CollisionListener()
{
    //可以等物體都放置好再開啟碰撞監控的功能
}

void CollisionListener::BeginContact(b2Contact *contact)
{
    //cout<<"物體接觸"<<endl;

    //得知了物體碰撞，現在要過濾出碰撞的物體是否是我們想要的
    b2Fixture * contactItemA = contact->GetFixtureA ();
    b2Fixture * contactItemB = contact->GetFixtureB ();

    string * objectTypeA = (string*)contactItemA->GetBody ()->GetUserData ();
    string * objectTypeB = (string*)contactItemB->GetBody ()->GetUserData ();
    //cout<<"物體的typeA為"<<*objectTypeA<<endl;
    //cout<<"物體的typeB為"<<*objectTypeB<<endl;

    if( (*objectTypeA=="Bird" && *objectTypeB=="Stick") || (*objectTypeB=="Bird" && *objectTypeA=="Stick") )
    {
        cout<<"棍子撞鳥事件"<<endl;
    }
}

void CollisionListener::EndContact(b2Contact *contact)
{
    //cout<<"物體離開"<<endl;
}

void CollisionListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{

}

void CollisionListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{

}
