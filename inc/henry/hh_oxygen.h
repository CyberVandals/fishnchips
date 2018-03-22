#ifndef HH_OXYGEN_H
#define HH_OXYGEN_H

#include <QProgressBar>
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QCoreApplication>
#include <QPalette>
#include <QPropertyAnimation>

class Oxygen: public QProgressBar
{
Q_OBJECT
public:
    Oxygen(QGraphicsScene * scene);
    void renew();

public slots:
    void tick();





};


#endif // HH_OXYGEN_H
