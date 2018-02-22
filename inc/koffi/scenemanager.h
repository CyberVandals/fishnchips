#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "gigiyoung/gy_object.h"

class SceneManager: public QGraphicsView
{
public:
    SceneManager();
    void playGame(QGraphicsScene * scene);
private:
    Shark *shark;
};

#endif // SCENEMANAGER_H
