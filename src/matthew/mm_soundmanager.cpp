#include "../../inc/mm_soundmanager.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

SoundManager::SoundManager()
{


    //music.setMedia(QUrl("qrc:/sounds/background.wav"));
    //music.play();

}

void SoundManager::playBackground()
{

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl(backgroundPath));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();


}

void SoundManager::playBump()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(bumpPath));

    music->play();


}

void SoundManager::playChomp()
{

    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(chompPath));

    music->play();

}

void SoundManager::playDie()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(diePath));

    music->play();
}

void SoundManager::playEat()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(eatPath));

    music->play();

}

void SoundManager::playEnd()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(endPath));

    music->play();
}

void SoundManager::playHit()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(hitPath));

    music->play();
}

void SoundManager::playLevelup()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(levelupPath));

    music->play();
}

void SoundManager::playPickup()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(pickupPath));

    music->play();
}

void SoundManager::playStart()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(startPath));

    music->play();
}

void SoundManager::playSteam()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(steamPath));

    music->play();
}

void SoundManager::playThrow()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia(QUrl(throwPath));

    music->play();
}

//void load_banana_sound(Main_player *player){

    //player->banana_throw.setMedia(QUrl("qrc:/sounds/throw.wav"));
//}
