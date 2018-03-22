#include "../../inc/ck_mainwindow.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>


MainWindow::MainWindow(){
    scene = new QGraphicsScene(this);
    backgroundMusic = new SoundManager();

    backgroundMusic->playBackground();

    // get desktop resolution
    QRect rec = QApplication::desktop()->screenGeometry();
    WID_HEI = rec.height();
    WID_WIDTH = rec.width();

    setFixedSize(WID_WIDTH/1.5, WID_HEI/1.1);

    scene->setSceneRect(0,0,WID_WIDTH/1.5,WID_HEI/1.1);

    QPixmap pim(":/images/menu_background.jpg");
    scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
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

    demoBtn = new Button(":/images/demoBtn.png");
    demoBtn->setGeometry((scene->width() - demoBtn->width()*2)/2, playBtn->pos().y()-demoBtn->height(),0,0);
    connect(demoBtn,SIGNAL(clicked()),this,SLOT(start_demo()));
    scene->addWidget(demoBtn);

    stressBtn = new Button(":/images/stressBtn.png");
    stressBtn->setGeometry((scene->width() - stressBtn->width()/20)/2, playBtn->pos().y()-stressBtn->height(),0,0);
    connect(stressBtn,SIGNAL(clicked()),this,SLOT(start_stress()));
    scene->addWidget(stressBtn);
}
void MainWindow::displayGameover(){
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
            scene->items()[i]->setEnabled(false);
    }
    scene->clear();
    bringGameOverScene();

}
void MainWindow::bringGameOverScene(){
    QPixmap pim(":/images/GameOverS.png");
    scene->setBackgroundBrush(pim.scaled(WID_WIDTH,WID_HEI,Qt::KeepAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    quitBtn = new Button(":/images/quit3.png");
    quitBtn->setGeometry((scene->width() - quitBtn->width()) /2,scene->height() - (quitBtn->height()*1.5),0,0);
    connect(quitBtn,SIGNAL(clicked()),this,SLOT(close()));
    scene->addWidget(quitBtn);

    replayBtn = new Button(":/images/replay.png");
    replayBtn->setGeometry((scene->width() - replayBtn->width()/2.2) /2,scene->height() - (replayBtn->height()*2),0,0);
    //connect(playBtn,SIGNAL(clicked()),this,SLOT(start()));
    scene->addWidget(replayBtn);


}

void MainWindow::start(){
    scene->removeItem(logo);
    playBtn->disconnect();
    quitBtn->disconnect();
    demoBtn->disconnect();
    stressBtn->disconnect();
    playBtn->deleteLater();
    quitBtn->deleteLater();
    demoBtn->deleteLater();
    stressBtn->deleteLater();
    //gamescene = new SceneManager(scene,false);
    gamescene = new SceneManager(scene,0);

    gamescene->playGame();
}
void MainWindow::start_demo(){
    scene->removeItem(logo);
    playBtn->disconnect();
    quitBtn->disconnect();
    demoBtn->disconnect();
    stressBtn->disconnect();
    playBtn->deleteLater();
    quitBtn->deleteLater();
    demoBtn->deleteLater();
    stressBtn->deleteLater();
    //gamescene = new SceneManager(scene,true);
    gamescene = new SceneManager(scene,1);

    gamescene->playGame();
}
void MainWindow::start_stress(){
    scene->removeItem(logo);
    playBtn->disconnect();
    quitBtn->disconnect();
    demoBtn->disconnect();
    stressBtn->disconnect();
    playBtn->deleteLater();
    quitBtn->deleteLater();
    demoBtn->deleteLater();
    stressBtn->deleteLater();
    //gamescene = new SceneManager(scene,true);
    gamescene = new SceneManager(scene,2);

    gamescene->playGame();
}
