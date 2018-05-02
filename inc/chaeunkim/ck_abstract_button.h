/***************************************
 *
 *    ck_abstract_button.h
 *    Chaeun Kim
 *
 ****************************************/

#ifndef CK_ABSTRACT_BUTTON_H
#define CK_ABSTRACT_BUTTON_H

#include <QtWidgets>

#define DEFAULT_BTN_HEIGHT 100
#define DEFAULT_BTN_WIDTH 150

class AbstractButton : public QPushButton {
    Q_OBJECT
public:
    AbstractButton(QPushButton * parent = NULL);

protected:
    int new_height;
    int new_width;

    virtual void mousePressEvent(QMouseEvent *event) = 0;

    void hover_enter(QHoverEvent *event);
    void hover_leave(QHoverEvent *event);
    void hover_move(QHoverEvent *event);
    bool event(QEvent *event);

};

#endif // CK_ABSTRACT_BUTTON_H
