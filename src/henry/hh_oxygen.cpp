#include "henry/hh_oxygen.h"


Oxygen::Oxygen(QGraphicsScene *scene): QProgressBar()
{
    setOrientation(Qt::Horizontal);
    setRange(0,100);
    setValue(100);
/*
    QPalette p = palette();
    p.setColor(QPalette::Highlight, Qt::white);
    setPalette(p);
*/
    setTextVisible(false);
    setFormat(NULL);

    setStyleSheet("::chunk { background-color: #182F99;}");


    this->update();
    this->setGeometry(160, 10, 200, 25);
    scene->addWidget(this);
    QTimer *oxy_timer = new QTimer(this);
/*
    QPropertyAnimation *animation = new QPropertyAnimation(this, "value");
    animation->setDuration(60000);
    animation->setStartValue(100);
    animation->setEndValue(0);
    animation->start();
*/

    connect(oxy_timer, SIGNAL(timeout()), this, SLOT(tick()));
    oxy_timer->start(1000);

}
void Oxygen::renew()
{

}

void Oxygen::tick()
{
int value = this->value();
this->setValue(value-1);
this->update();
}

