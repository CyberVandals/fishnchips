/***************************************
 *
 *    ck_pausebutton.h
 *    Chaeun Kim
 *
 ****************************************/
#ifndef PAUSEBUTTON_H
#define PAUSEBUTTON_H

#include "ck_abstract_button.h"
#include <QtWidgets>

class PauseButton : public AbstractButton {
    Q_OBJECT
public:
    PauseButton(QString txt, QPushButton * parent = NULL);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // PAUSEBUTTON_H
