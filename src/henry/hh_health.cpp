#include "../../inc/henry/hh_health.h"


Health::Health(int x, int y,QGraphicsRectItem * parent): QGraphicsRectItem(parent)
{
    setRect(x,y, 50, 50);
    //Health * new_health = new Health(this);
}


