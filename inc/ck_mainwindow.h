#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>

#include "chaeunkim/ck_button.h"
#include "chaeunkim/ck_pausebutton.h"
#include "chaeunkim/ck_pausescreen.h"
#include "kk_scenemanager.h"

class QKeyEvent;

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
    QTimer timer;
    bool isPaused;

    Button *playBtn;
    Button *quitBtn;
    Button *demoBtn;
    Button *stressBtn;

    PauseButton *pauseBtn;

    SceneManager * gamescene;

    PauseScreen * pauseScene;

    void handleKeyPressed(QKeyEvent * event);

protected:
    bool eventFilter(QObject *, QEvent *);

public slots:
    void start();
    void start_demo();
    void start_stress();
    void resume();
    void pause();

};



#endif // MAINWINDOW_H
