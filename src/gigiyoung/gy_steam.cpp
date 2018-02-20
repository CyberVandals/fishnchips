/* gy_steam.c - Implemention file for steam object
 * By Gigi Young
 */

#include <stdlib.h>
#include "../../inc/gigiyoung/gy_object.h"

using namespace std;

// Default constructor 
Steam::Steam(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    countdown = rand() % 60;

    // init size and position
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, DEFAULT_STEAM_WIDTH,
             DEFAULT_STEAM_HEIGHT );

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}


// Constructor with position 
Steam::Steam(int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    countdown = rand() % 60;

    // init size and position
    setRect( pos_x, pos_y, DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT );

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
} 

// Constructor with position and velocity 
Steam::Steam(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent)
{
    countdown = rand() % 60;

    // init size and position
    setRect( pos_x, pos_y, width, height );

    // create timer for move slot
    timer = new QTimer(this);
    connect( timer, SIGNAL(timeout()), this, SLOT(move()) );
    timer->start(UPDATE_MS);
}


void Steam::status() {

}
