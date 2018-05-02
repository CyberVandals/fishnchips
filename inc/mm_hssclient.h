#ifndef MM_HSSCLIENT_H
#define MM_HSSCLIENT_H

#include <QCoreApplication>
#include <QString>
#include <QProcess>

class HSSClient{

private:

    QString path;


public:

    QString ip_address;
    QString game_ID;
    QString player_name;

    HSSClient();

    // ip stands for IP address; gID stands for "game ID"

    void push_score(QString ip, QString gID, QString name, QString score);


};

#endif // MM_HSSCLIENT_H
