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

    // remove from scene and deallocate
    for( int i = 0; i < shark_list.size(); i++ ) {
        scene->removeItem(shark_list[i]); 
        delete shark_list[i];
    }

    for( int i = 0; i < steam_list.size(); i++ ) {
        scene->removeItem(steam_list[i]); 
        delete steam_list[i];
    }

    for( int i = 0; i < banana_list.size(); i++ ) {
        scene->removeItem(banana_list[i]);  
        delete banana_list[i];
    }
 
    scene->removeItem(exit);
    if( exit != NULL ) {
        delete exit;
        exit = NULL;
    }

    // clear pointer lists 
    while( !shark_list.isEmpty() ) 
        shark_list.removeLast();

    while( !steam_list.isEmpty() ) 
        steam_list.removeLast();

    while( !banana_list.isEmpty() ) 
        banana_list.removeLast();

    while(!platform_list.isEmpty()) 
        platform_list.removeLast();

}
