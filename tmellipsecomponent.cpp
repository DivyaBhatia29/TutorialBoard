#include "tmellipsecomponent.h"
#include<QtMath>
TMEllipseComponent::TMEllipseComponent()
{

}

int TMEllipseComponent::getX() const
{
    return x;
}

void TMEllipseComponent::setX(int value)
{
    x = value;
}

int TMEllipseComponent::getY() const
{
    return y;
}

void TMEllipseComponent::setY(int value)
{
    y = value;
}

int TMEllipseComponent::getWidth() const
{
    return width;
}

void TMEllipseComponent::setWidth(int value)
{
    width = value;
}

int TMEllipseComponent::getHeight() const
{
    return height;
}

void TMEllipseComponent::setHeight(int value)
{
    height = value;
}

int TMEllipseComponent::getPenWidth() const
{
    return penWidth;
}

void TMEllipseComponent::setPenWidth(int value)
{
    penWidth = value;
}

void TMEllipseComponent::draw(QPainter *painter)
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

    QRect ra(x,y,width,height);
painter->drawEllipse(ra);
}

int TMEllipseComponent::getColor() const
{
    return color;
}

void TMEllipseComponent::setColor(int value)
{
    color = value;
}
QString TMEllipseComponent::toString()
{
    return "Circle";
}

bool TMEllipseComponent::isOwnedByYou(int a,int b)
{
    int finalX,finalY;
    int cx,cy,radius,r;
    radius=width/2;
    cx=x+radius;
   cy=y+radius;
   //r=cx-a;
   r=qSqrt(((((a-cx)*(a-cx))+((b-cy)*(b-cy)))));

   if(r<radius)
   {
       return true;
   }
   else
   {
   return false;
}
   }
void TMEllipseComponent::select(QPainter *painter)
{
    int finalX,finalY;
    int cx,cy,radius;
   finalX=x+width;
   finalY=y+height;
   cx=(finalX+x)/2;
   cy=(finalY+y)/2;
   radius=width/2;
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawRect(cx-radius-10,cy-10,10,10);
    painter->drawRect(cx-10,cy-radius-10,10,10);
    painter->drawRect(cx+radius-10,cy-10,10,10);
    painter->drawRect(cx-10,cy+radius-10,10,10);

    QPen pen1;
    painter->setPen(pen1);

}

void TMEllipseComponent::move(QPainter *painter,int startX,int startY,int endX,int endY)
{
    int wd=startX-x;
    int hd=startY-y;
    x=endX-wd;
    y=endY-hd;

}
