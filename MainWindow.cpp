#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
 : QMainWindow(parent)
{
    setFixedSize(1202 , 602);

    gameView = new GameView(this);

}

MainWindow::~MainWindow()
{

}
