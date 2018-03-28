#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include <QFile>

class FileReader
{
public:
    FileReader(const QString &filename);
    void parse_level();

private:
    void parse(QString line);
    QFile *file;
    QString level, score;
    qint8 number_platforms, number_enemies;
};

#endif // FILEREADER_H
