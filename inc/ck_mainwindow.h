#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "chaeunkim/ck_button.h"
#include "chaeunkim/ck_pausebutton.h"
#include "kk_scenemanager.h"

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
