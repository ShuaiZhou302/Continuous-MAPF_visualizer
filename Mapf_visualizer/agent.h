#ifndef AGENT_H
#define AGENT_H
#include <QGraphicsItem>
#include <QPainter>
class agent:public QGraphicsItem
{
public:
    agent(int size,const QColor &color = QColor(255, 165, 0));
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setActive(int active);
    void setColor(const QColor &color);
    int active;
    int size;
    QColor color;
};

class target:public QGraphicsItem
{
public:
    target(int size);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setActive(int active);
    int active;
    double t;
    int size;

};

#endif // AGENT_H
