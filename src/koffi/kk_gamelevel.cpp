#include "inc/koffi/kk_gamelevel.h"
#include <QDebug>
#include "koffi/kk_levelitem.h"


GameLevel::GameLevel(const QString &filename)
{
    this->parse_level_file(filename);
}


QList<LevelItem>* GameLevel::get_levels_items()
{
    return this->level_items;
}


void GameLevel::parse_level_file(const QString &filename)
{

    QFile *file = new QFile(filename);

    if (!file->open(QIODevice::ReadOnly | QFile::Text))
    {
        qDebug() << "Could not open the file for reading";
        return;
    }

    QTextStream in(file);
    LevelItem *item;

    while (!in.atEnd())
    {
       QString line = in.readLine();
       qDebug() << "line: " << line;

       item = new LevelItem();
       parse(item, line);
       level_items->append(*item);
    }
    file->close();
}

void GameLevel::parse(LevelItem *item, const QString& line)
{
    if(!line.startsWith('#') && line.length() > 0){
        QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
        item->setTitle(list.at(0));
        item->setPosition(list.at(1).toUInt(), list.at(2).toUInt());
    }
}
