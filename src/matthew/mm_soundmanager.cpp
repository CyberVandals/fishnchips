#include "../../inc/mm_soundmanager.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

SoundManager::SoundManager()
{
//The constructor does not do anything
}

void SoundManager::play_background()
{

    //A playlist is used to put the background music in a continual loop rather than playing once
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia( QUrl( background_path ) );
    playlist->setPlaybackMode( QMediaPlaylist::Loop );

    music1 = new QMediaPlayer();
    //The volume is set to 20% since it is very loud otherwise
    music1->setVolume(20);
    music1->setPlaylist( playlist );
    music1->play();


}

//Each of these functions declares a qmedia player, passes the path to its respective sound file, and then plays the file.
//The file paths are the member variables of the SoundManager class

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
