#include "tmrectanglecomponent.h"
#include<QPainter>
TMRectangleComponent::TMRectangleComponent()
{

}

int TMRectangleComponent::getX() const
{
    return x;
}

void TMRectangleComponent::setX(int value)
{
    x = value;
}

int TMRectangleComponent::getY() const
{
    return y;
}

void TMRectangleComponent::setY(int value)
{
    y = value;
}

int TMRectangleComponent::getWidth() const
{
    return width;
}

void TMRectangleComponent::setWidth(int value)
{
    width = value;
}

int TMRectangleComponent::getHeight() const
{
    return height;
}

void TMRectangleComponent::setHeight(int value)
{
    height = value;
}

int TMRectangleComponent::getPenWidth() const
{
    return penWidth;
}

void TMRectangleComponent::setPenWidth(int value)
{
    penWidth = value;
}

void TMRectangleComponent::draw(QPainter *painter)
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

    QRectF rectangle(x,y,width,height);
   painter->drawRect(rectangle);

}

int TMRectangleComponent::getColor() const
{
    return color;
}

void TMRectangleComponent::setColor(int value)
{
    color = value;
}
QString TMRectangleComponent::toString()
{
   return "Rectangle";
}

bool TMRectangleComponent::isOwnedByYou(int a,int b)
{
int finalX=x+width;
int finalY=x+height;
if(a>x && a<finalX && b>y && b<finalY)
{
    return true;
}
return false;
}
void TMRectangleComponent::select(QPainter *painter)
{
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    int finalX=x+width;
    int finalY=y+height;
    painter->drawRect(x-10,y-10,10,10);
    painter->drawRect(finalX,finalY,10,10);
    painter->drawRect(x-10,finalY,10,10);
    painter->drawRect(finalX,y-10,10,10);
}

void TMRectangleComponent::move(QPainter *painter,int startX,int startY,int endX,int endY)
{
    int wd=startX-x;
    int hd=startY-y;
    x=endX-wd;
    y=endY-hd;

}
