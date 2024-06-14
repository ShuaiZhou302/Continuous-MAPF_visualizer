#ifndef AGENT_H
#define AGENT_H
#include <QGraphicsItem>
#include <QPainter>
class agent:public QGraphicsItem
{
public:
    agent(int size);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setActive(int active);
    int active;
    int size;
};

class target:public QGraphicsItem
{
public:
    target(int size);
    QRectF boundingRect() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    void setActive(int active);
    int active;
    double t;
    int size;

};

#endif // AGENT_H
