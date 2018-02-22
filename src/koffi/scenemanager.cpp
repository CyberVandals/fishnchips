#include "koffi/scenemanager.h"
#include <QRect>
#include <QGraphicsPixmapItem>
SceneManager::SceneManager()
{
    QGraphicsPixmapItem *shark = new QGraphicsPathItem();
    shark->setPixmap(QPixmap(":/images/"));
    this->shark = new Shark()
}

void SceneManager::playGame(QGraphicsScene * scene){
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();
    setFixedSize(width/1.5, height/1.1);
    scene->setSceneRect(0,0,width/1.5,height/1.1);
    QPixmap pim(":/images/back_ground.jpg");
    scene->setBackgroundBrush(pim.scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
}