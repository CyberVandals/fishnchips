/* gy_shark.c - Implementation file for shark object
 * By Gigi Young
 */

#include <typeinfo>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include "gy_object.h"

using namespace std;

Shark::Shark(int height, int width, int pos_x, int pos_y, int vel_x, int vel_y,
    QGraphicsItem *parent=0): QObject(), QGraphicsRectItem(parent)
{
    // init size and position
    setRect( pos_x, pos_y, width, height );

    // init velocity
    vel.x = vel_x;
    vel.y = vel_y;    

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}

void Shark::move() {
    QList<QGraphicsItem *> colliding_items = 
        collidingItems(Qt::IntersectsItemShape);

    // if collision with platform, invert x velocity
    if( int i = 0; i < colliding_items.size() ; i++ ) {
        if( typeid( *(colliding_items[i]) ) == typeid(Platform) )
            vel.x = -vel.x; 
    }

    // update position
    setPos( x()+vel.x, y()+vel.y );
}

