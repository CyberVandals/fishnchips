/********************************
 *     MainWindow.h
 *     Chaeun Kim
 ********************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define WID_HEI 700
#define WID_WIDTH 950

#include <QGraphicsScene>
#include <QGraphicsView>

#include "mm_soundmanager.h"
#include "chaeunkim/ck_button.h"
#include "chaeunkim/ck_pausebutton.h"
#include "chaeunkim/ck_pausescreen.h"
#include "kk_scenemanager.h"


class MainWindow :public QGraphicsView {
    Q_OBJECT
public:
    MainWindow();
    void display_mainmenu();

private:
    void bring_gameover_scene();

    QGraphicsScene * scene;
    QGraphicsPixmapItem *logo;

    Button *play_button;
    Button *replay_button;
    Button *quit_button;
    Button *demo_button;
    Button *stress_button;

    SceneManager * game_scene;

    SoundManager * background_music;

public slots:
    void start();
    void restart();
    void start_demo();
    void start_stress();
    void display_gameover();
};



#endif // MAINWINDOW_H
