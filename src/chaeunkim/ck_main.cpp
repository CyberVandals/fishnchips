#include "../../inc/ck_mainwindow.h"
#include <QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Add Splash Screen
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/icon_shark.png"));
    splash->show();
    QTimer::singleShot(2000,splash,SLOT(close()));

    MainWindow * mainWin;
    mainWin = new MainWindow();
    QTimer::singleShot(2300,mainWin,SLOT(show()));
    mainWin->mainmenu();

    return a.exec();
}

