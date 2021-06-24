#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include<QPainter>

class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter *)=0;
    virtual QString toString()=0;
    virtual void select(QPainter *)=0;
    virtual bool isOwnedByYou(int x,int y)=0;
    virtual void move(QPainter *,int,int,int,int)=0;
};

#endif // DRAWABLECOMPONENT_H
