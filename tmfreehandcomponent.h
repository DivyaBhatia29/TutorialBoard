#ifndef TMFREEHANDCOMPONENT_H
#define TMFREEHANDCOMPONENT_H
#include "drawablecomponent.h"
#include"tmview.h"

class TMFreehandComponent:public DrawableComponent
{
public:
    TMFreehandComponent();
    QList<int> *getFreehandList() const;
    void setFreehandList(QList<int> *value);
    void draw(QPainter *) ;
    bool isOwnedByYou(int x, int y) ;
    void select(QPainter *);
    void move(QPainter *, int, int, int, int) ;
    QString toString() ;
    int getColor() const;
    void setColor(int value);

    int getPenwidth() const;
    void setPenwidth(int value);

private:
    QList<int> *freehandList;
    int color;
    int penwidth;

};

#endif // TMFREEHANDCOMPONENT_H
