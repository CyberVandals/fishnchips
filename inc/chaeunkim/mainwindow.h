#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "pausebutton.h"
#include "koffi/kk_scenemanager.h"

class MainWindow :public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow();
    void mainmenu();
    QGraphicsScene * scene;
    //Koffisclass* gameplay;
    QGraphicsPixmapItem *logo;
    Button *playBtn;
    Button *quitBtn;
    PauseButton *pauseBtn;
    void gameplay();
public slots:
    void start();

};



#endif // MAINWINDOW_H
