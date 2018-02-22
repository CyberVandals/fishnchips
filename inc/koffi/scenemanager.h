#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "gigiyoung/gy_object.h"
#include "henry/hh_main_player.h"

class SceneManager: public QGraphicsView
{
public:
    SceneManager();
    void playGame(QGraphicsScene * scene);
private:
    Shark *shark;
    Main_player *player;
};

#endif // SCENEMANAGER_H
