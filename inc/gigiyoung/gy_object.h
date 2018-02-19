/* gy_object.h - Interface for game objects
 * By Gigi Young
 */

#ifndef GY_OBJECT_H
#define GY_OBJECT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>

#define UPDATE_MS 50

#define DEFAULT_POS_X 0
#define DEFAULT_POS_Y 0
#define DEFAULT_VEL_X 10
#define DEFAULT_VEL_Y 0

#define DEFAULT_PLAT_HEIGHT 10
#define DEFAULT_PLAT_WIDTH 10
#define DEFAULT_SHARK_HEIGHT 50
#define DEFAULT_SHARK_WIDTH 150
#define DEFAULT_BANANA_HEIGHT 50
#define DEFAULT_BANANA_WIDTH 150
#define DEFAULT_STEAM_HEIGHT 50
#define DEFAULT_STEAM_WIDTH 150
#define DEFAULT_EXIT_HEIGHT 50
#define DEFAULT_EXIT_WIDTH 150

// structs
struct Velocity {
    int x;
    int y;
};


// Platform
class Platform: public QGraphicsRectItem {
public:
    Platform(int height=DEFAULT_PLAT_HEIGHT, int width=DEFAULT_PLAT_WIDTH, 
             int pos_x=DEFAULT_POS_X, int pos_y=DEFAULT_POS_Y, 
             QGraphicsItem *parent=0);
};

// Shark - needs to move 
class Shark: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Shark(int height=DEFAULT_PLAT_HEIGHT, int width=DEFAULT_PLAT_WIDTH, 
          int pos_x=DEFAULT_POS_X, int pos_y=DEFAULT_POS_Y, 
          int vel_x=DEFAULT_VEL_X, int vel_y=DEFAULT_VEL_Y,
          QGraphicsItem *parent=0);

public slots:
    void move();

private:
    struct Velocity vel;
    QTimer *timer;
};

// Banana 
class Banana: public QGraphicsRectItem {
public:
    Banana(QGraphicsItem *parent = 0);

private:
};

// Banana projectile
class BananaProjectile: public QObject, public Banana {
    Q_OBJECT
public:
    BananaProjectile(QGraphicsItem *parent = 0);

private:
    struct Velocity vel;
    QTimer *timer;
};


// Steam needs to check if SomeObject collided with it
class Steam: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Steam(int height=DEFAULT_PLAT_HEIGHT, int width=DEFAULT_PLAT_WIDTH, 
          int pos_x=DEFAULT_POS_X, int pos_y=DEFAULT_POS_Y, 
          QGraphicsItem *parent=0);

private:
    int countdown;
    QTimer *timer;
};

// Exit Object - needs to check whether play has collided with it
class Exit: public QObject, public QGraphicsRectItem {
    Q_OBJECT()
public:
    Exit(int height=DEFAULT_PLAT_HEIGHT, int width=DEFAULT_PLAT_WIDTH, 
         int pos_x=DEFAULT_POS_X, int pos_y=DEFAULT_POS_Y, 
         QGraphicsItem *parent=0);

public slots:
    void check_player();

private:
    QTimer *timer;
};


#endif /* GY_OBJECT_H */
