#include "../../inc/henry/hh_health.h"


Health::Health(int x, int y, int id, QGraphicsRectItem * parent): QGraphicsRectItem(parent)
{
    setRect(x,y, 50, 50);
    this->ID = id;
    //Health * new_health = new Health(this);
}


