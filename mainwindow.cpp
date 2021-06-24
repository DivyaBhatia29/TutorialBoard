#include<iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QMouseEvent>
#include<QFileDialog>
#include<QMessageBox>
#include "tmlinecomponent.h"
#include "tmellipsecomponent.h"
#include "tmrectanglecomponent.h"
#include "drawablecomponent.h"
#include"tmfreehandcomponent.h"
#include <QtMath>
#include<QDebug>
using namespace std;
int color=4;
TMView view;
int flag=0;
int startX;
int startY;
int endX;
int endY;
int j=0;
int e=0;
int tempX;
int tempY;
int t=0;
int z=0;
int m=0;
int p=0;
int ser;
int change;
int select=0;
TMLineComponent *line;
TMRectangleComponent *rectangle;
TMEllipseComponent *ellipse;
TMFreehandComponent *freehandC;
QPainter *painter;
QList<int> *selectedList=nullptr;
QList<DrawableComponent *> *listToSelect=nullptr;
QList<DrawableComponent *> *listToMove=nullptr;
QList<DrawableComponent *> *listToDraw=nullptr;
QList<DrawableComponent *> *listToDegroup=nullptr;
int a=0;
int u=0;
int q=0;
int group=0;
int ungroup=0;
int mulSel=0;
int draw=0;
QList<int> *freehand=nullptr;
QList<int> *freehandOld=nullptr;
//QVector<QVector<int>> freehand;
#define PI 3.14159265
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->testLabel->setVisible(false);
    QPixmap linePixmap(":/images/line_icon.png");
    QIcon lineIcon(linePixmap);
    this->ui->lineButton->setIcon(lineIcon);
    QPixmap circlePixmap(":/images/circle2_icon.png");
    QIcon circleIcon(circlePixmap);
    this->ui->circleButton->setIcon(circleIcon);
    QPixmap rectanglePixmap(":/images/rectangle_icon.png");
    QIcon rectangleIcon(rectanglePixmap);
    this->ui->rectangleButton->setIcon(rectangleIcon);
    QPixmap savePixmap(":/images/save_icon.png");
    QIcon saveIcon(savePixmap);
    this->ui->saveButton->setIcon(saveIcon);
    QPixmap openPixmap(":/images/open_icon.png");
    QIcon openIcon(openPixmap);
    this->ui->openButton->setIcon(openIcon);
    QPixmap groupPixmap(":/images/group_icon.png");
    QIcon groupIcon(groupPixmap);
    this->ui->groupButton->setIcon(groupIcon);
    QPixmap ungroupPixmap(":/images/degroup_icon.png");
    QIcon ungroupIcon(ungroupPixmap);
    this->ui->ungroupButton->setIcon(ungroupIcon);
    QPixmap clearPixmap(":/images/clear_icon.png");
    QIcon clearIcon(clearPixmap);
    this->ui->clearButton->setIcon(clearIcon);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
   QPainter painter(this);
   QRectF rect(170,30,1400,911);
   QPen pen(Qt::black);
   pen.setWidth(10);
   painter.setPen(pen);
   painter.setBrush(QBrush(Qt::white));
   painter.fillRect(rect,Qt::SolidPattern);
   painter.drawRect(rect);
   //view.drawView(&painter);

   if(color==1)
   {
      QPen pen(Qt::red);
      pen.setWidth(4);
      painter.setPen(pen);
   }
   if(color==2)
   {
      QPen pen(Qt::green);
      pen.setWidth(4);
      painter.setPen(pen);
   }if(color==3)
   {
      QPen pen(Qt::blue);
      pen.setWidth(4);
      painter.setPen(pen);
   }if(color==4)
   {
      QPen pen(Qt::black);

      pen.setWidth(4);
      painter.setPen(pen);
   }

   if(draw==1)
   {
       view.drawView(&painter);
       draw=0;
       //return;
   }
  this->ui->shapeList->setSelectionMode(QAbstractItemView::SingleSelection);
   qDebug()<<"paintEvent started";
   if(flag==6)
   {
       qDebug()<<"Entered in flag==6";
       if(t==1)
       {
           qDebug()<<"Entered in t==1";

           if(color==1)
           {
              QPen pen(Qt::red);
              pen.setWidth(4);
              painter.setPen(pen);
           }
           if(color==2)
           {
              QPen pen(Qt::green);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==3)
           {
              QPen pen(Qt::blue);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==4)
           {
               cout<<"Entered in color==4";
              QPen pen(Qt::black);
              pen.setWidth(4);
              painter.setPen(pen);
           }

           view.drawView(&painter);
           if(freehand==nullptr)
           {
               freehand=new QList<int>;
               freehand->push_back(startX);
               freehand->push_back(startY);
           }
           freehand->push_back(tempX);
           freehand->push_back(tempY);
            view.drawView(&painter);
           int i=2;
           int x1,x2,y1,y2;
           x1=freehand->at(0);
           y1=freehand->at(1);
           while(i<freehand->size()-2)
           {
               cout<<"Entered in while loop";
           x2=freehand->at(i);
            i++;
            y2=freehand->at(i);
            i++;
             painter.drawLine(x1,y1,x2,y2);
             x1=x2;
              y1=y2;
           }

           t=0;
       }
       if(j==1)
       {
           freehand->push_back(endX);
           freehand->push_back(endY);
         freehandC=new TMFreehandComponent();
         freehandC->setFreehandList(freehand);
        freehandC->setColor(color);

         freehand=nullptr;
         view.add(freehandC);
         view.drawView(&painter);
         qDebug()<<"exit from j";
         a=1;
           j=0;
       }
   }

   if(flag==1)
   {
       if(t==1)
       {
           view.drawView(&painter);
           if(color==1)
           {
              QPen pen(Qt::red);
              pen.setWidth(4);
              painter.setPen(pen);
           }
           if(color==2)
           {
              QPen pen(Qt::green);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==3)
           {
              QPen pen(Qt::blue);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==4)
           {
              QPen pen(Qt::black);
              pen.setWidth(4);
              painter.setPen(pen);
           }
         painter.drawLine(startX,startY,tempX,tempY);
       //  view.drawView(&painter);
          t=0;
       }
       if(j==1)
       {
       line=new TMLineComponent();
       line->setStartX(startX);
       line->setStartY(startY);
       line->setEndX(endX);
       line->setEndY(endY);
       line->setColor(color);
       view.add(line);
       view.drawView(&painter);
       a=1;
       j=0;

       }
   }

   if(flag==2)
   {

       if(t==1)
       {
           view.drawView(&painter);
           if(color==1)
           {
              QPen pen(Qt::red);
              pen.setWidth(4);
              painter.setPen(pen);
           }
           if(color==2)
           {
              QPen pen(Qt::green);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==3)
           {
              QPen pen(Qt::blue);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==4)
           {
              QPen pen(Qt::black);
              pen.setWidth(4);
              painter.setPen(pen);
           }
           painter.drawRect(startX,startY,tempX-startX,tempY-startY);
           //view.drawView(&painter);
           t=0;

       }

       if(j==1)
       {
           rectangle=new TMRectangleComponent();
           rectangle->setX(startX);
           rectangle->setY(startY);
           rectangle->setWidth(endX-startX);
           rectangle->setHeight(endY-startY);
           rectangle->setColor(color);
           view.add(rectangle);
           view.drawView(&painter);
          a=1;
           j=0;

       }
   }

   if(flag==3)
   {
       if(t==1)
       {
           view.drawView(&painter);
           if(color==1)
           {
              QPen pen(Qt::red);
              pen.setWidth(4);
              painter.setPen(pen);
           }
           if(color==2)
           {
              QPen pen(Qt::green);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==3)
           {
              QPen pen(Qt::blue);
              pen.setWidth(4);
              painter.setPen(pen);
           }if(color==4)
           {
              QPen pen(Qt::black);
              pen.setWidth(4);
              painter.setPen(pen);
           }

//           int radius=tempX-startX;
  //float radius=qSqrt(((tempX-startX)^2)+((tempY-startY)^2));
           int radius=(qSqrt(((tempX-startX)*(tempX-startX))+((tempY-startY)*(tempY-startY))));
           int q=0;
  float x1,y1,x2,y2;
  float pie=3.14159265/180;
  while(q<360)
  {
      x1=radius* cos(pie*q)+startX;
      y1=radius* sin(pie*q)+startY;
      q=q+1;
      x2=radius* cos(pie*q)+startX;
      y2=radius* sin(pie*q)+startY;
      painter.drawLine(x1,y1,x2,y2);
  }
   t=0;
       }
       if(j==1)
       {
           ellipse=new TMEllipseComponent();
       int radius=(qSqrt(((endX-startX)*(endX-startX))+((endY-startY)*(endY-startY))));
           ellipse->setX(startX-radius);
           ellipse->setY(startY-radius);
           ellipse->setWidth(2*radius);
           ellipse->setHeight(2*radius);
           ellipse->setColor(color);
           view.add(ellipse);
           view.drawView(&painter);
           a=1;
           j=0;

       }

   }
   if(flag==4)
   {
       view.clear();
       this->ui->shapeList->clear();
       update();
   }

   if(flag==5)
   {
       if(t==1)
       {

           int ri=view.processClick(startX,startY,&painter);
           DrawableComponent *dc=view.getComponent(ri);
           listToDraw=view.ifMemberOfAnyGroup(dc);
           if(listToDraw!=nullptr)
           {

               view.drawViewExcept(&painter,listToDraw);

               int i=0;
           while(i<listToDraw->size())
           {
               dc=listToDraw->at(i);
               QString type=dc->toString();
               if(type=="Line")
               {
                   line=(TMLineComponent *)dc;
                   int wd1=startX-line->getStartX();
                   int hd1=startY-line->getStartY();
                   int wd2=line->getEndX()-startX;
                   int hd2=line->getEndY()-startY;
                   int x1=tempX-wd1;
                   int y1=tempY-hd1;
                   int x2=tempX+wd2;
                   int y2=tempY+hd2;

                   painter.drawLine(x1,y1,x2,y2);
               }
               if(type=="Rectangle")
               {

                    rectangle=(TMRectangleComponent *)dc;
                    int wd=startX-rectangle->getX();
                    int hd=startY-rectangle->getY();
                    int width=rectangle->getWidth();
                    int height=rectangle->getHeight();
                    int x=tempX-wd;
                    int y=tempY-hd;
                    painter.drawRect(x,y,width,height);

               }

               if(type=="Circle")
               {
                   ellipse=(TMEllipseComponent *)dc;
                   int wd=startX-ellipse->getX();
                   int hd=startY-ellipse->getY();
                   int x=tempX-wd;
                   int y=tempY-hd;
                   int width=ellipse->getWidth();
                   int height=ellipse->getHeight();
                   painter.drawEllipse(x,y,width,height);
               }

               if(type=="Freehand")
               {
                   qDebug()<<"Entered in t==1 and e==1 and type=freehand";
                   freehandC=(TMFreehandComponent *)dc;
                   freehandOld=freehandC->getFreehandList();
                  freehand=new QList<int>;
                  int f=0;
                  int x,y;
                  int wd,hd,x2,y2;
                  while(f<freehandOld->size()-2)
                  {
                      x=freehandOld->at(f);
                      f++;
                      y=freehandOld->at(f);
                      f++;
                      wd=startX-x;
                      hd=startY-y;
                      x2=tempX-wd;
                      y2=tempY-hd;
                      freehand->push_back(x2);
                      freehand->push_back(y2);
                  }
                   f=2;
                  int x1,y1;
                  x1=freehand->at(0);
                  y1=freehand->at(1);
                  while(f<freehand->size()-2)
                  {
                      cout<<"Entered in while loop";
                  x2=freehand->at(f);
                   f++;
                   y2=freehand->at(f);
                   f++;
                    painter.drawLine(x1,y1,x2,y2);
                    x1=x2;
                     y1=y2;
                  }
                   freehand=nullptr;

                   /*
                    * freehandOld=freehandC->getFreehandList();
                   int oldStartX=freehandOld->at(0);
                   int oldStartY=freehandOld->at(1);
                   int wd=startX-oldStartX;
                   int hd=startX-oldStartY;
                   freehand=new QList<int>;
                   freehand->push_back(startX);
                   freehand->push_back(startY);
                   int f=2;
                   int x,y;
                   while(f<freehandOld->size())
                   {
                       x=freehandOld->at(f);
                       f++;
                       y=freehandOld->at(f);
                       f++;
                       freehand->push_back(x+wd);
                       freehand->push_back(y+hd);
                   }
                    f=2;
                   int x1,x2,y1,y2;
                   x1=freehand->at(0);
                   y1=freehand->at(1);
                   while(f<freehand->size()-2)
                   {
                       cout<<"Entered in while loop";
                   x2=freehand->at(f);
                    f++;
                    y2=freehand->at(f);
                    f++;
                     painter.drawLine(x1,y1,x2,y2);
                     x1=x2;
                      y1=y2;
                   }
                    freehand=nullptr;
*/
               }
               i++;
           }
           listToDraw=nullptr;
            }
           else
           {

               QString type=dc->toString();
               //int oldX=0;
               //int oldY=0;
               if(type=="Line")
               {
                   line=(TMLineComponent *)dc;
                   int wd1=startX-line->getStartX();
                   int hd1=startY-line->getStartY();
                   int wd2=line->getEndX()-startX;
                   int hd2=line->getEndY()-startY;
                   int x1=tempX-wd1;
                   int y1=tempY-hd1;
                   int x2=tempX+wd2;
                   int y2=tempY+hd2;

                   view.drawViewExcept(&painter,line);
                   painter.drawLine(x1,y1,x2,y2);
               }
               if(type=="Rectangle")
               {

                    rectangle=(TMRectangleComponent *)dc;
                    int wd=startX-rectangle->getX();
                    int hd=startY-rectangle->getY();
                    int width=rectangle->getWidth();
                    int height=rectangle->getHeight();
                    int x=tempX-wd;
                    int y=tempY-hd;
                    view.drawViewExcept(&painter,rectangle);
                    painter.drawRect(x,y,width,height);

               }

               if(type=="Circle")
               {
                   ellipse=(TMEllipseComponent *)dc;
                   int wd=startX-ellipse->getX();
                   int hd=startY-ellipse->getY();
                   int x=tempX-wd;
                   int y=tempY-hd;
                   int width=ellipse->getWidth();
                   int height=ellipse->getHeight();
                   view.drawViewExcept(&painter,ellipse);
                   painter.drawEllipse(x,y,width,height);
               }

               if(type=="Freehand")
               {
                   qDebug()<<"Entered in t==1 and e==1 and type=freehand";

                   freehandC=(TMFreehandComponent *)dc;
                   view.drawViewExcept(&painter,freehandC);
                 //  freehand=freehandC->getFreehandList();
                   //freehandC=(TMFreehandComponent *)dc;
                    freehandOld=freehandC->getFreehandList();
                   freehand=new QList<int>;
                   int f=0;
                   int x,y;
                   int wd,hd,x2,y2;
                   while(f<freehandOld->size()-2)
                   {
                       x=freehandOld->at(f);
                       f++;
                       y=freehandOld->at(f);
                       f++;
                       wd=startX-x;
                       hd=startY-y;
                       x2=tempX-wd;
                       y2=tempY-hd;
                       freehand->push_back(x2);
                       freehand->push_back(y2);
                   }
                    f=2;
                   int x1,y1;
                   x1=freehand->at(0);
                   y1=freehand->at(1);
                   while(f<freehand->size()-2)
                   {
                       cout<<"Entered in while loop";
                   x2=freehand->at(f);
                    f++;
                    y2=freehand->at(f);
                    f++;
                     painter.drawLine(x1,y1,x2,y2);
                     x1=x2;
                      y1=y2;
                   }
                    freehand=nullptr;
                }
           }
         t=0;
       }

       if(j==1)
       {
           qDebug()<<"Entered in j==1";

           int ri=view.processClick(startX,startY,&painter);
           DrawableComponent *dc=view.getComponent(ri);

           listToMove=view.ifMemberOfAnyGroup(dc);
           if(listToMove!=nullptr)
           {
           int i=0;
           while(i<listToMove->size())
           {
               dc=listToMove->at(i);
               dc->move(&painter,startX,startY,endX,endY);
               i++;
           }
           listToMove=nullptr;
           }
           else
           {
               qDebug()<<"Entered in j==1 listToMove==nullptr";

           dc->move(&painter,startX,startY,endX,endY);
           }
           view.drawView(&painter);
           view.processClick(endX,endY,&painter);
           j=0;
           flag=1;
           select=0;
          p=0;
       }
/*
       if(z==1)
       {
       view.drawView(&painter);
       int row=view.processClick(startX,startY,&painter);
       this->ui->shapeList->item(row)->setSelected(true);
      select=1;
       z=0;
       return;
       }
*/
}
if(group==1)
{
if(mulSel==1)
{
    view.drawView(&painter);
    int i=view.populateIGL(selectedList);
    this->ui->testLabel->setText(QString::number(i));
    group=0;
  //  return;
}
}

if(ungroup==1)
{
    view.drawView(&painter);
    int row=view.processClick(startX,startY,&painter);
    DrawableComponent *dc=view.getComponent(row);
    listToDegroup=view.ifMemberOfAnyGroup(dc);
        if(listToDegroup!=nullptr)
    {
            int i=0;
            //DrawableComponent *dc;
            while(i<listToDegroup->size())
        {
                dc=listToDegroup->at(i);
                dc->select(&painter);
                i++;
            }

        view.removeGroup(listToDegroup);
    }
    ungroup=0;
}


   if(z==1)
   {
       view.drawView(&painter);
   if(e==1)
   {
       qDebug()<<"Entered in z==1 and e==1 ";

       view.drawView(&painter);
       if(selectedList==nullptr)
       {
          selectedList=new QList<int>();
       }
       this->ui->testLabel->setText("strating process click");
       int row=view.processClick(startX,startY,&painter);
       this->ui->testLabel->setText("end prpcess click");
       selectedList->push_back(row);
       int i=0;
       DrawableComponent *dc;
       view.drawView(&painter);
       this->ui->shapeList->setSelectionMode(QAbstractItemView::MultiSelection);
       this->ui->testLabel->setText("entering in while loop");
       while(i<selectedList->size())
       {
           row=selectedList->at(i);
           this->ui->shapeList->item(row)->setSelected(true);
           dc=view.getComponent(row);
           dc->select(&painter);
           i++;
       }

       z=0;
       mulSel=1;
       //return;
   }

  else
   {
       qDebug()<<"Entered in process click of else";

       view.drawView(&painter);
       int row=view.processClick(startX,startY,&painter);
       qDebug()<<"After process click of else";
       //this->ui->shapeList->item(row)->setSelected(true);
       if(row==-1)
       {
           view.drawView(&painter);
           this->ui->shapeList->setSelectionMode(QAbstractItemView::NoSelection);
       }
       else
       {
           view.drawView(&painter);
           qDebug()<<"After process click in else";

           int row=view.processClick(startX,startY,&painter);
           if(row>=0)
           {
               this->ui->shapeList->item(row)->setSelected(true);

           }
       DrawableComponent *dc=view.getComponent(row);
       listToSelect=view.ifMemberOfAnyGroup(dc);
       if(listToSelect!=nullptr)
       {
           this->ui->shapeList->setSelectionMode(QAbstractItemView::MultiSelection);
       int i=0;
       while(i<listToSelect->size())
       {

           dc=listToSelect->at(i);
           dc->select(&painter);
           int r=view.indexOf(dc);
           this->ui->shapeList->item(r)->setSelected(true);
           i++;
       }
       listToSelect=nullptr;
       //this->ui->shapeList->item(row)->setSelected(true);

       }
}
      if(selectedList!=nullptr)
      {
          selectedList->clear();
      }
      mulSel=0;

      select=1;
      z=0;
//      return;
   }
   }
   if(a==1)
   {
   DrawableComponent *component;

   int i=0;
   this->ui->shapeList->clear();
   while(i<view.getSize())
{
   component=view.getComponent(i);
   this->ui->shapeList->addItem(component->toString());
   i++;
   }
   a=0;
   }

        if(change==1)
   {

   int rowIndex=this->ui->shapeList->currentRow();
   DrawableComponent *d=view.getComponent(rowIndex);
   view.drawView(&painter);
   d->select(&painter);

   change=0;

   }


}

void MainWindow::on_redColorButton_clicked()
{
    color=1;
    //update();
}

void MainWindow::on_greenColorButton_clicked()
{
    color=2;
   // update();
}

void MainWindow::on_blueColorButton_clicked()
{
    color=3;
    //update();
}

void MainWindow::on_blackColorButton_clicked()
{
    color=4;
    //update();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
  if(flag==1 || flag==2 || flag==3 || flag==5 || flag==6)
  {
     startX=event->x();
     startY=event->y();
  }


}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
  if(flag==1 || flag==2 || flag==3 || flag==5 || flag==6)
  {
      tempX=event->x();
      tempY=event->y();
      if(select==1 && z==1)
      {
          flag=5;
      }

      t=1;
      update();
  }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

     if(flag==1 || flag==2 || flag==3 || flag==5 || flag==6)
     {
         endX=event->x();
         endY=event->y();

         if(startX!=endX && startY!=endY)
         {
             j=1;
         }
         else
         {
                 z=1;
         }
         if(select==1 && z==1)
         {
          flag=5;
         }
         update();

     }
}
void MainWindow::on_lineButton_clicked()
{
    flag=1;
    //update();
}

void MainWindow::on_rectangleButton_clicked()
{
    flag=2;
    //update();
}

void MainWindow::on_circleButton_clicked()
{
    flag=3;
    //update();
}

void MainWindow::on_shapeList_itemSelectionChanged()
{
   // change=1;
    //update();
}

void MainWindow::on_shapeList_itemClicked(QListWidgetItem *item)
{
    change=1;
    update();
}

void MainWindow::on_clearButton_clicked()
{
    flag=4;
    update();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->modifiers()==Qt::CTRL)
    {
        e=1;
       this->ui->testLabel->setText("control key pressed.");
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Control)
    {
        e=2;
        this->ui->testLabel->setText("control key released.");

    }

}


void MainWindow::on_groupButton_clicked()
{
    group=1;
    update();
}

void MainWindow::on_ungroupButton_clicked()
{
    ungroup=1;
    update();
}

void MainWindow::on_saveButton_clicked()
{
    view.saveToFile(this);
    this->ui->shapeList->clear();
}

void MainWindow::on_openButton_clicked()
{
    view.loadFromFile(this);
    int size=view.getSize();
    this->ui->testLabel->setText(QString::number(size));
    draw=1;
    update();
}

void MainWindow::on_freehandButton_clicked()
{
 flag=6;
 cout<<"value of flag=6";
 //update();
}
