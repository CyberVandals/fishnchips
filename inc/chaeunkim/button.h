#ifndef BUTTON_H
#define BUTTON_H

//#include <QPushButton>
#include <QGraphicsTextItem>
#include <QtWidgets>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(QString txt, QPushButton * parent = NULL);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);
    void hoverEnter(QHoverEvent *event);
    void hoverLeave(QHoverEvent *event);
    void hoverMove(QHoverEvent *event);
    bool event(QEvent *event);

};

#endif // BUTTON_H
