#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QList>

#include "gy_autotest.h"
#include "gy_objecthandler.h"

#include "kk_scenemanager.h"
#include "koffi/kk_gamelevel.h"
#include "koffi/kk_levelitem.h"
#include "koffi/kk_gamescene.h"
#include "koffi/kk_levelbuilder.h"

SceneManager::SceneManager(QGraphicsScene *scene)
{
    main_scene = new GameScene(scene);
//    object_handler = new ObjectHandler(scene);
    object_handler = NULL;
    set_levels();
}

SceneManager::SceneManager(QGraphicsScene *scene, int demo)
{
    main_scene = new GameScene(scene);
    set_levels();
    init(scene, demo);
}

void SceneManager::init(QGraphicsScene *scene, int demo)
{

    main_scene = new GameScene(scene);
    object_handler = new ObjectHandler(scene);

    // stress
    if(demo == 2) {
        AutoTest * autoTest = new AutoTest(scene);
        return;
    }

    player = new MainPlayer(scene);
    main_scene->addGameObject(player);
    main_scene->setFocus(player);

    // demo
    if(demo == 1) {
        AutoTest * autoTest = new AutoTest(scene, player, this);
    }
}

void SceneManager::play_game(){
    main_scene->setBackground(":/images/back_ground.jpg");
    next_level();
}

void SceneManager::restart_game()
{
//    main_scene->removeGameObject(player);
//    main_scene->removeGameObject(shark);
//    main_scene->removeGameObject(exit);
//    main_scene->removeGameObject(platform);
}

void SceneManager::generate_level(const QString& filename)
{
    GameLevel *gameLevel = new GameLevel(filename);
    QList<LevelItem> *level_items = gameLevel->get_levels_items();
    LevelItem item;
    LevelBuilder *levelBuilder = new LevelBuilder(object_handler);
    for (int i = 0; i < level_items->size(); ++i) {
        item = level_items->at(i);
        levelBuilder->position(item);
    }
}

void SceneManager::next_level()
{
    if(!levels->isEmpty()){
        object_handler->remove_all();
        generate_level(levels->takeFirst());
    }
    else {
        qDebug() << "Maximum number of levels reached!\n";
        // display end game windows
    }
}

MainPlayer* SceneManager::get_player()
{
    return player;
}

void SceneManager::set_levels()
{
    levels->push_back(":/levels/level1.txt");
    levels->push_back(":/levels/level2.txt");
}
