#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H

#include <QPushButton>
#include <QtWidgets>

class PauseButton : public QPushButton
{
    Q_OBJECT
public:
    PauseButton(QString txt, QPushButton * parent = NULL);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

};

#endif // PAUSEBUTTON_H
