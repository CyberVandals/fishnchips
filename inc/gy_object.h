/* gy_object.h - Interface for game objects
 * By Gigi Young
 */

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
#define DEFAULT_STEAM_HEIGHT 50
#define DEFAULT_STEAM_WIDTH 50
#define DEFAULT_EXIT_HEIGHT 100
#define DEFAULT_EXIT_WIDTH 75

#define DEFAULT_STUN_DURATION 40

#define LEFT	0
#define RIGHT	1


// structs
struct Velocity {
    int x;
    int y;
};

// Banana 
class Banana: public AbstractObject {
    Q_OBJECT
public:
    Banana(QGraphicsItem *parent = 0);
    Banana(int x, int y, QGraphicsItem *parent = 0);

    void pause();
    void resume();

    // 0 left, 1 right 
    void chuck(int direction);
    void pickup();
    void eat();
    //bool is_thrown();

public slots:
    void status();
    void move();

private:
    void init();

    bool picked_up;
    bool thrown;
    struct Velocity vel;
};


// Exit Object - needs to check whether play has collided with it
class Exit: public AbstractObject {
    Q_OBJECT
public:
    Exit(QGraphicsItem *parent=0);
    Exit(int x, int y, QGraphicsItem *parent=0);

    void pause();
    void resume();

public slots:
    void status();

private:
    void init();
};




// Platform - maybe use Draw/Paint() instead of an image
//class Platform: public QGraphicsRectItem {
class Platform: public QGraphicsPixmapItem {
public:
    Platform(QGraphicsItem *parent=0);
    Platform(int x, int y, QGraphicsItem *parent=0);
    Platform(int x, int y, int width, QGraphicsItem *parent=0);

private:
    void init();

    Graphics *graphics;
};

// Shark - needs to move 
class Shark: public AbstractObject {
    Q_OBJECT
public:
    Shark(QGraphicsItem *parent=0);
    Shark(int x, int y, QGraphicsItem *parent=0);
    Shark(int x, int y, int vel_x, int vel_y, QGraphicsItem *parent=0);

    void pause();
    void resume();

    bool stun(int time=DEFAULT_STUN_DURATION);
    bool cook();

public slots:
    void move();
    void status();

private:
    void init();
    void set_image();

    bool cooked;
    int stunned;
    int sound_count;
    struct Velocity vel;
};


// Steam needs to check if SomeObject collided with it
class Steam: public AbstractObject {
    Q_OBJECT
public:
    Steam(QGraphicsItem *parent=0);
    Steam(int x, int y, QGraphicsItem *parent=0);

    void pause();
    void resume();

public slots:
    void status();

private:
    void init();

    bool exploded;
    int countdown;
};


#endif /* GY_OBJECT_H */
