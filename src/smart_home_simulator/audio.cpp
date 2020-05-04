#include "audio.h"

#include <QDir>
#include <QMediaPlaylist>
#include <QSound>

Audio *audio = nullptr;


/*
QMediaPlayer::StoppedState	0	The media player is not playing content, playback will begin from the start of the current track.
QMediaPlayer::PlayingState	1	The media player is currently playing content.
QMediaPlayer::PausedState	2	The media player has paused playback, playback of the current track will resume from the position the player was paused at.

enum QMediaPlaylist::PlaybackMode
QMediaPlaylist::CurrentItemOnce
0

QMediaPlaylist::CurrentItemInLoop
1

QMediaPlaylist::Sequential
2
Playback starts from the current and moves through each successive item until the last is reached and then stops. The next item is a null item when the last one is currently playing.

QMediaPlaylist::Loop
3
Playback restarts at the first item after the last has finished playing.

QMediaPlaylist::Random
4
Play items in random order.
*/


Audio::Audio()
    : songs_player(new QMediaPlayer(nullptr, QMediaPlayer::LowLatency)),
      effects_player(new QMediaPlayer),
      songs_playlist(new QMediaPlaylist),
      effects_playlist(new QMediaPlaylist)
{
    songs_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    effects_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
}

void Audio::LoadSongs(QString path)
{
    QDir directory(path);
    songs_files = directory.entryList(QStringList() << "*.mp3" << "*.MP3", QDir::Files);
    for (QString f_name : songs_files) {
        songs_playlist->addMedia(QUrl().fromLocalFile(path + f_name));
    }

    songs_playlist->setCurrentIndex(0);

    songs_player->setPlaylist(songs_playlist);

//    videoWidget = new QVideoWidget;
//    player->setVideoOutput(videoWidget);
//    videoWidget->show();
//    player->play();

}

QStringList Audio::GetSongNames()
{
    return songs_files;
}

void Audio::LoadSoundEffects(QString path) {
    QDir directory(path);
    effects_files = directory.entryList(QStringList() << "*.mp3" << "*.MP3" << "*.wav", QDir::Files);
    for (QString f_name : effects_files) {
        effects_playlist->addMedia(QUrl().fromLocalFile(path + f_name));
    }

    effects_playlist->setCurrentIndex(0);

    effects_player->setPlaylist(effects_playlist);
}

void Audio::PlaySong(QString file_name)
{
    if (!songs_files.contains(file_name)) {
        qDebug() << file_name << " was not found in the song_mp3_files:\n" << songs_files;
        return;
    }

    int ind = songs_files.indexOf(file_name);
    songs_playlist->setCurrentIndex(ind);

    songs_player->play();
}

void Audio::PlayEffect(QString file_name, bool repetitive, qreal playback_speed)
{
    int state = effects_player->state();

    effects_player->setPlaybackRate(playback_speed);
    if (repetitive) {
        effects_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

        if (state == QMediaPlayer::PlayingState && file_name == last_played_sound_effect) {
            return;
        }
    }
    else {
        effects_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    }


    last_played_sound_effect = file_name;



    if (!effects_files.contains(file_name)) {
        qDebug() << file_name << " was not found in the effects_files:\n" << effects_files;
        return;
    }

    int ind = effects_files.indexOf(file_name);
    effects_playlist->setCurrentIndex(ind);
    effects_player->play();

    qDebug() << file_name << " should be played";
}


