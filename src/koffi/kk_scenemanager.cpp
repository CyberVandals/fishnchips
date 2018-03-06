#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

#include "kk_scenemanager.h"
#include "inc/gy_autotest.h"

SceneManager::SceneManager(QGraphicsScene *scene)
{
    mainScene = new GameScene(scene);
}

SceneManager::SceneManager(QGraphicsScene *scene, int demo)
{
    mainScene = new GameScene(scene);
    init(scene, demo);
}

void SceneManager::init(QGraphicsScene *scene, int demo)
{

    mainScene = new GameScene(scene);
    if(demo == 2) {
        AutoTest * autoTest = new AutoTest(scene);
        return;
    }
    player = new Main_player(scene);
    shark = new Shark(30, 30, 10, 0);
    exit = new Exit();
    platform = new Platform();
    mainScene->addGameObject(player);
    mainScene->addGameObject(shark);
    mainScene->addGameObject(exit);
    mainScene->addGameObject(platform);
    mainScene->setFocus(player);

    if(demo == 1) {
        AutoTest * autoTest = new AutoTest(scene, player, this);
    }
}

void SceneManager::playGame(){
    mainScene->setBackground(":/images/back_ground.jpg");
}

void SceneManager::restartGame()
{
    mainScene->removeGameObject(player);
    mainScene->removeGameObject(shark);
    mainScene->removeGameObject(exit);
    mainScene->removeGameObject(platform);
}
