#include "../../inc/henry/hh_health.h"


Health::Health(int x_pos): QGraphicsRectItem()
{

    new_x_pos = x_pos;
    setRect(0,0, 25, 25);
    setPos(new_x_pos, 10);

}


