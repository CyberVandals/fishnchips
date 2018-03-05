#include "inc/koffi/kk_gamescene.h"

GameScene::GameScene(QGraphicsScene *scene)
{
    gameScene = scene;
}

void GameScene::addGameObject(QGraphicsItem *gameObject, QString imagePath, int scaledWidth, int scaledHeight)
{
    QPixmap gameImage(imagePath);
    gameScene->setBackgroundBrush(gameImage.scaled(scaledHeight,scaledHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    gameScene->addItem(gameObject);
}

void GameScene::removeGameObject(QGraphicsItem *gameObject)
{

}
