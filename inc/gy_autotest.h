#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPoint>
#include <QList>

class AutoTest: public QObject {
    Q_OBJECT

public:
    AutoTest(QObject *main_window, QGraphicsItem *object); 
    bool change_scene(QObject *main_window);
    void add_point(QPoint point);
    void add_path(QList<QPoint> points);

public slots:
    void simulate_keypress();

private:
    int list_pos;
    QPoint dest;
    QList<QPoint> points;
 
    QGraphicsItem *object;
    QTimer *timer;
    QObject *receiver;

};


#endif /* AUTOTEST_H */
