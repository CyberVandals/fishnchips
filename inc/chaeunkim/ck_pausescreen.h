#ifndef CK_PAUSESCREEN_H
#define CK_PAUSESCREEN_H

#include <QGraphicsTextItem>
#include <QGraphicsScene>

class PauseScreen : public QGraphicsTextItem{

public:
    PauseScreen(QGraphicsScene *);
    void bring_pauseScreen();

};

#endif // CK_PAUSESCREEN_H
