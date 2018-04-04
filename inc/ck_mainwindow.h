/********************************
 *     MainWindow.h
 *     Chaeun Kim
 ********************************/

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


class MainWindow :public QGraphicsView {
    Q_OBJECT
public:
    MainWindow();
    void mainmenu();
    void gameplay();

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

    int WID_WIDTH;
    int WID_HEI;

public slots:
    void start();
    void restart();
    void start_demo();
    void start_stress();
    void display_gameover();
};



#endif // MAINWINDOW_H
