/* gy_platform.c - Implementation file for platform object
 * By Gigi Young
 */

#include <QGraphicsRectItem>
#include "../../inc/gy_object.h"


void Platform::init() {
   // sound.loadPlatformSounds(this)
   graphics = new Graphics();

   graphics->load_platform(this);
}


// constructors
//Platform::Platform(QGraphicsItem *parent): QGraphicsRectItem(parent) {
Platform::Platform(QGraphicsItem *parent): QGraphicsPixmapItem(parent) {
    //setRect( DEFAULT_PLAT_POS_X, DEFAULT_PLAT_POS_Y, 
    //         DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 

    setPos( DEFAULT_PLAT_POS_X, DEFAULT_PLAT_POS_Y );
    init();
}

Platform::Platform(int pos_x, int pos_y, 
    QGraphicsItem *parent): QGraphicsPixmapItem(parent)
//    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //setRect( pos_x, pos_y, DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 
    setPos( pos_x, pos_y ); 
    
    init();
}

Platform::Platform(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QGraphicsPixmapItem(parent)
//    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    //setRect( pos_x, pos_y, width, height ); 
    setPos( pos_x, pos_y ); 

    init();
}

