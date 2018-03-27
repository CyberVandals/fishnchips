/* gy_steam.cpp - Implemention file for steam object
 * By Gigi Young
 */

#include <stdlib.h>
#include "../../inc/gy_object.h"

using namespace std;

// Default constructor 
Steam::Steam(QGraphicsItem *parent): AbstractObject(parent) {
    init();

    setPos(DEFAULT_POS_X, DEFAULT_POS_Y);
    //graphics->load_steam(
    //    DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT, this);

    timer->start(UPDATE_MS);
}


// Constructor with position 
//Steam::Steam(int pos_x, int pos_y,
//    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
Steam::Steam(int x, int y, QGraphicsItem *parent): 
    AbstractObject(parent)
{
    init();

    setPos(x, y);
    //graphics->load_steam(
    //    DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT, this);

    timer->start(UPDATE_MS);
} 

/*
// Constructor with position and velocity 
Steam::Steam(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    init();
    setPos( pos_x, pos_y );

    graphics->load_steam(width, height, this);

    timer->start(UPDATE_MS);
}
*/

void Steam::init() {

    countdown = rand() % 60;

    timer = new QTimer(this);
    graphics = new Graphics();
    sound = new SoundManager();

    graphics->load_steam(
        DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT, this);

    // create timer for move slot
    connect( timer, SIGNAL(timeout()), this, SLOT(status()) );
}

void Steam::pause() {

}

void Steam::status() {
    if(countdown > 0) {
        countdown--;
    }
    else 
        exploded = true;

    if(exploded) {
        // make object visible
    }
    else {
        // make invisible
    }


}
