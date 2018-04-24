#include "../../inc/mm_soundmanager.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QProcess>
#include <QTime>

SoundManager::SoundManager()
{

    background_music = new QMediaPlayer();

    bump_music = new QMediaPlayer();

    chomp_music = new QMediaPlayer();

    die_music = new QMediaPlayer();

    eat_music = new QMediaPlayer();

    end_music = new QMediaPlayer();

    hit_music = new QMediaPlayer();

    levelup_music = new QMediaPlayer();

    pickup_music = new QMediaPlayer();

    start_music = new QMediaPlayer();

    steam_music = new QMediaPlayer();

    throw_music = new QMediaPlayer();

}

void SoundManager::adjust_volume(QMediaPlayer *music, int volume)
{
    music->setVolume(volume);

}



void SoundManager::play_background()
{

    //A playlist is used to put the background music in a continual loop rather than playing once
    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia( QUrl( background_path ) );
    playlist->setPlaybackMode( QMediaPlaylist::Loop );




    //The volume is set to 20% since it is very loud otherwise
    //background_music->setVolume(20);
    this->adjust_volume(background_music,20);
    background_music->setPlaylist( playlist );
    background_music->play();

}



//Each of these functions declares a qmedia player, passes the path to its respective sound file, and then plays the file.
//The file paths are the member variables of the SoundManager class

void SoundManager::play_bump()
{
    bump_music->setMedia( QUrl( bump_path ) );

    bump_music->play();


}

void SoundManager::play_chomp()
{



    chomp_music->setMedia( QUrl( chomp_path ) );

    chomp_music->play();

}

void SoundManager::play_die()
{

    die_music->setMedia( QUrl ( die_path ) );

    die_music->play();
}

void SoundManager::play_eat()
{

    eat_music->setMedia( QUrl( eat_path ) );

    eat_music->play();

}

void SoundManager::play_end()
{

    end_music->setMedia( QUrl( end_path ) );

    end_music->play();
}

void SoundManager::play_hit()
{

    hit_music->setMedia( QUrl( hit_path ) );

    hit_music->play();
}

void SoundManager::play_levelup()
{


    levelup_music->setMedia( QUrl( levelup_path ) );

    levelup_music->play();
}

void SoundManager::play_pickup()
{


    pickup_music->setMedia( QUrl( pickup_path ) );

    pickup_music->play();
}

void SoundManager::play_start()
{

    start_music->setMedia( QUrl( start_path ) );

    start_music->play();
}

void SoundManager::play_steam()
{

    steam_music->setMedia( QUrl( steam_path ) );

    steam_music->play();

}

void SoundManager::play_throw()
{

    throw_music->setMedia( QUrl( throw_path ) );

    throw_music->play();
}

void SoundManager::stop_background()
{

    background_music->stop();

}

void SoundManager::stop_bump()
{

    bump_music->stop();
}

void SoundManager::stop_chomp()
{

    chomp_music->stop();
}

void SoundManager::stop_die()
{

    die_music->stop();

}

void SoundManager::stop_eat()
{

    eat_music->stop();

}

void SoundManager::stop_end()
{

    end_music->stop();

}

void SoundManager::stop_hit()
{

    hit_music->stop();

}

void SoundManager::stop_levelup()
{

    levelup_music->stop();
}

void SoundManager::stop_pickup()
{

    pickup_music->stop();

}

void SoundManager::stop_start()
{

    start_music->stop();

}

void SoundManager::stop_steam()
{

    steam_music->stop();
}

void SoundManager::stop_throw()
{
    throw_music->stop();

}

