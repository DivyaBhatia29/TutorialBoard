#ifndef TMRECTANGLECOMPONENT_H
#define TMRECTANGLECOMPONENT_H
#include "drawablecomponent.h"

class TMRectangleComponent : public DrawableComponent
{
public:
    TMRectangleComponent();
    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getWidth() const;
    void setWidth(int value);

    int getHeight() const;
    void setHeight(int value);

    int getPenWidth() const;
    void setPenWidth(int value);

    void draw(QPainter *);


    int getColor() const;
    void setColor(int value);

    QString toString();
    bool isOwnedByYou(int x,int y);
    void select(QPainter *);
    void move(QPainter *,int,int,int,int);

private:
    int x;
    int y;
    int width;
    int height;
    int penWidth;
    int color;
};

#endif // TMRECTANGLECOMPONENT_H
