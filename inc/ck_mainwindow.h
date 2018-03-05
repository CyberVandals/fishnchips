#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "inc/chaeunkim/ck_button.h"
#include "inc/chaeunkim/ck_pausebutton.h"
#include "inc/koffi/kk_scenemanager.h"

class MainWindow :public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow();
    void mainmenu();
    void gameplay();
private:
    QGraphicsScene * scene;
    QGraphicsPixmapItem *logo;
    Button *playBtn;
    Button *quitBtn;
    PauseButton *pauseBtn;
public slots:
    void start();

};



#endif // MAINWINDOW_H
