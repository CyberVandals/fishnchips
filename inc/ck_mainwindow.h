#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
<<<<<<< HEAD:inc/chaeunkim/mainwindow.h
#include "button.h"
#include "pausebutton.h"
#include "koffi/kk_scenemanager.h"
=======
#include "inc/chaeunkim/ck_button.h"
#include "inc/chaeunkim/ck_pausebutton.h"
#include "inc/koffi/kk_scenemanager.h"
>>>>>>> 09602f33e53d16bdf61e18c4a92d3a1bfe25244f:inc/ck_mainwindow.h

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
