#include "mainwindow.h"
#include "button.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>

MainWindow::MainWindow(QWidget *parent){


    scene = new QGraphicsScene();
    setFixedSize(1280,720);
    scene->setSceneRect(0,0,1280,720);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void MainWindow::mainmenu(){

    // add logo to start menu
    QGraphicsPixmapItem *logo = new QGraphicsPixmapItem(QPixmap("/Users/chaeunkim/QT_proj/FISH_N_CHIPS/images/icon.png"));
    logo->setPos((Width - logo->boundingRect().width()) / 2, Height / 12);
    scene->addItem(logo);

    //add buttons
    Button *playBtn = new Button("/Users/chaeunkim/QT_proj/FISH_N_CHIPS/images/play.png");
    //Button *quitBtn = new Button("/Users/chaeunkim/QT_proj/FISH_N_CHIPS/images/quit.png");
    playBtn->setGeometry(Width/2,Height/2,190,90);
    scene->addWidget(playBtn);

    //scene->addItem(playBtn);





}
