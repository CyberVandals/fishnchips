#ifndef HH_OXYGEN_H
#define HH_OXYGEN_H

#include <QProgressBar>
#include <QTimer>
#include <QGraphicsScene>

class Oxygen: public QProgressBar
{
public:
    Oxygen(QGraphicsScene * scene);
    void renew();

public slots:
    void tick();





};


#endif // HH_OXYGEN_H
