/***************************************
 *
 *    ck_button.h
 *    Chaeun Kim
 *
 ****************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "ck_abstract_button.h"
#include <QtWidgets>

class MainButton : public AbstractButton {
    Q_OBJECT
public:
    MainButton(QString txt, QPushButton * parent = NULL);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *event);

};

#endif // BUTTON_H
