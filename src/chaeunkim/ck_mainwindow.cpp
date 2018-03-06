#include "../../inc/ck_mainwindow.h"
#include <iostream>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QRect>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>


MainWindow::MainWindow(){
    pauseScene = new PauseScreen();
    scene = new QGraphicsScene();

    //timer.start(1000/33);

    // get desktop resolution
    QRect rec = QApplication::desktop()->screenGeometry();
    int height = rec.height();
    int width = rec.width();

    setFixedSize(width/1.5, height/1.1);

    scene->setSceneRect(0,0,width/1.5,height/1.1);

    QPixmap pim(":/images/menu_background.jpg");
    scene->setBackgroundBrush(pim.scaled(width,height,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    //scene->installEventFilter(this);

    // turn off the scroll bars both horizontal and vertical
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //resume();

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
    demoBtn->setGeometry((scene->width() - demoBtn->width())/2, playBtn->pos().y()-demoBtn->height(),0,0);
    connect(demoBtn,SIGNAL(clicked()),this,SLOT(start_demo()));
    scene->addWidget(demoBtn);

    /*pauseBtn = new PauseButton(":/images/pause.png");
    pauseBtn->setGeometry(scene->width() - pauseBtn->width(), 0,0,0);
    scene->addWidget(pauseBtn);*/



}

void MainWindow::handleKeyPressed(QKeyEvent * event){
    if(!isPaused){
        switch (event->key()){
            case Qt::Key_Space:
                //pause();
                pauseScene->setVisible(true);
                break;
            default:
                break;
        }
    }
    else{
        qDebug() << "ispaused is true";
        pauseScene->setVisible(false);
        isPaused = false;
    }
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        handleKeyPressed((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
void MainWindow::pause(){
    disconnect(&timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    isPaused = true;
}

void MainWindow::resume(){
    connect(&timer, SIGNAL(timeout()),
            scene, SLOT(advance()));
    isPaused = false;
}

void MainWindow::start(){
    scene->removeItem(logo);
    playBtn->disconnect();
    quitBtn->disconnect();
    demoBtn->disconnect();
    playBtn->deleteLater();
    quitBtn->deleteLater();
    demoBtn->deleteLater();
    //pauseBtn->deleteLater();
    //gamescene = new SceneManager(scene);
    gamescene = new SceneManager(scene,false);
    gamescene->playGame();
}
void MainWindow::start_demo(){
    scene->removeItem(logo);
    playBtn->disconnect();
    quitBtn->disconnect();
    demoBtn->disconnect();
    playBtn->deleteLater();
    quitBtn->deleteLater();
    demoBtn->deleteLater();
    //pauseBtn->deleteLater();
    //gamescene = new SceneManager(scene);
    gamescene = new SceneManager(scene,true);
    gamescene->playGame();
}

