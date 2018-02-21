/* gy_platform.c - Implementation file for platform object
 * By Gigi Young
 */

#include <QGraphicsRectItem>
#include "../../inc/gigiyoung/gy_object.h"


// constructors
Platform::Platform(QGraphicsItem *parent): QGraphicsRectItem(parent) {
    setRect( DEFAULT_POS_X, DEFAULT_POS_Y, 
             DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 
}

Platform::Platform(int pos_x, int pos_y, 
    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect( pos_x, pos_y, DEFAULT_PLAT_WIDTH, DEFAULT_PLAT_HEIGHT ); 
}

Platform::Platform(int width, int height, int pos_x, int pos_y,
    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect( pos_x, pos_y, width, height ); 
}

