#include "koffi/kk_scenemanager.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

SceneManager::SceneManager(QGraphicsScene *scene)
{
    gameScene = new GameScene(scene);
    shark = new Shark(100, 50, 30, 30, 10, 0);

    player = new Main_player();

    gameScene->addGameObject(shark);
    gameScene->addGameObject(player);
}

void SceneManager::playGame(){

    int sceneHeight = gameScene->height();
    int sceneWidth = gameScene->width();
    QPixmap backgrounImage(":/images/back_ground.jpg");
    gameScene->setBackgroundBrush(backgrounImage.scaled(sceneWidth,
                                         sceneHeight,
                                         Qt::IgnoreAspectRatio,
                                         Qt::SmoothTransformation));
}
