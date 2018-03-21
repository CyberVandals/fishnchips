#include "koffi/kk_filereader.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QResource>
#include <QIODevice>
#include <QStringList>
#include <QRegExp>

FileReader::FileReader(const QString& filename)
{
    this->file = new QFile(filename);
}

void FileReader::parseLevel()
{
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
       parse(line);
    }
    file->close();
}

void FileReader::parse(QString line)
{
    QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);
    qDebug() << list.at(0) << " - " << list.at(1);
}
