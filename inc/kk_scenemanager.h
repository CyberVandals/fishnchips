#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>

#include "gy_object.h"
#include "hh_main_player.h"
#include "inc/koffi/kk_gamelevel.h"
#include "inc/koffi/kk_gamescene.h"

class SceneManager: public QGraphicsView
{
public:
    SceneManager(QGraphicsScene *scene);
    SceneManager(QGraphicsScene *scene, int demo);
    void init(QGraphicsScene *scene, int demo);
    void playGame();
    void restartGame();
    void generateLevel(QString filename);
    Main_player* getMainPlayer();
private:
    Shark *shark;
    Main_player *player;
    GameLevel *gameLevel;
    GameScene *mainScene;
    Exit *exit;
    Platform *platform;
};

#endif // SCENEMANAGER_H
