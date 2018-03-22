#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include "mm_soundmanager.h"

#include "chaeunkim/ck_button.h"
#include "chaeunkim/ck_pausebutton.h"
#include "chaeunkim/ck_pausescreen.h"
#include "kk_scenemanager.h"


class MainWindow :public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow();
    void mainmenu();
    void gameplay();

private:
    void bringGameOverScene();
    QGraphicsScene * scene;
    QGraphicsPixmapItem *logo;

    Button *playBtn;
    Button *replayBtn;
    Button *quitBtn;
    Button *demoBtn;
    Button *stressBtn;

    SceneManager * gamescene;

    SoundManager * backgroundMusic;

    int WID_WIDTH;
    int WID_HEI;

public slots:
    void start();
    void start_demo();
    void start_stress();
    void displayGameover();
};



#endif // MAINWINDOW_H
