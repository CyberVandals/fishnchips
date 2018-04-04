/*************************************
 * gy_steam.cpp
 * 
 * By Gigi Young
 ************************************/

#include <stdlib.h>
#include "../../inc/gy_object.h"


// Default constructor 
Steam::Steam(QGraphicsItem *parent): AbstractObject(parent) {
    init();
    setPos(DEFAULT_POS_X, DEFAULT_POS_Y);
    timer->start(UPDATE_MS);
}

Steam::Steam(int x, int y, QGraphicsItem *parent): 
    AbstractObject(parent)
{
    init();
    setPos(x, y);
    timer->start(UPDATE_MS);
} 

void Steam::init() {

    is_active = false;
    time_active = 20 + rand() % 60;
    count = time_active;

    timer = new QTimer(this);
    graphics = new Graphics();
    sound = new SoundManager();

    graphics->load_steam(
        DEFAULT_STEAM_WIDTH, DEFAULT_STEAM_HEIGHT, this);

    // create timer for move slot
    connect(timer, SIGNAL(timeout()), this, SLOT(status()));
}

void Steam::pause() {
    if(timer != NULL)
        timer->stop();
}

void Steam::resume() {
    if(timer != NULL)
        timer->start();
}

bool Steam::active() {
    return is_active;
}

void Steam::status() {
    if(count > 0) {
        count--;
    }
    else {
        is_active = !is_active;
        count = time_active;
    }

    if(is_active) {
        // make object visible
        this->setVisible(true);
    }
    else {
        // make invisible
        this->setVisible(false);
    }
}
