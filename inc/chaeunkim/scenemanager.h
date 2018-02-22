#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "mainwindow.h"
#include "../../inc/gigiyoung/gy_object.h"

class SceneManager :public QGraphicsView
{
public:
    SceneManager();
    void playGame(QGraphicsScene * scene);
    void addObjects();
    Shark * shark;

};

#endif // SCENEMANAGER_H
