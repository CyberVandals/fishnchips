#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>

class MainWindow : public QGraphicsView{
public:
    MainWindow(QWidget * parent = 0);
    void mainmenu();
    QGraphicsScene * scene;

private:

    const int Width = 1280;
    const int Height = 720;

    //QRect screenGeometry = QApplication::desktop()->screenGeometry();

};



#endif // MAINWINDOW_H
