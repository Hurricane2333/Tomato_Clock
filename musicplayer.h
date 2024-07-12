#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include<QWidget>
#include<QMediaPlayer>
#include<QAudioOutput>
class musicplayer  : public QWidget
{
public:
    QAudioOutput* audiooutput;
    QMediaPlayer* mediaplayer;
    musicplayer();
    void playmusic1();
    void playmusic2();
    void playmusic3();
    void playmusic4();
    void playmusic5();
};

#endif // MUSICPLAYER_H
