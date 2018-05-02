#include "mm_hssclient.h"


HSSClient::HSSClient()
{
    this->path = qApp->applicationDirPath();

    this->path.replace("/", "\\\\");

    //this->path.append("\\\\hssclient");

    this->path.append("\\\\..\\\\..\\\\fishnchips\\\\hssclient");

    ip_address = "52.160.46.238";

    game_ID = "1";

    player_name = "CyberVandal";

}

void HSSClient::push_score(QString ip, QString gID, QString name, QString score)
{

    QStringList strlist;

    strlist << ip;
    strlist << gID;
    strlist << name;
    strlist << score;

    QProcess *proc = new QProcess();

    proc->start(path, strlist);

}
