#ifndef HH_MAIN_PLAYER_H
#define HH_MAIN_PLAYER_H

#include <QObject>
#include <QKeyEvent>
#include <QWidget>
#include <QObject>
#include <QGraphicsRectItem>
#include <QDesktopWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsItem>

class Main_player: public QObject, public QGraphicsRectItem
{
Q_OBJECT
private:
bool has_banana;

public:
    Main_player(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void sink();
};

#endif // HH_MAIN_PLAYER_H
