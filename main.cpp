#include <QApplication>
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();


    return a.exec();
}


//main暫時都不會改
