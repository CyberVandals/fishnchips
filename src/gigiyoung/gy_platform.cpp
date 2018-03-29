/* gy_platform.c - Implementation file for platform object
 * By Gigi Young
 */

//#include <QGraphicsRectItem>
#include "../../inc/gy_object.h"


void Platform::init() {
   // sound.loadPlatformSounds(this)
   graphics = new Graphics();

}


// constructors
//Platform::Platform(QGraphicsItem *parent): QGraphicsRectItem(parent) {
Platform::Platform(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    //setRect( DEFAULT_PLAT_POS_X, DEFAULT_PLAT_POS_Y, 
    //         DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 

    init();
    setPos( DEFAULT_PLAT_POS_X, DEFAULT_PLAT_POS_Y );
    graphics->load_platform(DEFAULT_PLAT_WIDTH,DEFAULT_PLAT_HEIGHT,this);
}

Platform::Platform(int x, int y, QGraphicsItem *parent): 
    QGraphicsPixmapItem(parent)
//    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //setRect( pos_x, pos_y, DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 

    init();

    setPos(x, y); 
    graphics->load_platform(DEFAULT_PLAT_WIDTH,DEFAULT_PLAT_HEIGHT,this);
    
}

Platform::Platform(int x, int y, int width, QGraphicsItem *parent):
    QGraphicsPixmapItem(parent)
//    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //setRect( pos_x, pos_y, width, height ); 

    init();

    setPos(x, y); 
    graphics->load_platform( width, DEFAULT_PLAT_HEIGHT,this);
}

