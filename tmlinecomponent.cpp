#include "tmlinecomponent.h"
#include<QPainter>

TMLineComponent::TMLineComponent()
{

}

int TMLineComponent::getStartX() const
{
    return startX;
}

void TMLineComponent::setStartX(int value)
{
    startX = value;
}

int TMLineComponent::getStartY() const
{
    return startY;
}

void TMLineComponent::setStartY(int value)
{
    startY = value;
}

int TMLineComponent::getEndX() const
{
    return endX;
}

void TMLineComponent::setEndX(int value)
{
    endX = value;
}

int TMLineComponent::getEndY() const
{
    return endY;
}

void TMLineComponent::setEndY(int value)
{
    endY = value;
}

int TMLineComponent::getPenWidth() const
{
    return penWidth;
}

void TMLineComponent::setPenWidth(int value)
{
    penWidth = value;
}

void TMLineComponent::draw(QPainter *painter)
{
    if(color==1)
    {
       QPen pen(Qt::red);
       pen.setWidth(4);
       painter->setPen(pen);
    }
    if(color==2)
    {
       QPen pen(Qt::green);
       pen.setWidth(4);
       painter->setPen(pen);
    }if(color==3)
    {
       QPen pen(Qt::blue);
       pen.setWidth(4);
       painter->setPen(pen);
    }if(color==4)
    {
       QPen pen(Qt::black);
       pen.setWidth(4);
       painter->setPen(pen);
    }
    painter->drawLine(startX,startY,endX,endY);

}

int TMLineComponent::getColor() const
{
    return color;
}

void TMLineComponent::setColor(int value)
{
    color = value;
}

QString TMLineComponent::toString()
{
    return "Line";
}
bool TMLineComponent::isOwnedByYou(int a,int b)
{

     if(a>startX && a<endX && b>startY && b<endY)
    {
        return true;
    }
    return false;
}
void TMLineComponent::select(QPainter *painter)
{
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawRect(startX-10,startY-10,10,10);
    painter->drawRect(endX,endY,10,10);
    QPen pen1;
    painter->setPen(pen1);
}

void TMLineComponent::move(QPainter *painter,int sx,int sy,int ex,int ey)
{
    int wd1=sx-startX;
    int hd1=sy-startY;
    int wd2=endX-sx;
    int hd2=endY-sy;
    startX=ex-wd1;
    startY=ey-hd1;
    endX=ex+wd2;
    endY=ey+hd2;

}
