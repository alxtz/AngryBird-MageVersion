#include "GameView.h"

GameView::GameView(QWidget * parent)
 : QGraphicsView(parent)
{
    setFixedSize(1202 , 602);

    //設定scene
    gameScene = new GameScene();
    setScene (gameScene);

}
