#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "GameView.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0);
        ~MainWindow();

    private:
        GameView * gameView;
};


#endif // MAINWINDOW_H
