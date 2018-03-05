#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QGraphicsPixmapItem>
#include "hh_main_player.h"
#include "gy_object.h"
#include <QGraphicsPathItem>

class Shark;
class Banana;
class Platform;
class Steam;

class Graphics : public QGraphicsPathItem {
public:
    //void load_mainPlayer(Main_player *player);
    Graphics();
    void load_shark (int width,int heigh,Shark *shark);
    void load_shark (Shark *shark);
    void load_banana(Banana *banana);
    void load_banana(int width,int heigh,Banana *banana);
    //void load_platform(Platform *Platform);
    //void load_steam(Steam *steam);

private:
};

#endif // GRAPHICS_H