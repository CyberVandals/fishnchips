#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QRect>

#include "gigiyoung/gy_object.h"

class SceneManager: public QGraphicsView
{
public:
    SceneManager();
    void playGame(QGraphicsScene * scene);
private:
    Shark *shark;
    QRect *rect;
};

#endif // SCENEMANAGER_H
