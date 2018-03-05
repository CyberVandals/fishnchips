#include "inc/koffi/kk_gamescene.h"

GameScene::GameScene(QGraphicsScene *scene)
{
    gameScene = scene;
}

void GameScene::addGameObject(QGraphicsItem *gameObject, imagePath, scaledWidth, scaledWidth)
{
    QPixmap gameImage(imagePath);
    gameScene->setBackgroundBrush(gameImage.scaled(scaledWidth,scaledWidth,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gameScene->addItem(gameObject);
}

void GameScene::removeGameObject(QGraphicsItem *gameObject)
{

}
