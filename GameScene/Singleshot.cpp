#include <iostream>
#include <cstdlib>
#include <cmath>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QPixmap>
#include "Singleshot.h"

using namespace std;

Singleshot::Singleshot()
{
    hasBird = true;

    isShortening = false;

    shortenTimer = new QTimer();

    singleshotPic = new QGraphicsPixmapItem(this);
    singleshotPic->setPixmap(QPixmap("./GameData/DefaultResources/Images/singleshot.png"));

    setPos(100 , 410);
    setZValue (0);

    //設定橡皮筋1 , 2的轉動點
    int rubberBand1OriginX = 5;
    int rubberBand1OriginY = 4;

    int rubberBand2OriginX = 5;
    int rubberBand2OriginY = 4;

    //設定橡皮筋
    QPen * pen = new QPen(Qt::NoPen);

        //設定橡皮筋1
        rubberBand1 = new QGraphicsRectItem(this);
        rubberBand1->setTransformOriginPoint (rubberBand1OriginX , rubberBand1OriginY);

        rubberBand1->setRect (0 , 0 , 0 , 0);
        rubberBand1->setBrush(QColor(51 , 17 , 0));
        rubberBand1->setPen(*pen);
        rubberBand1->setPos(2 , 14);
        rubberBand1->setRotation (240);
        rubberBand1->setZValue (-10);

        //設定橡皮筋2
        rubberBand2 = new QGraphicsRectItem(this);
        rubberBand2->setTransformOriginPoint (rubberBand2OriginX , rubberBand2OriginY);

        rubberBand2->setRect (0 , 0 , 0 , 0);
        rubberBand2->setBrush(QColor(51 , 17 , 0));
        rubberBand2->setPen(*pen);
        rubberBand2->setPos(24 , 15);
        rubberBand2->setRotation (0);
        rubberBand2->setZValue (-10);




    realTransformOriginX1 = pos ().x () + rubberBand1->x() + rubberBand1OriginX;
    realTransformOriginY1 = pos ().y () + rubberBand1->y() + rubberBand1OriginY;

    realTransformOriginX2 = pos ().x () + rubberBand2->x() + rubberBand2OriginX;
    realTransformOriginY2 = pos ().y () + rubberBand2->y() + rubberBand2OriginY;

}

void Singleshot::pull(int x, int y)
{
    if(isShortening==true)
    {
        return;
    }

    //cout<<"realTransformOriginX1-x"<<realTransformOriginX1-x<<endl;
    if((x-realTransformOriginX1)>0)
    {
        rubberBand1->setZValue (10);
        rubberBand2->setZValue (10);
    }
    else
    {
        rubberBand1->setZValue (-10);
        rubberBand2->setZValue (-10);
    }

    //設定拉力
    forceX = realTransformOriginX1 - x;
    forceY = y - realTransformOriginY1;

    //設定長度1
    int absX = abs(x - realTransformOriginX1) , absY= abs(y - realTransformOriginY1);

    double directLength = sqrt(absX*absX + absY*absY);

    rubberBand1->setRect (0 , 0 , directLength +10 , 8);

    double rad;

    int fooY = realTransformOriginY1 -y;
    int fooX = x - realTransformOriginX1;

    rad = atan((double)fooY/fooX);

    double deg = rad * 180 / 3.1415926;

    if(fooX<0)
    {
        deg+=180;
    }

    rubberBand1->setRotation (-deg);

    //設定長度2
    absX = abs(x - realTransformOriginX2) , absY= abs(y - realTransformOriginY2);
    directLength = sqrt(absX*absX + absY*absY);

    rubberBand2->setRect (0 , 0 , directLength +10 , 7);

    fooY = realTransformOriginY2 -y;
    fooX = x - realTransformOriginX2;

    rad = atan((double)fooY/fooX);

    deg = rad * 180 / 3.1415926;

    if(fooX<0)
    {
        deg+=180;
    }

    rubberBand2->setRotation (-deg);
}

void Singleshot::release()
{
    hasBird = false;
    isShortening = true;

    cout<<"called release"<<endl;
    if(shortenTimer->isActive ()==false)
    {
        cout<<"called release when stop"<<endl;
        shortenTimer->start (17);
        connect(shortenTimer , SIGNAL(timeout()) , this , SLOT(shorten()));
    }
}

void Singleshot::shorten()
{
    cout<<"shorten"<<endl;
    int RB1length = rubberBand1->rect ().width ();

    rubberBand1->setRect (0 , 0 , RB1length - (float)RB1length/25 , 8);

    int RB2length = rubberBand2->rect ().width ();
    rubberBand2->setRect (0 , 0 , RB2length - (float)RB2length/25 , 8);

    if(RB2length<10&&RB2length<10)
    {
        shortenTimer->stop();
        cout<<"stops"<<endl;
        isShortening = false;
        if(hasBird==false)
        {
            emit setNewBird ();
            hasBird = true;
        }
    }
}
