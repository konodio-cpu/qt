#ifndef ENEMY_H
#define ENEMY_H


#include <QObject>
#include <QPoint>
#include <QSize>
#include <QPixmap>

class way;
class QPainter;
class scene;
class tower;
class enemy : public QObject
{
    Q_OBJECT
public:
    enemy(way *startWayPoint, scene *game);
    ~enemy();

    void draw(QPainter *painter) const;
    void move();
    void getDamage(int damage);
    void getRemoved();
    void getAttacked(tower *attacker);
    void gotLostSight(tower *attacker);
    QPoint pos() const;

public slots:
    void doActivate();

private:
    bool			my_active;
    int				my_maxHp;
    int				my_currentHp;
    qreal			my_walkingSpeed;
    qreal			my_rotationSprite;

    QPoint			my_pos;
    way *		my_destinationWayPoint;
    scene *	my_game;
    QList<tower *>	my_attackedTowersList;

    const QPixmap	my_sprite= QPixmap(":/resource/法术大师.png").scaled(my_fixedSize.width(),my_fixedSize.height());
    static const QSize my_fixedSize;
};

#endif // ENEMY_H
