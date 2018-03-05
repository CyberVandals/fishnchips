#ifndef HH_HEALTH_H
#define HH_HEALTH_H

#include <QGraphicsRectItem>

class Health: public QGraphicsRectItem
{
private:
    int height, width;

public:
    Health(int x_pos);
    int x_pos;




};

#endif // HH_HEALTH_H
