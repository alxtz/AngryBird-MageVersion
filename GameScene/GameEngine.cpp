#include <iostream>
#include <QDebug>
#include <QPointF>
#include "GameEngine.h"

using namespace std;

GameEngine::GameEngine()
{
    leftButtonPressed = false;
}

void GameEngine::keyPressEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
    {
            return;
    }
    if(event->key()==Qt::Key_Q)
    {
        qDebug()<<"you press Q !";
    }
    else if(event->key()==Qt::Key_Space)
    {
        emit useSpecialAbility ();
    }
}

void GameEngine::keyReleaseEvent(QKeyEvent *event)
{
    if(event->isAutoRepeat())
    {
            return;
    }
    if(event->key()==Qt::Key_Q)
    {
        qDebug()<<"you release Q !";
    }
}

void GameEngine::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"you press left !";

        QPointF mousePos;

        mousePos = event->pos();

        cout<<"按的位置為("<<mousePos.x()<<","<<mousePos.y()<<")"<<endl;

        leftButtonPressed = true;

        emit getPullPos (mousePos.x() , mousePos.y() );
    }
}

void GameEngine::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug()<<"you release left !";

        leftButtonPressed = false;

        emit release ();
    }
}

void GameEngine::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(leftButtonPressed == true)
    {
        //qDebug()<<"壓住了左鍵";

        QPointF mousePos;

        mousePos = event->pos();

        //cout<<"位置為("<<mousePos.x()<<","<<mousePos.y()<<")"<<endl;

        emit getPullPos (mousePos.x() , mousePos.y() );
    }
}
