#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>

#include "gy_object.h"

#include "hh_main_player.h"


#include "inc/gy_autotest.h"

//#include "inc/koffi/kk_gamelevel.h"
//#include "inc/koffi/kk_gamescene.h"

class GameLevel;

class GameScene;

class ObjectHandler;

class SceneManager: public QGraphicsView
{
public:
    SceneManager(QGraphicsScene *scene);
    SceneManager(QGraphicsScene *scene, int demo);
    void init(QGraphicsScene *scene, int demo);
    void play_game();
    void restart_game();
    void generate_level(const QString& filename);
    Main_player* get_player();
private:
    ObjectHandler *object_handler;
    Main_player *player;
    GameScene *main_scene;
};

#endif // SCENEMANAGER_H
