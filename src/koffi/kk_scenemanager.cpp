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
    init(demo);
}

void SceneManager::init(demo)
{

    mainScene = new GameScene(scene);
    player = new Main_player(scene);
    shark = new Shark(100, 50, 30, 30, 10, 0);
    exit = new Exit();
    platform = new Platform();
    mainScene->addGameObject(player);
    mainScene->addGameObject(shark);
    mainScene->addGameObject(exit);
    mainScene->addGameObject(platform);
    mainScene->setFocus(player);
    if(demo == 1) {
        AutoTest * autoTest = new AutoTest(scene, player);
    } else if(demo == 2) {
        AutoTest * autoTest = new AutoTest(scene);
    }
}

void SceneManager::playGame(){
    mainScene->setBackground(":/images/back_ground.jpg");
}

void SceneManager::restartGame()
{
    mainScene->removeGameObject(player);
    mainScene->removeGameObject(shark);
}
