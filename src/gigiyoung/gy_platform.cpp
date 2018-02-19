/* gy_platform.c - Implementation file for platform object
 * By Gigi Young
 */

#include "gy_object.h"

Platform::Platform(int height, int width, int pos_x, int pos_y,
    QGraphicsItem *parent): QGraphicsRectItem(parent)
{
    setRect(pos_x, pos_y, width, height); 
}
