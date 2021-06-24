#include "tmfreehandcomponent.h"
#include<QDebug>


TMFreehandComponent::TMFreehandComponent()
{

}

QList<int> *TMFreehandComponent::getFreehandList() const
{
    return freehandList;
}

void TMFreehandComponent::setFreehandList(QList<int> *value)
{
    freehandList = value;
}

void TMFreehandComponent::draw(QPainter *painter)
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

    int i=2;
    int x1,x2,y1,y2;
    x1=freehandList->at(0);
    y1=freehandList->at(1);
    while(i<freehandList->size()-2)
    {
    x2=freehandList->at(i);
     i++;
     y2=freehandList->at(i);
     i++;
      painter->drawLine(x1,y1,x2,y2);
      x1=x2;
       y1=y2;
    }
qDebug()<<"After draw of freehand";
}

bool TMFreehandComponent::isOwnedByYou(int x, int y)
{
    int x1,y1;
    int i=0;
    while(i<freehandList->size()-2)
    {
        x1=freehandList->at(i);
        i++;
        y1=freehandList->at(i);
        i++;
        if((x1-3<x && x<x1+3) || (y1-3<y && y<y1+3))
        {
            return true;
        }
    }
 return false;
}

void TMFreehandComponent::select(QPainter *painter)
{
    QPen pen(Qt::red);
    pen.setWidth(5);
    painter->setPen(pen);
    painter->drawRect(200,200,30,30);
    int x1=freehandList->at(0);
    int y1=freehandList->at(1);
    int x2=freehandList->at(freehandList->size()-2);
    int y2=freehandList->at(freehandList->size()-1);
    painter->drawRect(x1,y1,10,10);
    painter->drawRect(x2,y2,10,10);

    QPen pen1;
    painter->setPen(pen1);

}

void TMFreehandComponent::move(QPainter *, int sx, int sy, int ex, int ey)
{
    int f=0;
    int x,y;
    int wd,hd,x2,y2;
    QList<int > *freehand;
    freehand=new QList<int>;

    while(f<freehandList->size()-2)
    {
        x=freehandList->at(f);
        f++;
        y=freehandList->at(f);
        f++;
        wd=sx-x;
        hd=sy-y;
        x2=ex-wd;
        y2=ey-hd;
        freehand->push_back(x2);
        freehand->push_back(y2);
    }
    freehandList=freehand;

}

QString TMFreehandComponent::toString()
{
return "Freehand";
}

int TMFreehandComponent::getColor() const
{
    return color;
}

void TMFreehandComponent::setColor(int value)
{
    color = value;
}

int TMFreehandComponent::getPenwidth() const
{
    return penwidth;
}

void TMFreehandComponent::setPenwidth(int value)
{
    penwidth = value;
}
