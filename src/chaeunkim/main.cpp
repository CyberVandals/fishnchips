#include "mainwindow.h"
#include <QSplashScreen>
#include <QCoreApplication>
#include <QWidget>
#include <QApplication>

MainWindow * mainWin;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    mainWin = new MainWindow();
    mainWin->show();
    mainWin->mainmenu();

    return a.exec();
}

