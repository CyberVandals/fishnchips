#include "inc/koffi/kk_gamelevel.h"
#include <QDebug>
#include "koffi/kk_levelitem.h"

GameLevel::GameLevel()
{

}


QList<LevelItem>* GameLevel::generate(const QString &filename)
{
    parse_level_file(filename);
    return levelItems;
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
       qDebug() << line;

//       LevelItem *item = new LevelItem();
//       parse(item, line);
//       levelItems->append(*item);
    }
    file->close();
}

void GameLevel::parse(QString line)
{
    QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    qDebug() << list.at(0) << " - " << list.at(1);
}

void GameLevel::parse(LevelItem *item, QString line)
{
    QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    item->setTitle(list.at(0));
    bool ok;
    item->setPosition(list.at(1).toUInt(), list.at(2).toUInt());
}
