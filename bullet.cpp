#include "bullet.h"
#include "enemy.h"
#include "scene.h"
#include <QPainter>
#include <QPropertyAnimation>

const QSize bullet::my_fixedSize(8, 8);

bullet::bullet(QPoint startPos, QPoint targetPoint, int damage, enemy *target,
               scene *game, const QPixmap &sprite)
    : my_startPos(startPos)
    , my_targetPos(targetPoint)
    , my_sprite(sprite)
    , my_currentPos(startPos)
    , my_target(target)
    , my_game(game)
    , my_damage(damage)
{
}

void bullet::draw(QPainter *painter) const
{
    painter->drawPixmap(my_currentPos, my_sprite);
}

void bullet::move()
{
    // 100毫秒内击中敌人
    static const int duration = 100;
    QPropertyAnimation *animation = new QPropertyAnimation(this, "my_currentPos");
    animation->setDuration(duration);
    animation->setStartValue(my_startPos);
    animation->setEndValue(my_targetPos);
    connect(animation, SIGNAL(finished()), this, SLOT(hitTarget()));

    animation->start();
}

void bullet::hitTarget()
{
    // 这样处理的原因是:
    // 可能多个炮弹击中敌人,而其中一个将其消灭,导致敌人delete
    // 后续炮弹再攻击到的敌人就是无效内存区域
    // 因此先判断下敌人是否还有效
    if (my_game->enemyList.indexOf(my_target) != -1)
        my_target->getDamage(my_damage);
    my_game->removedBullet(this);
}

void bullet::setCurrentPos(QPoint pos)
{
    my_currentPos = pos;
}

QPoint bullet::currentPos() const
{
    return my_currentPos;
}
