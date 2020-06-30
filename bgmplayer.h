#ifndef BGMPLAYER_H
#define BGMPLAYER_H

#include <QObject>

class QMediaPlayer;





    //EnemyDestorySound

class bgmplayer : public QObject
{
public:
    explicit bgmplayer(QObject *parent = 0);

    void bgm1();

    void playSound();
    void TowerPlaceSound();
    //LifeLoseSound,
    void shootsound1();
    void shootsound2();
    void shootsound3();
    void shootsound4();
    void shootsound5();

    void clicksound1();
    void clicksound2();

    void choose1();
    void choose2();
    void choose3();
    void choose4();
    void choose5();

    void voice1();
    void voice2();
    void voice3();
    void voice4();
    void voice5();//这些都是废弃的播放函数，因为资源问题画音不匹配




private:

    QMediaPlayer *player;
    //QMediaPlayer *my_backgroundMusic; // 只用来播放背景音乐
};

#endif // BGMPLAYER_H
