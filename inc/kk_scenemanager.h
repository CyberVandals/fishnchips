#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QList>

#include "gy_object.h"

#include "hh_main_player.h"


#include "inc/gy_autotest.h"

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
    void next_level();
    MainPlayer* get_player();
private:
    int level_number;

    void set_levels();
    ObjectHandler *object_handler;
    MainPlayer *player;
    GameScene *main_scene;
    QList<QString> *levels = new QList<QString>();
};

#endif // SCENEMANAGER_H
