#ifndef BUTTON_H
#define BUTTON_H

#include <QtWidgets>

#define DEFAULT_BTN_HEIGHT 100
#define DEFAULT_BTN_WIDTH 150

class Button : public QPushButton
{
    Q_OBJECT
    public:
        Button(QString txt, QPushButton * parent = NULL);

    private:
        int new_height;
        int new_width;

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
