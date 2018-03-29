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
    GameLevel();
    QList<LevelItem>* generate(const QString &filename);
private:
    void parse_level_file(const QString &filename);
    void parse(QString line);
    void parse(LevelItem* item, QString line);
    QString level, score;
    QList<LevelItem> *levelItems;
};
