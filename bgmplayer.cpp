#include "bgmplayer.h"
#include <QDir>
#include <QMediaPlayer>
#include <QMediaPlaylist>

// 为了解决mac下声音无法输出,总之发现使用绝对路径可以完成目标,蛋疼,因此以此种方式暂时处理
//static const QString s_curDir = QDir::currentPath() + "/";

bgmplayer::bgmplayer(QObject *parent)
    : QObject(parent)

{

    player=new QMediaPlayer;
}

void bgmplayer::bgm1()
{
    player->stop();
    QMediaPlaylist *list=new QMediaPlaylist;

    list->addMedia(QUrl("qrc:/resource/生命流.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    player->setPlaylist(list);
    player->setVolume(10);
    player->play();

}



void bgmplayer::playSound()
{

}

void bgmplayer::TowerPlaceSound()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/干员落地.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

//LifeLoseSound,
void bgmplayer::shootsound1()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/能天使攻击.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::shootsound2()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/白金蓝毒攻击.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::shootsound3()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/W攻击.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::shootsound4()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/白金蓝毒攻击.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::shootsound5()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/真理攻击.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::clicksound1()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/Link音效.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}

void bgmplayer::clicksound2()
{
    QMediaPlayer *pl=new QMediaPlayer;
    QMediaPlaylist *list=new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/resource/Choose音效.mp3"));
    list->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    pl->setPlaylist(list);
    pl->setVolume(50);
    pl->play();
}//                              这些播放函数都废弃了，因为资源问题画音不匹配。。。////

void bgmplayer::choose1()
{

}

void bgmplayer::choose2()
{

}

void bgmplayer::choose3()
{

}

void bgmplayer::choose4()
{

}

void bgmplayer::choose5()
{

}

void bgmplayer::voice1()
{

}

void bgmplayer::voice2()
{

}

void bgmplayer::voice3()
{

}

void bgmplayer::voice4()
{

}

void bgmplayer::voice5()
{

}
