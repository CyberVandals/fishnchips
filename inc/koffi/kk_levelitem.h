#ifndef LEVELITEM_H
#define LEVELITEM_H

#endif // LEVELITEM_H

#include <QString>

class LevelItem {
public:
    LevelItem(){};
    void setPosition(int x, int y) {
        x_pos = x;
        y_pos = y;
    }
    void setTitle(QString title) {
        _title = title;
    }
    int x() {
        return x_pos;
    }
    int y() {
        return y_pos;
    }
    QString title() {
        return _title;
    }


private:
    int x_pos, y_pos;
    QString _title;
};
