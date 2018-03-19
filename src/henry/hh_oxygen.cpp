#include "henry/hh_oxygen.h"


Oxygen::Oxygen(QGraphicsScene *scene): QProgressBar()
{
    //Oxygen oxy = new Oxygen();
    setOrientation(Qt::Horizontal);
    //oxy.setMaximum(100);
    //oxy.setMinimum(0);
    setRange(0,100);
    setValue(100);
    setFormat(NULL);
    setStyleSheet("::chunk { background-color: #182F99; border: 2px solid blue; }");

    this->setGeometry(160, 10, 150, 25);
    scene->addWidget(this);
    //QTimer oxy_timer = new QTimer(this);

//connect(oxy_timer, SIGNAL(timeout(), this, SLOT(setValue(int)));

}
void Oxygen::renew()
{

}

void Oxygen::tick()
{

}

