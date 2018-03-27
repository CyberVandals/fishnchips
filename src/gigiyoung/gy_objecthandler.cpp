/* gy_objecthandler.cpp
 * Gigi Young
 */

#include "../../inc/gy_objecthandler.h"

//GameObjectHandler::GameObjectHandler(QObject *parent): QObject(parent) {
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

void ObjectHandler::pause() {

}
