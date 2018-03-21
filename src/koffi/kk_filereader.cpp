#include "koffi/kk_filereader.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QResource>
#include <QIODevice>

FileReader::FileReader(QString filename)
{
    QFile file(Filename);
}

void FileReader::parseLevel()
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {
          QString line = in.readLine();
          qDebug << line;
       }
       file.close();
    }
}
