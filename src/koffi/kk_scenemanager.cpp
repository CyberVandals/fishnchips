#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

#include "kk_scenemanager.h"
#include "inc/gy_autotest.h"

SceneManager::SceneManager(QGraphicsScene *scene)
{
    gameScene = new GameScene(scene);
    player = new Main_player(scene);
    shark = new Shark(100, 50, 30, 30, 10, 0);

    gameScene->addGameObject(player, ":/images/monkey.png", 165,80);
    gameScene->addGameObject(shark, ":/images/blue_shark.png", 65, 100);
    gameScene->setFocus(player);

}

SceneManager::SceneManager(QGraphicsScene *scene, bool demo)
{
    gameScene = new GameScene(scene);
    player = new Main_player(scene);
    gameScene->addGameObject(player, ":/images/monkey.png", 165,80);
    gameScene->setFocus(player);

    if(demo) {
        AutoTest * autoTest = new AutoTest(scene, player);
    }
    shark = new Shark(100, 50, 30, 30, 10, 0);
    gameScene->addGameObject(shark, ":/images/blue_shark.png", 65, 100);
}

void SceneManager::playGame(){
    gameScene->setBackground(":/images/back_ground.jpg");
}
