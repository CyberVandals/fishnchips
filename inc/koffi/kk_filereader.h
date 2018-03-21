#ifndef FILEREADER_H
#define FILEREADER_H

#include <QString>
#include <QFile>

class FileReader
{
public:
    FileReader(const QString &filename);
    void parseLevel();

private:
    QFile *file;
    QString level, score;
    qint8 numberOfPlatforms, numberOfEnemies;
};

#endif // FILEREADER_H
