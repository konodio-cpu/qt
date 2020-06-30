#include "enemy.h"
#include "way.h"
#include "tower.h"
#include "scene.h"


#include "collide.h"
//#include "audioplayer.h"



#include <QPainter>
#include <QColor>
#include <QDebug>
#include <QMatrix>
#include <QVector2D>
#include <QtMath>
static const int Health_Bar_Width = 20;

const QSize enemy::my_fixedSize(52, 30);

enemy::enemy(way *startWayPoint, scene *game)
    : QObject(0)
    , my_active(false)
    , my_maxHp(40)
    , my_currentHp(40)
    , my_walkingSpeed(1.0)
    , my_rotationSprite(0.0)
    , my_pos(startWayPoint->pos())
    , my_destinationWayPoint(startWayPoint->nextWayPoint())
    , my_game(game)

{
}

enemy::~enemy()
{
    my_attackedTowersList.clear();
    my_destinationWayPoint = NULL;
    my_game = NULL;
}

void enemy::doActivate()
{
    my_active = true;
}
//      inline bool collide(QPoint point1, int radius1, QPoint point2, int radius2)
void enemy::move()
{
    if (!my_active)
        return;

    if (collide(my_pos, 1, my_destinationWayPoint->pos(), 1))
    {
        // 敌人抵达了一个航点
        if (my_destinationWayPoint->nextWayPoint())
        {
            // 还有下一个航点
            my_pos = my_destinationWayPoint->pos();
            my_destinationWayPoint = my_destinationWayPoint->nextWayPoint();
        }
        else
        {
            // 表示进入基地
            my_game->getHpDamage();
            my_game->removedEnemy(this);
            return;
        }
    }

    // 还在前往航点的路上
    // 目标航点的坐标
    QPoint targetPoint = my_destinationWayPoint->pos();
    // 未来修改这个可以添加移动状态,加快,减慢,m_walkingSpeed是基准值

    // 向量标准化
    qreal movementSpeed = my_walkingSpeed;
    QVector2D normalized(targetPoint - my_pos);
    normalized.normalize();
    my_pos = my_pos + normalized.toPoint() * movementSpeed;

    // 确定敌人选择方向
    // 默认图片向左,需要修正180度转右
    my_rotationSprite = qRadiansToDegrees(qAtan2(normalized.y(), normalized.x()));
}

void enemy::draw(QPainter *painter) const
{
    //if (!my_active)
     //   return;

    painter->save();

    QPoint healthBarPoint = my_pos + QPoint(-Health_Bar_Width / 2 - 5, -my_fixedSize.height() / 3);
    // 绘制血条
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthBarBackRect(healthBarPoint, QSize(Health_Bar_Width, 2));
    painter->drawRect(healthBarBackRect);

    painter->setBrush(Qt::green);
    QRect healthBarRect(healthBarPoint, QSize((double)my_currentHp / my_maxHp * Health_Bar_Width, 2));
    painter->drawRect(healthBarRect);

    // 绘制偏转坐标,由中心+偏移=左上
    static const QPoint offsetPoint(-my_fixedSize.width() / 2, -my_fixedSize.height() / 2);
    painter->translate(my_pos);
    //painter->rotate(my_rotationSprite);
    // 绘制敌人
    painter->drawPixmap(offsetPoint, my_sprite);

    painter->restore();
}

void enemy::getRemoved()
{
    if (my_attackedTowersList.empty())
        return;

    foreach (tower *attacker, my_attackedTowersList)
        attacker->targetKilled();
    // 通知game,此敌人已经阵亡
    my_game->removedEnemy(this);
}

void enemy::getDamage(int damage)
{
    //m_game->audioPlayer()->playSound(LaserShootSound);
    my_currentHp -= damage;

    // 阵亡,需要移除
    if (my_currentHp <= 0)
    {
        //m_game->audioPlayer()->playSound(EnemyDestorySound);
        my_game->awardGold(10);
        getRemoved();
    }
}

void enemy::getAttacked(tower *attacker)
{
    my_attackedTowersList.push_back(attacker);
}

// 表明敌人已经逃离了攻击范围
void enemy::gotLostSight(tower *attacker)
{
    my_attackedTowersList.removeOne(attacker);
}

QPoint enemy::pos() const
{
    return my_pos;
}
