#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsPixmapItem>
#include "Main_player.h"
#include "gy_object.h"
class Graphics : public QGraphicsPathItem
{
    Q_OBJECT

public:
    //void load_mainPlayer(Main_player *player);
    void load_shark(Shark *shark);
    /*void load_banana(Banana *banana);
    void load_platform(Platform *Platform);
    void load_steam(Steam *steam);
    */
};

#endif // GRAPHICS_H
