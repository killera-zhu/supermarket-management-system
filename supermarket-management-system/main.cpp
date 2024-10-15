#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;   //主窗口创建
    w.show();       //主窗口展示
    return a.exec();
}
