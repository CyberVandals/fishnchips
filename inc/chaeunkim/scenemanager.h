#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "mainwindow.h"

class SceneManager :public QGraphicsView
{
public:
    SceneManager();
    void playGame(QGraphicsScene * scene);

};

#endif // SCENEMANAGER_H
