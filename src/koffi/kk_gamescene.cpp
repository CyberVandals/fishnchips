#include "inc/koffi/kk_gamescene.h"

GameScene::GameScene(QGraphicsScene *scene)
{
    gameScene = scene;
}

void GameScene::addGameObject(QGraphicsItem *gameObject)
{
    gameScene->addItem(gameObject);
}

void GameScene::removeGameObject(QGraphicsItem *gameObject)
{

}
