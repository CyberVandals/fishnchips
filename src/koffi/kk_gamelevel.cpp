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

    while (!in.atEnd())
    {
       QString line = in.readLine();
       parse(line);
    }
    file->close();
}

void GameLevel::parse(const QString& line)
{
    QString simplifiedLine = line.simplified();
    if(!simplifiedLine.startsWith('#') && !simplifiedLine.isEmpty()){
        QStringList list = simplifiedLine.split(QRegExp("\\W+"), QString::SkipEmptyParts);
        LevelItem *item = new LevelItem();
        item->setTitle(list.at(0));
        item->setPosition(list.at(1).toUInt(), list.at(2).toUInt());
        level_items->append(*item);
    }
}
