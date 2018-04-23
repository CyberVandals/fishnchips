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

private:
    void bring_gameover_scene();

    MainWindow();
    static MainWindow * mainwindow_inst;

    QGraphicsScene * scene;
    QGraphicsPixmapItem *logo;

    MainButton *play_button;
    MainButton *replay_button;
    MainButton *quit_button;
    MainButton *demo_button;
    MainButton *stress_button;

    SceneManager * game_scene;

    SoundManager * background_music;

public:
    void init();
    void display_mainmenu();
    // singleton pattern
    static MainWindow* get_instance() {
        if( mainwindow_inst == NULL ){
            mainwindow_inst = new MainWindow();
        }
        return mainwindow_inst;
    }

public slots:
    void start();
    void restart();
    void start_demo();
    void start_stress();
    void display_gameover();
};



#endif // MAINWINDOW_H
