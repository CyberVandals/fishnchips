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
class Main_player;
class Exit;
class Graphics : public QGraphicsPathItem {
public:
    //void load_mainPlayer(Main_player *player);
    Graphics();
    void load_mainplayer(Main_player *main_player);
    void load_mainplayer(int width,int heigh,Main_player *main_player);
    void load_mainplayer();
    void load_shark (int width,int heigh,Shark *shark, bool left, bool righ);
    void load_shark (Shark *shark);
    //void shark_flip(Shark *shark, bool horizontal, bool vertical);
    void load_banana(Banana *banana);
    void load_banana(int width,int heigh,Banana *banana);
    void load_platform(Platform *platform);
    void load_platform(int width,int heigh,Platform *platform);
    void load_steam(Steam *steam);
    void load_steam(int width,int heigh,Steam *steam);
    void load_exit_door(Exit *exit_door);
    void load_exit_door(int width,int heigh,Exit *exit_door);
private:
};

#endif // GRAPHICS_H
