#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include<towerpos.h>
#include<bgmplayer.h>
class bgmplayer;
namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private:
    Ui::MainWin *ui;

private slots:
    int clickedstart(bool checked);
};

#endif // MAINWIN_H
