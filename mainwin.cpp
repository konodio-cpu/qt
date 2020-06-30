#include "mainwin.h"
#include "ui_mainwin.h"
#include"scene.h"
#include"bgmplayer.h"
MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
    connect(ui->btnstart,SIGNAL(clicked(bool)),this,SLOT(clickedstart(bool)));
    this->setFixedSize(800,400);
    this->setWindowTitle("Arknights");
    bgmplayer *player=new bgmplayer();
    player->bgm1();

}

MainWin::~MainWin()
{
    delete ui;
}
int MainWin::clickedstart(bool checked)
{
    //bgmplayer *player=new bgmplayer;
    //player->clicksound1();
    scene *scene1=new scene;
    scene1->show();
    this->hide();
    return 0;
}


