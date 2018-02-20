#include "mainwindow.h"
#include "button.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QDesktopWidget>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent){

    // get desktop resolution
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();

    scene = new QGraphicsScene();
    setFixedSize(width/1.5, height/1.1);
    scene->setSceneRect(0,0,width/1.5,height/1.1);
    setScene(scene);

    // turn off the scroll bars both horizontal and vertical
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void MainWindow::mainmenu(){
    scene->clear();
    // add logo to start menu
    logo = new QGraphicsPixmapItem(QPixmap(":/images/icon_shark.png"));
    logo->setPos((scene->width() - logo->boundingRect().width()) / 2, scene->height() / 12);
    scene->addItem(logo);

    //add play and quit buttons
    playBtn = new Button(":/images/play3.png");
    playBtn->setGeometry((scene->width() - playBtn->width()) /2,scene->height()/2,0,0);
    connect(playBtn,SIGNAL(clicked()),this,SLOT(start()));
    scene->addWidget(playBtn);

    quitBtn = new Button(":/images/quit3.png");
    quitBtn->setGeometry((scene->width() - quitBtn->width()) /2,playBtn->pos().y()+quitBtn->height(),0,0);
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quitBtn);





}
void MainWindow::gameplay(){

}
void MainWindow::start(){
    scene->removeItem(logo);
    playBtn->deleteLater();
    quitBtn->deleteLater();
}

