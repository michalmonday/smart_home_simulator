#ifndef AUDIO_H
#define AUDIO_H

#include <QMediaPlayer>

class Audio
{
public:
    Audio();

    QString last_played_sound_effect;

    void LoadSongs(QString path = QString("resources/audio/songs/"));
    QStringList GetSongNames();
    void LoadSoundEffects(QString path = QString("resources/audio/effects/"));
    void PlaySong(QString file_name);
    void PlayEffect(QString file_name, bool repetitive = false, qreal playback_speed = 1.0);

    QMediaPlayer *songs_player, *effects_player;
private:
    QMediaPlaylist *songs_playlist, *effects_playlist;
    QStringList songs_files, effects_files;


};

extern Audio *audio;

#endif // AUDIO_H
