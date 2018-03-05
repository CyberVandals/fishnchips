#include "koffi/scenemanager.h"
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

SceneManager::SceneManager()
{
    shark = new Shark(100, 50, 30, 30, 10, 0);

    player = new Main_player();
}

void SceneManager::playGame(QGraphicsScene * scene){

    int sceneHeight = scene->height();
    int sceneWidth = scene->width();
    QPixmap pim(":/images/back_ground.jpg");
    scene->setBackgroundBrush(pim.scaled(sceneWidth,sceneHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    scene->addItem(shark);
    scene->addItem(player);
    scene->setFocusItem(player);
}
