#include "../../inc/mm_soundmanager.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

SoundManager::SoundManager()
{


    //music.setMedia(QUrl("qrc:/sounds/background.wav"));
    //music.play();

}

void SoundManager::play_background()
{

    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia( QUrl( background_path ) );
    playlist->setPlaybackMode( QMediaPlaylist::Loop );

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist( playlist );
    music->play();


}

void SoundManager::play_bump()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( bump_path ) );

    music->play();


}

void SoundManager::play_chomp()
{

    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( chomp_path ) );

    music->play();

}

void SoundManager::play_die()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl ( die_path ) );

    music->play();
}

void SoundManager::play_eat()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( eat_path ) );

    music->play();

}

void SoundManager::play_end()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( end_path ) );

    music->play();
}

void SoundManager::play_hit()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( hit_path ) );

    music->play();
}

void SoundManager::play_levelup()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( levelup_path ) );

    music->play();
}

void SoundManager::play_pickup()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( pickup_path ) );

    music->play();
}

void SoundManager::play_start()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( start_path ) );

    music->play();
}

void SoundManager::play_steam()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( steam_path ) );

    music->play();
}

void SoundManager::play_throw()
{
    QMediaPlayer *music = new QMediaPlayer();

    music->setMedia( QUrl( throw_path ) );

    music->play();
}

//void load_banana_sound(Main_player *player){

    //player->banana_throw.setMedia(QUrl("qrc:/sounds/throw.wav"));
//}
