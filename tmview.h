#ifndef TMVIEW_H
#define TMVIEW_H
#include<drawablecomponent.h>
#include<QPainter>
#include<QMainWindow>
class TMView;

class TMView
{
private:
QList<DrawableComponent *> list;

public:
    TMView();
     void add(DrawableComponent *);
     int indexOf(DrawableComponent *);
     void drawView(QPainter *);
     int getSize();
     DrawableComponent * getComponent(int index);
     int  processClick(int x,int y,QPainter *);
     void clear();
     void drawViewExcept(QPainter *,DrawableComponent *);
     void drawViewExcept(QPainter *,QList<DrawableComponent *> *);
     int populateIGL(QList<int> *);
     void saveToFile(QMainWindow *);
     void loadFromFile(QMainWindow *);
     QList<DrawableComponent *> * ifMemberOfAnyGroup(DrawableComponent *dc);
     void removeGroup(QList<DrawableComponent *> *);
};

#endif // TMVIEW_H
