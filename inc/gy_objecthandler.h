/*************************************
 * gy_objectihandler.h
 *
 * By Gigi Young
 ************************************/

#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include "gy_object.h"

class ObjectHandler {
public:
    ObjectHandler(QGraphicsScene *scene);

    void add_banana(QGraphicsItem *parent=0);
    void add_banana(int x, int y, QGraphicsItem *parent=0);

    void add_exit(QGraphicsItem *parent=0);
    void add_exit(int x, int y, QGraphicsItem *parent=0);

    void add_platform(QGraphicsItem *parent=0);
    void add_platform(int x, int y, int width, QGraphicsItem *parent=0);

    void add_shark(QGraphicsItem *parent=0);
    void add_shark(int x, int y, QGraphicsItem *parent=0);
    void add_shark(int x, int y, int vel_x, int vel_y, 
                   QGraphicsItem *parent=0);

    void add_steam(QGraphicsItem *parent=0);
    void add_steam(int x, int y, QGraphicsItem *parent=0);

    void pause();
    void resume();

    void remove_all();

private:
    QList<Banana *> banana_list;
    QList<Platform *> platform_list;
    QList<Shark *> shark_list;
    QList<Steam *> steam_list;
    Exit *exit; 

    QGraphicsScene *scene;

};
