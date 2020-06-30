#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QSize>
#include <QPixmap>
#include <QObject>


class QPainter;
class enemy;
class scene;
class bullet : QObject
{
    Q_OBJECT
    Q_PROPERTY(QPoint my_currentPos READ currentPos WRITE setCurrentPos)

public:
    bullet(QPoint startPos, QPoint targetPoint, int damage, enemy *target,
           scene *game, const QPixmap &sprite = QPixmap(":/resource/bullet.png"));

    void draw(QPainter *painter) const;
    void move();
    void setCurrentPos(QPoint pos);
    QPoint currentPos() const;

private slots:
    void hitTarget();

private:
    const QPoint my_startPos;
    const QPoint my_targetPos;
    const QPixmap my_sprite=QPixmap(":/resource/bullet.png").scaled(5,5);
    QPoint my_currentPos;
    enemy *	my_target;
    scene *	my_game;
    int		my_damage;

    static const QSize my_fixedSize;
};

#endif // BULLET_H
