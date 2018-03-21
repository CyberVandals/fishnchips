/* gy_gameobject.h
 * Gigi Young
 */

#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include "gy_object.h"

class GameObjectHandler: public QObject {
    Q_OBJECT
public:
    GameObjectHandler(QObject *parent=0);

    //bool pause();
    
    //bool add_banana();
    //bool add_exit();
    //bool add_platform();
    //bool add_shark();
    //bool add_steam();

private:
    QList<Banana *> banana_list;
    QList<Platform *> platform_list;
    QList<Shark *> shark_list;
    QList<Steam *>  team_list;
    Exit *exit; 

    QGraphicsScene *scene;

};
