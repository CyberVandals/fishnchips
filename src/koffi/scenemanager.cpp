#include "koffi/scenemanager.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>

SceneManager::SceneManager()
{
    shark = new Shark(100, 50, 30, 30, 10, 0);
    QPixmap sharkGraphic(":/images/blue_shark.png");
    shark->setBrush(QBrush(sharkGraphic.scaled(165,80,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

    player = new Main_player();
    QPixmap playerGraphic(":/images/monkey.png");
    player->setBrush(QBrush(playerGraphic.scaled(80,165,Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
}

void SceneManager::playGame(QGraphicsScene * scene){

    int sceneHeight = scene->height();
    int sceneWidth = scene->width();
    QPixmap pim(":/images/back_ground.jpg");
    scene->setBackgroundBrush(pim.scaled(sceneWidth,sceneHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    scene->addItem(shark);
    scene->addItem(player);
}
