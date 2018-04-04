/*****************************************
 * gy_exit.c 
 *
 * By Gigi Young
 ****************************************/

#include "../../inc/gy_object.h"

Exit::Exit(QGraphicsItem *parent): AbstractObject(parent) {
    init();
    setPos(DEFAULT_EXIT_POS_X, DEFAULT_EXIT_POS_Y); 
    timer->start(UPDATE_MS);
}


Exit::Exit(int x, int y, QGraphicsItem *parent):
    AbstractObject(parent)
{
    init();
    setPos(x, y); 
    timer->start(UPDATE_MS);
}


void Exit::init() {
    timer = new QTimer(this);
    graphics = new Graphics(); 
    sound = new SoundManager();

    graphics->load_exit_door(
        DEFAULT_EXIT_WIDTH, DEFAULT_EXIT_HEIGHT, this);

    connect(timer, SIGNAL(timeout()), this, SLOT(status()));
}

void Exit::pause() {
    if( timer != NULL )
        timer->stop();
}

void Exit::resume() {
    if( timer != NULL )
        timer->start();
}

void Exit::status() {

}
