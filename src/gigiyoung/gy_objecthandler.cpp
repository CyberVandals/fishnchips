/********************************* 
 * gy_objecthandler.cpp
 *
 * By Gigi Young
 ********************************/

#include "../../inc/gy_objecthandler.h"

ObjectHandler::ObjectHandler(QGraphicsScene *scene) {
    this->scene = scene;
    exit = NULL;
}

// Banana
void ObjectHandler::add_banana(QGraphicsItem *parent) {
    Banana *obj = new Banana(parent);
    scene->addItem(obj);
    banana_list.append(obj);
}

void ObjectHandler::add_banana(int x, int y, QGraphicsItem *parent) {
    Banana *obj = new Banana(x, y, parent);
    scene->addItem(obj);
    banana_list.append(obj);
}

// Exit
void ObjectHandler::add_exit(QGraphicsItem *parent) {
    if(exit == NULL) {
        exit = new Exit(parent);
        scene->addItem(exit);
    }
}

void ObjectHandler::add_exit(int x, int y, QGraphicsItem *parent) {
    if(exit == NULL) {
        exit = new Exit(x, y, parent);
        scene->addItem(exit);
    }
}

// Platform
void ObjectHandler::add_platform(QGraphicsItem *parent) {
    Platform *obj = new Platform(parent);
    scene->addItem(obj);
    platform_list.append(obj);
}

void ObjectHandler::add_platform(int x, int y, QGraphicsItem *parent)
{
    Platform *obj = new Platform(x, y, DEFAULT_PLAT_WIDTH, parent);
    scene->addItem(obj);
    platform_list.append(obj);
}


void ObjectHandler::add_platform(int x, int y, int width, 
    QGraphicsItem *parent)
{
    Platform *obj = new Platform(x, y, width, parent);
    scene->addItem(obj);
    platform_list.append(obj);
}

// Shark
void ObjectHandler::add_shark(QGraphicsItem *parent) {
    Shark *obj = new Shark(parent);
    scene->addItem(obj);
    shark_list.append(obj);
}

void ObjectHandler::add_shark(int x, int y, QGraphicsItem *parent) {
    Shark *obj = new Shark(x, y, parent);
    scene->addItem(obj);
    shark_list.append(obj);
}

void ObjectHandler::add_shark(int x, int y, int vel_x, int vel_y, 
    QGraphicsItem *parent) 
{
    Shark *obj = new Shark(x, y, vel_x, vel_y, parent);
    scene->addItem(obj);
    shark_list.append(obj);
}

// Steam
void ObjectHandler::add_steam(QGraphicsItem *parent) {
    Steam *obj = new Steam(parent);
    scene->addItem(obj);
    steam_list.append(obj);
}

void ObjectHandler::add_steam(int x, int y, QGraphicsItem *parent) {
    Steam *obj = new Steam(x, y, parent);
    scene->addItem(obj);
    steam_list.append(obj);
}

/* Pause objects that use QTimer (banana, shark, steam, and exit)
 */
void ObjectHandler::pause() {

    for( int i = 0; i < shark_list.size(); i++ ) 
        shark_list[i]->pause(); 

    for( int i = 0; i < steam_list.size(); i++ ) 
        steam_list[i]->pause(); 

    for( int i = 0; i < banana_list.size(); i++ ) 
        banana_list[i]->pause(); 
 
    exit->pause();
}

void ObjectHandler::resume() {

    for( int i = 0; i < shark_list.size(); i++ ) 
        shark_list[i]->resume(); 

    for( int i = 0; i < steam_list.size(); i++ ) 
        steam_list[i]->resume(); 

    for( int i = 0; i < banana_list.size(); i++ ) 
        banana_list[i]->resume(); 
 
    exit->resume();

}

void ObjectHandler::remove_all() {

    // platforms
    for( int i = 0; i < platform_list.size(); i++ ) {
        if( platform_list[i] != NULL ) {
            scene->removeItem(platform_list[i]); 
            delete platform_list[i];
            platform_list[i] = NULL;
        }
    }
    while( !platform_list.isEmpty() ) 
        platform_list.removeLast();

    // sharks
    for( int i = 0; i < shark_list.size(); i++ ) {
        if( shark_list[i] != NULL ) {
            scene->removeItem(shark_list[i]); 
            delete shark_list[i];
            shark_list[i] = NULL;
        }
    }
    while( !shark_list.isEmpty() ) 
        shark_list.removeLast();

    // steam
    for( int i = 0; i < steam_list.size(); i++ ) {
        if( steam_list[i] != NULL ) {
            scene->removeItem(steam_list[i]); 
            delete steam_list[i];
            steam_list[i] = NULL;
        }
    }
    while( !steam_list.isEmpty() ) 
        steam_list.removeLast();

    // banana
    for( int i = 0; i < banana_list.size(); i++ ) {
        if( banana_list[i] != NULL ) {
            scene->removeItem(banana_list[i]);  
            delete banana_list[i];
            banana_list[i] = NULL;
        }
    }
    while( !banana_list.isEmpty() ) 
        banana_list.removeLast();

    // exit
    if( exit != NULL ) {
        scene->removeItem(exit);
        delete exit;
        exit = NULL;
    }
}
