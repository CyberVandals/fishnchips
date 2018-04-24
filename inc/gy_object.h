/******************************************** 
 * gy_object.h - Interface for game objects
 *
 * By Gigi Young
 *******************************************/

#ifndef GY_OBJECT_H
#define GY_OBJECT_H

#include "wz_graphics.h"
#include "mm_soundmanager.h"
#include "gigiyoung/gy_abstract.h"

#define UPDATE_MS 50

#define PLAYER_IMMUNE_DURATION 20
#define DEFAULT_POS_X 30 
#define DEFAULT_POS_Y 30
#define DEFAULT_VEL_X 10
#define DEFAULT_VEL_Y 0

#define DEFAULT_PLAT_POS_X 0
#define DEFAULT_PLAT_POS_Y 150 

#define DEFAULT_EXIT_POS_X 50 
#define DEFAULT_EXIT_POS_Y 50

#define DEFAULT_PLAT_HEIGHT 10
#define DEFAULT_PLAT_WIDTH 500

#define DEFAULT_SHARK_HEIGHT 100 
#define DEFAULT_SHARK_WIDTH 150 

#define DEFAULT_BANANA_HEIGHT 30
#define DEFAULT_BANANA_WIDTH 30

#define DEFAULT_STEAM_HEIGHT 100
#define DEFAULT_STEAM_WIDTH 100

#define DEFAULT_EXIT_HEIGHT 100
#define DEFAULT_EXIT_WIDTH 75

#define DEFAULT_STUN_DURATION 40

#define LEFT	0
#define RIGHT	1
#define UP	2
#define DOWN	3


struct Velocity {
    int x, y;
};

//class LoadPlatform;

class Banana: public AbstractObject {
    Q_OBJECT
public:
    Banana(QGraphicsItem *parent = 0);
    Banana(int x, int y, QGraphicsItem *parent = 0);

    void pause();
    void resume();

    // 0 left, 1 right 
    void chuck(int direction);
    void eat();
    bool thrown();
    void set_thrown(bool is_thrown);

public slots:
    void status();
    void move();

protected:
    void init();

private:
    bool is_picked_up;
    bool is_thrown;
    struct Velocity vel;
};


class Exit: public AbstractObject {
    Q_OBJECT
public:
    Exit(QGraphicsItem *parent=0);
    Exit(int x, int y, QGraphicsItem *parent=0);

    void pause();
    void resume();

public slots:
    void status();

protected:
    void init();
};




class Platform: public QGraphicsPixmapItem {
public:
    Platform(QGraphicsItem *parent=0);
    Platform(int x, int y, QGraphicsItem *parent=0);
    Platform(int x, int y, int width, QGraphicsItem *parent=0);

private:
    void init();

    //LoadPlatform *graphics;
    Graphics *graphics;
};



class Shark: public AbstractObject {
    Q_OBJECT
public:
    Shark(QGraphicsItem *parent=0);
    Shark(int x, int y, QGraphicsItem *parent=0);
    Shark(int x, int y, int vel_x, int vel_y, QGraphicsItem *parent=0);

    void pause();
    void resume();

    void stun(int time=DEFAULT_STUN_DURATION);

public slots:
    void move();

protected:
    void init();

private:
    void set_image();

    int stun_duration;
    int sound_count;
    struct Velocity vel;
};


class Steam: public AbstractObject {
    Q_OBJECT
public:
    Steam(QGraphicsItem *parent=0);
    Steam(int x, int y, QGraphicsItem *parent=0);

    void pause();
    void resume();

    bool active();

public slots:
    void status();

protected:
    void init();

private:
    bool is_active;
    int count, time_active;
};


#endif /* GY_OBJECT_H */
