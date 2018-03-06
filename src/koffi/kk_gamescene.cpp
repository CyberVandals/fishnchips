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

void GameScene::addGameObject(QGraphicsItem *gameObject)
{
    gameScene->addItem(gameObject);
}

void GameScene::removeGameObject(QGraphicsItem *gameObject)
{
    gameScene->removeItem(gameObject);
    gameObject = NULL;
    delete gameObject;
}

void GameScene::setBackground(QString imagePath)
{
    int sceneHeight = gameScene->height();
    int sceneWidth = gameScene->width();

    QPixmap backgroundImage(imagePath);
    gameScene->setBackgroundBrush(backgroundImage.scaled(sceneWidth,
                                         sceneHeight,
                                         Qt::IgnoreAspectRatio,
                                                         Qt::SmoothTransformation));
}

void GameScene::setFocus(QGraphicsItem *gameObject)
{
    gameScene->setFocusItem(gameObject);
}
