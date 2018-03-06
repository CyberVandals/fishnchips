#ifndef HH_HEALTH_H
#define HH_HEALTH_H

#include <QGraphicsRectItem>
#include <QGraphicsView>

class Health: public QGraphicsRectItem
{
private:
    int height, width;
    //int new_x_pos;

public:
    Health(int x_pos);
    int new_x_pos;



};

#endif // HH_HEALTH_H
