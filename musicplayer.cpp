#include "musicplayer.h"
#include<QSoundEffect>
#include<QFileDialog>
#include<QDebug>
#include<QDir>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QUrl>

musicplayer::musicplayer()
{
    audiooutput= new QAudioOutput(this);
    mediaplayer= new QMediaPlayer(this);
    mediaplayer->setAudioOutput(audiooutput);
}

void musicplayer::playmusic1()//心有所想，日复一日，必有精进
{
    mediaplayer->setSource(QUrl("qrc:/res/music/k96m1mywyutcsts5349cnbfynihhtv3.mp3"));
    mediaplayer->play();

}

void musicplayer::playmusic2()//耽搁的时间太多，事情可就做不完了
{
    mediaplayer->setSource(QUrl("qrc:/res/music/mn3ctk67mp0ibxteiemxqaei3dnxk77.mp3"));
    mediaplayer->play();
}

void musicplayer::playmusic3()
{
    //又有心事么，我来陪你一起想吧
    mediaplayer->setSource(QUrl("qrc:/res/music/fm2otnsxjo5he9bokl45qgg5zv3o7m8.mp3"));
    mediaplayer->play();
}

void musicplayer::playmusic4()
{
    //变聪明了
    mediaplayer->setSource(QUrl("qrc:/res/music/almrax52aza4v4fafjoj1icq9u2wcws.mp3"));
    mediaplayer->play();
}

void musicplayer::playmusic5()
{
    //劳逸结合是不错，但也别放松过头
    mediaplayer->setSource(QUrl("qrc:/res/music/hjsc5kenf9bn4u5wzxvnllq83bgohbg.mp3"));
    mediaplayer->play();
}
