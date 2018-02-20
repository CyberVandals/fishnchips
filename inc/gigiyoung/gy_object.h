/* gy_object.h - Interface for game objects
 * By Gigi Young
 */

#ifndef GY_OBJECT_H
#define GY_OBJECT_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QGraphicsItem>

#define UPDATE_MS 50

#define DEFAULT_POS_X 0
#define DEFAULT_POS_Y 0
#define DEFAULT_VEL_X 10
#define DEFAULT_VEL_Y 0

#define DEFAULT_PLAT_HEIGHT 10
#define DEFAULT_PLAT_WIDTH 10
#define DEFAULT_SHARK_HEIGHT 30
#define DEFAULT_SHARK_WIDTH 70
#define DEFAULT_BANANA_HEIGHT 30
#define DEFAULT_BANANA_WIDTH 30
#define DEFAULT_STEAM_HEIGHT 50
#define DEFAULT_STEAM_WIDTH 50
#define DEFAULT_EXIT_HEIGHT 50
#define DEFAULT_EXIT_WIDTH 50

// structs
struct Velocity {
    int x;
    int y;
};


// Platform
class Platform: public QGraphicsRectItem {
public:
    Platform(QGraphicsItem *parent=0);
    Platform(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Platform(int width, int height, int pos_x, int pos_y, 
             QGraphicsItem *parent=0);
};

// Shark - needs to move 
class Shark: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Shark(QGraphicsItem *parent=0);
    Shark(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Shark(int pos_x, int pos_y, int vel_x, int vel_y, 
          QGraphicsItem *parent=0);
    Shark(int width, int height, int pos_x, int pos_y, 
          int vel_x, int vel_y, QGraphicsItem *parent=0);

    bool stunned(int time);

public slots:
    void move();

private:
    int stun_duration;
    struct Velocity vel;
    QTimer *timer;
};

// Banana 
class Banana: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Banana(QGraphicsItem *parent = 0);
    Banana(int pos_x, int pos_y, QGraphicsItem *parent = 0);
    Banana(int width, int height, int pos_x, int pos_y,
           QGraphicsItem *parent = 0);
public slots:
    void check_player();

private:
    QTimer *timer;
};

// Banana projectile
/*
class BananaProjectile: public Banana {
public:
    BananaProjectile(QGraphicsItem *parent = 0);

public slots:
    void move();

//private:
//    struct Velocity vel;
//    QTimer *timer;
};
*/


// Steam needs to check if SomeObject collided with it
class Steam: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Steam(QGraphicsItem *parent=0);
    Steam(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Steam(int width, int height, int pos_x, int pos_y, 
          QGraphicsItem *parent=0);

public slots:
    void status();
private:
    int countdown;
    QTimer *timer;
};

// Exit Object - needs to check whether play has collided with it
class Exit: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Exit(QGraphicsItem *parent=0);
    Exit(int pos_x, int pos_y, QGraphicsItem *parent=0);
    Exit(int width, int height, int pos_x, int pos_y, 
         QGraphicsItem *parent=0);

public slots:
    void check_player();

private:
    QTimer *timer;
};


#endif /* GY_OBJECT_H */
