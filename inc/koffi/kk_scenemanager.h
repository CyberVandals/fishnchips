#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "gigiyoung/gy_object.h"
#include "henry/hh_main_player.h"
#include "kk_gamelevel.h"
#include "kk_gamescene.h"

class SceneManager: public QGraphicsView
{
public:
    SceneManager(QGraphicsScene *scene);
    void playGame();
private:
    Shark *shark;
    Main_player *player;
    GameLevel *gameLevel;
    GameScene *gameScene;
};

#endif // SCENEMANAGER_H
