/* gy_object.h - Interface for game objects
 * By Gigi Young
 */

#ifndef GY_OBJECT_H
#define GY_OBJECT_H

#include <QGraphicsRectItem>

struct Size {
    int width;
    int height;
};

struct Position {
    int x;
    int y;
};

struct Velocity {
    int x;
    int y;
};


// Platform
class Platform: public QGraphicsRectItem {
public:
    Platform();

private:
    struct Size size;
    struct Position pos;
};

// Shark - needs to move 
class Shark: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Shark();

public slots:
    void move();

private:
    struct Size size;
    struct Position pos;
    struct Velocity vel;
};

// Banana 
class Banana: public QGraphicsRectItem {
public:
    Banana();

private:
    struct Size size;
    struct Position pos;
};

// Banana projectile
class BananaProjectile: public QObject, public Banana {
    Q_OBJECT
public:
    BananaProjectile();

private:
    struct Velocity vel;
};


// Steam needs to check if SomeObject collided with it
class Steam: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Steam();

private:
    int countdown;
    struct Size size;
    struct Position pos;
}

// Exit Object - needs to check whether play has collided with it
class ExitDoor: public QObject public QGraphicsRectItem {
    Q_OBJECT()
public:
    ExitDoor();

public slots:
    void check_player();

private:
    struct Size size;
    struct Position pos;
};


#endif /* GY_OBJECT_H */
