#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <QList>
#include <QString>
#include <QMediaPlayer>
#include "hh_main_player.h"

class SoundManager
{
private:

    QString backgroundPath = "qrc:/sounds/background.mp3";
    QString bumpPath = "qrc:/sounds/bump.mp3";
    QString chompPath = "qrc:/sounds/chomp.mp3";
    QString diePath = "qrc:/sounds/die.mp3";
    QString eatPath = "qrc:/sounds/eat.mp3";
    QString endPath = "qrc:/sounds/end.mp3";
    QString hitPath = "qrc:/sounds/hit.mp3";
    QString levelupPath = "qrc:/sounds/levelup.mp3";
    QString pickupPath = "qrc:/sounds/pickup.mp3";
    QString startPath = "qrc:/sounds/start.mp3";
    QString steamPath = "qrc:/sounds/steam.mp3";
    QString throwPath = "qrc:/sounds/throw.mp3";

public:

    SoundManager();

    void playBackground();

    void playBump();

    void playChomp();

    void playDie();

    void playEat();

    void playEnd();

    void playHit();

    void playLevelup();

    void playPickup();

    void playStart();

    void playSteam();

    void playThrow();

};

#endif // SOUNDMANAGER_H
