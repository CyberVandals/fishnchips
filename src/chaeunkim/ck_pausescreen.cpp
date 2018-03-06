#include "../../inc/chaeunkim/ck_pausescreen.h"
#include <QDebug>

PauseScreen::PauseScreen(QGraphicsScene * scene){
    this->setHtml(QString("<div style='background:rgba(45, 45, 36, 100%);'>" + QString("PAUSE") + QString("</div>") ));
    this->setPos(500,500);
    this->setTextWidth(500);
    scene->addItem(this);

}
void PauseScreen::bring_pauseScreen(){
    //setHtml(QString("<div style='background:rgba(255, 255, 255, 100%);'>" + QString("put your text here") + QString("</div>") );

}
