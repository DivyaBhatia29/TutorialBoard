#ifndef TMLINECOMPONENT_H
#define TMLINECOMPONENT_H
#include "tmview.h"
#include "drawablecomponent.h"

class TMLineComponent : public DrawableComponent
{
public:
    TMLineComponent();
    int getStartX() const;
    void setStartX(int value);

    int getStartY() const;
    void setStartY(int value);

    int getEndX() const;
    void setEndX(int value);

    int getEndY() const;
    void setEndY(int value);

    int getPenWidth() const;
    void setPenWidth(int value);

    void draw(QPainter *p);

    int getColor() const;
    void setColor(int value);

    QString toString();
    bool isOwnedByYou(int x,int y);
    void select(QPainter *);
    void move(QPainter *,int,int,int,int);

private:
    int startX;
    int startY;
    int endX;
    int endY;
    int penWidth;
    int color;
};

#endif // TMLINECOMPONENT_H
