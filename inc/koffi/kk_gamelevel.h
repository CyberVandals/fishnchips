#ifndef GAMELEVEL_H
#define GAMELEVEL_H

#endif // GAMELEVEL_H

//#include "kk_levelitem.h"

#include <QString>
#include <QFile>
#include<QList>
#include <stdlib.h>

class LevelItem;

class GameLevel
{
public:
    GameLevel(const QString &filename);
    QList<LevelItem>* get_levels_items();
private:
    void parse_level_file(const QString &filename);
    void parse(const QString& line);
    QString level, score;
    QList<LevelItem> *level_items = new QList<LevelItem>();
};
