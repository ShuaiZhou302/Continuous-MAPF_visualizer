#include "agent.h"
#include <QColor>
agent::agent(int size)
{
    active=2;
    this->size=size;
}

QRectF agent::boundingRect() const
{
    return QRectF(0,0,size,size);
}

void agent::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color;
    QRectF rect = boundingRect();
    if(active==1)
    {
        QPen pen(Qt::red, 1);
        painter->setPen(pen);
        painter->setBrush(Qt::red);
        painter->drawEllipse(rect);
        QPen pen2(Qt::black, 1);
        painter->setPen(pen2);
        painter->drawLine(QPointF(0,0), QPointF(5,5));
    }
    else if(active==2)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush = QBrush(color.fromRgb(255,165,0), style);
        painter->setBrush(brush);
        painter->drawEllipse(rect);
        QPen pen2(Qt::black, 3);
        if(size<10)
            pen2.setWidth(2);
        painter->setPen(pen2);
        //painter->drawLine(QPointF(size-1,size/2), QPointF(size/2,size/2));
    }
    else if(active==3)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        Qt::BrushStyle style = Qt::SolidPattern;
        QBrush brush = QBrush(Qt::green, style);
        painter->setBrush(brush);
        painter->drawEllipse(rect);
        QPen pen2(Qt::black, 3);
        if(size<10)
            pen2.setWidth(2);
        painter->setPen(pen2);
        //painter->drawLine(QPointF(size-1,size/2), QPointF(size/2,size/2));
    }
    else
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);
        painter->setBrush(Qt::blue);
        painter->drawEllipse(rect);
        QPen pen2(Qt::black, 1);
        painter->setPen(pen2);
        painter->drawLine(QPointF(0,0), QPointF(5,5));
    }
}

void agent::setActive(int active)
{
    this->active=active;
}


target::target(int size)
{
    active=2;
    this->size=size;
}

QRectF target::boundingRect() const
{
    return QRectF(0,0,size,size);
}

void target::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    if(active==1)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        painter->setBrush(Qt::green);
        painter->drawRect(rect);
    }
    else if(active==2)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        painter->setBrush(Qt::blue);
        painter->drawRect(rect);
    }
}

void target::setActive(int active)
{
    this->active=active;
}

