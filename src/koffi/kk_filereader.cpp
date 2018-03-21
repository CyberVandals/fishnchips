#include "koffi/kk_filereader.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QResource>
#include <QIODevice>

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
    }
    file->close();
}
