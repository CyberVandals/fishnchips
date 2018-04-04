/****************************************
 * gy_abstract.cpp
 *
 * By Gigi Young
 ***************************************/

#include "../../inc/gigiyoung/gy_abstract.h"

AbstractObject::AbstractObject(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    timer = NULL;
    graphics = NULL;
    sound = NULL;
}
