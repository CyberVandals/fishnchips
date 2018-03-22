/* gy_object.h - Interface for game objects
 * By Gigi Young
 */

#ifndef GY_OBJECT_H
#define GY_OBJECT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "wz_graphics.h"
#include "mm_soundmanager.h"

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

// forward declarations
class Graphics;
class SoundManager;

// structs
struct Velocity {
    int x;
    int y;
};

// Banana 
class Banana: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Banana(QGraphicsItem *parent = 0);
    Banana(int pos_x, int pos_y, QGraphicsItem *parent = 0);
    Banana(int width, int height, int pos_x, int pos_y,
           QGraphicsItem *parent = 0);

    // 0 for up, 1 for down, 2 for left, 3 for right
    bool chuck(int direction);
    bool pickup();
    bool eat();
    bool is_thrown();

public slots:
    void status();
    void move();

private:
    void init();

    bool thrown;
    struct Velocity vel;
    Graphics *graphics;
    QTimer *timer;
};

// Exit Object - needs to check whether play has collided with it
class Exit: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Exit(QGraphicsItem *parent=0);
    Exit(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Exit(int width, int height, int pos_x, int pos_y, QGraphicsItem *parent=0);

public slots:
    void status();

private:
    void init();

    QTimer *timer;
    Graphics *graphics;
};



// Platform - maybe use Draw/Paint() instead of an image
//class Platform: public QGraphicsRectItem {
class Platform: public QGraphicsPixmapItem {
public:
    Platform(QGraphicsItem *parent=0);
    Platform(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Platform(int width, int pos_x, int pos_y, 
             QGraphicsItem *parent=0);

private:
    void init();

    Graphics *graphics;

};

// Shark - needs to move 
class Shark: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Shark(QGraphicsItem *parent=0);
    Shark(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Shark(int pos_x, int pos_y, int vel_x, int vel_y, 
          QGraphicsItem *parent=0);
    Shark(int width, int height, int pos_x, int pos_y, int vel_x, int vel_y, 
          QGraphicsItem *parent=0);

    bool stun(int time=DEFAULT_STUN_DURATION);
    bool cook();

public slots:
    void move();
    void status();

private:
    void init();

    bool cooked;
    int stunned;
    int sound_count;
    struct Velocity vel;

    QTimer *timer;
    Graphics *graphics;
    SoundManager *sound;
};

// Steam needs to check if SomeObject collided with it
class Steam: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Steam(QGraphicsItem *parent=0);
    Steam(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Steam(int width, int height, int pos_x, int pos_y, QGraphicsItem *parent=0);

public slots:
    void status();

private:
    void init();

    bool exploded;
    int countdown;
    QTimer *timer;
    Graphics *graphics;
};


#endif /* GY_OBJECT_H */
