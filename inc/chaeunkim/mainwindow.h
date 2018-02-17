#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"

class MainWindow :public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow(QWidget * parent = NULL);
    void mainmenu();
    QGraphicsScene * scene;
    QGraphicsPixmapItem *logo;
    Button *playBtn;
    Button *quitBtn;
    void gameplay();
public slots:
    void start();

};



#endif // MAINWINDOW_H
