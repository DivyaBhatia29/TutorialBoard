#include "tmview.h"
#include<mainwindow.h>
#include<QTextStream>
#include<QFile>
#include<QFileDialog>
#include<QJsonObject>
#include<QJsonDocument>
#include<QJsonArray>
#include<tmlinecomponent.h>
#include<tmrectanglecomponent.h>
#include<tmellipsecomponent.h>
#include<tmfreehandcomponent.h>
#include<QMessageBox>
#include<QString>
#include<QDebug>
QList<DrawableComponent *> list;
QList<QList<DrawableComponent *>*> groupList;
TMView::TMView()
{

}
int TMView::indexOf(DrawableComponent *dc)
{
    DrawableComponent *d;
    int i=0;
    while(i<list.size())
    {
        d=list[i];
        if(d==dc)
        {
            return i;
        }
        i++;
    }
    return -1;
}
void TMView::saveToFile(QMainWindow *mw)
{
    QString fileName = QFileDialog::getSaveFileName(mw,QString("Save Address Book"), "",   QString("All Files (*)"));

    if (fileName.isEmpty())
    {
            return;
     }
    else
    {
            QFile file(fileName);
            if (!file.open(QIODevice::WriteOnly))
            {
                QMessageBox::information(mw, QString("Unable to open file"), file.errorString());
                return;
            }
    }
    QJsonArray recordsArray;
    DrawableComponent *dc;
    int i=0;
    while(i<list.size())
    {
        QJsonObject  recordObject;
        dc=list[i];
        if(dc->toString()=="Line")
        {
            TMLineComponent *d;
            d=(TMLineComponent *)dc;
            recordObject.insert("type", QJsonValue::fromVariant("Line"));
            recordObject.insert("startX", QJsonValue::fromVariant(d->getStartX()));
            recordObject.insert("startY", QJsonValue::fromVariant(d->getStartY()));
            recordObject.insert("endX", QJsonValue::fromVariant(d->getEndX()));
            recordObject.insert("endY", QJsonValue::fromVariant(d->getEndY()));
            recordObject.insert("penwidth", QJsonValue::fromVariant(d->getPenWidth()));
            recordObject.insert("color", QJsonValue::fromVariant(d->getColor()));

        }
        if(dc->toString()=="Rectangle")
        {

            TMRectangleComponent *d;
            d=(TMRectangleComponent *)dc;
            recordObject.insert("type", QJsonValue::fromVariant("Rectangle"));
            recordObject.insert("x", QJsonValue::fromVariant(d->getX()));
            recordObject.insert("y", QJsonValue::fromVariant(d->getY()));
            recordObject.insert("width", QJsonValue::fromVariant(d->getWidth()));
            recordObject.insert("height", QJsonValue::fromVariant(d->getHeight()));
            recordObject.insert("penwidth", QJsonValue::fromVariant(d->getPenWidth()));
            recordObject.insert("color", QJsonValue::fromVariant(d->getColor()));


        }
        if(dc->toString()=="Circle")
        {

            TMEllipseComponent *d;
            d=(TMEllipseComponent *)dc;

            recordObject.insert("type", QJsonValue::fromVariant("Circle"));
            recordObject.insert("x", QJsonValue::fromVariant(d->getX()));
            recordObject.insert("y", QJsonValue::fromVariant(d->getY()));
            recordObject.insert("width", QJsonValue::fromVariant(d->getWidth()));
            recordObject.insert("height", QJsonValue::fromVariant(d->getHeight()));
            recordObject.insert("penwidth", QJsonValue::fromVariant(d->getPenWidth()));
            recordObject.insert("color", QJsonValue::fromVariant(d->getColor()));


        }
        if(dc->toString()=="Freehand")
        {
            TMFreehandComponent *d;
            d=(TMFreehandComponent *)dc;
            QList<int> *list=d->getFreehandList();
            int f=0;
            int c;
            QJsonArray *array=new QJsonArray();
            while(f<list->size())
            {
                c=list->at(f);
               array->push_back(c);
                f++;
            }
            recordObject.insert("color",QJsonValue::fromVariant(d->getColor()));
            recordObject.insert("penwidth",QJsonValue::fromVariant(d->getPenwidth()));
            recordObject.insert("type",QJsonValue::fromVariant("Freehand"));
            recordObject["Coordinates"]=*array;
        }

    recordsArray.push_back(recordObject);
    i++;
     }

    QFile file(fileName);
   file.open(QFile::WriteOnly);
   i=0;
   QJsonDocument json;
   json.setArray(recordsArray);
   file.write(json.toJson());
   file.close();
   QMessageBox::information(mw, QString("Confirm Dialog"),QString("Data Saved"));
}

void TMView::loadFromFile(QMainWindow( *mw))
{
     QString fileName=QFileDialog::getOpenFileName(mw,  QString("Open Address Book"), "", QString("All Files (*)"));

    if (fileName.isEmpty())
      {
        return;
      }
    else
    {
            QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly))
            {
                QMessageBox::information(mw, QString("Unable to open file"), file.errorString());
                return;
            }
    }
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
  //  QTextStream fileText(&file);
    QString jsonString;
    jsonString=file.readAll();
    QByteArray jsonBytes=jsonString.toLocal8Bit();
    QJsonDocument jsonDoc=QJsonDocument::fromJson(jsonBytes);

    if(jsonDoc.isNull())
    {
        qDebug()<<"json doc is null";
        exit(2);
    }
    if(!jsonDoc.isArray())
    {
        exit(3);
    }

  QJsonArray jsonArray=jsonDoc.array();
  /*
  if(jsonArray.isEmpty())
    {
        exit(4);
    }
*/


   int i=0;
    clear();
    DrawableComponent *dc;
    TMLineComponent *line;
    TMEllipseComponent *ellipse;
    TMRectangleComponent *rectangle;
    TMFreehandComponent *freehand;
    while(i<jsonArray.count())
    {

        qDebug()<<"loop started";
    QJsonObject jsonObject=jsonArray.at(i).toObject();
    if(jsonObject.isEmpty())
    {
        exit(4);
    }
    QString type=jsonObject["type"].toString();
        if(type=="Line")
        {

            line=new TMLineComponent();
            line->setStartX(jsonObject["startX"].toInt());
            line->setEndX(jsonObject["endX"].toInt());
            line->setStartY(jsonObject["startY"].toInt());
            line->setEndY(jsonObject["endY"].toInt());
            line->setPenWidth(jsonObject["penwidth"].toInt());
            line->setColor(jsonObject["color"].toInt());
            add(line);
        }
        if(type=="Rectangle")
        {
                rectangle=new TMRectangleComponent();
                rectangle->setX(jsonObject["x"].toInt());
                rectangle->setY(jsonObject["y"].toInt());
                rectangle->setWidth(jsonObject["width"].toInt());
                rectangle->setHeight(jsonObject["height"].toInt());
                rectangle->setPenWidth(jsonObject["penwidth"].toInt());
                rectangle->setColor(jsonObject["color"].toInt());
                add(rectangle);
        }
        if(type=="Circle")
        {
                ellipse=new TMEllipseComponent();
                ellipse->setX(jsonObject["x"].toInt());
                ellipse->setY(jsonObject["y"].toInt());
                ellipse->setWidth(jsonObject["width"].toInt());
                ellipse->setHeight(jsonObject["height"].toInt());
                ellipse->setPenWidth(jsonObject["penwidth"].toInt());
                ellipse->setColor(jsonObject["color"].toInt());
                add(ellipse);

        }
        if(type=="Freehand")
        {
                freehand=new TMFreehandComponent();
                QJsonArray array=jsonObject["Coordinates"].toArray();
                QList<int> freehandList;
                int f=0;
                int c;
                while(f<array.count())
                {
                    c=array.at(f).toInt();
                    freehandList.push_back(f);
                    f++;
                }
                freehand->setPenwidth(jsonObject["penwidth"].toInt());
                freehand->setColor(jsonObject["color"].toInt());
                freehand->setFreehandList(&freehandList);
                add(freehand);
        }
    i++;
    }

}

void TMView::removeGroup(QList<DrawableComponent *> *listToDegroup)
{
    int i=0;
    while(i<groupList.size())
    {
        if(groupList[i]==listToDegroup)
        {
            groupList.removeAt(i);
            break;
        }
        i++;
    }
}
int TMView::populateIGL(QList<int> *selectedList)
{
    int i=0;
    DrawableComponent *dc;
    QList<DrawableComponent *> *individualGroupList;
    individualGroupList=new QList<DrawableComponent *>();
    while(i<selectedList->size())
    {
        int row=selectedList->at(i);
        dc=getComponent(row);
        individualGroupList->push_back(dc);
        i++;
    }
    groupList.push_back(individualGroupList);
    return groupList.size();
}


QList<DrawableComponent *> * TMView::ifMemberOfAnyGroup(DrawableComponent *dc)
{
    QList<DrawableComponent *> *igl;
    DrawableComponent *dc1;
    int i=0;
while(i<groupList.size())
{
    igl=groupList[i];
    int j=0;
    while(j<igl->size())
    {
        dc1=igl->at(j);
        if(dc1==dc)
        {
            return igl;
        }
        j++;
    }
    i++;

}
return nullptr;
}

void TMView::add(DrawableComponent *d)
{
    list.push_back(d);
}

DrawableComponent* TMView::getComponent(int index)
{
    return list[index];
}

int TMView::processClick(int x, int y, QPainter *painter)
{
    DrawableComponent *dc;
    int i=0;
    bool exist;
    qDebug()<<"In process click";
    while(i<list.size())
    {
        dc=list[i];
        exist=dc->isOwnedByYou(x,y);
        qDebug()<<exist;
        qDebug()<<"in process click in while loop after is owned by you";
        if(exist==true)
        {

            qDebug()<<"in process click in while loop after in if exists condition";
            dc->select(painter);
            qDebug()<<"After select in process click";
            return i;
        }
        i++;
    }
     return -1;
}

void TMView::clear()
{
    int i=0;
    while(i<list.size())
    {
        list.removeOne(list[i]);

    }
    }
int TMView::getSize()
{
    return list.size();
}
void TMView::drawViewExcept(QPainter *painter,DrawableComponent *dc)
{
    DrawableComponent *d;
    painter->eraseRect(10,10,600,600);
    QRectF rect(170,30,1400,911);
    QPen pen(Qt::black);
    pen.setWidth(10);
    painter->setPen(pen);
    painter->setBrush(QBrush(Qt::white));
    painter->fillRect(rect,Qt::SolidPattern);
    painter->drawRect(rect);

    int i=0;
    while(i<list.size())
    {
        d=list[i];
        if(d!=dc)
        {
        d->draw(painter);
        }
        i++;
        //MainWindow m;
        //m.update();
    }

}

void TMView::drawViewExcept(QPainter *painter, QList<DrawableComponent *> *listToDraw)
{
    DrawableComponent *d;
    painter->eraseRect(10,10,600,600);
    QRectF rect(170,30,1400,911);
    QPen pen(Qt::black);
    pen.setWidth(10);
    painter->setPen(pen);
    painter->setBrush(QBrush(Qt::white));
    painter->fillRect(rect,Qt::SolidPattern);
    painter->drawRect(rect);
    DrawableComponent *dc;
    DrawableComponent *dc1;
    QList<DrawableComponent *> tempList;
    int i=0;
    while(i<list.size())
    {
        dc=list[i];
        int j=0;
        while(j<listToDraw->size())
        {
            dc1=listToDraw->at(j);
            if(dc==dc1)
            {
                break;
            }
            j++;
        }
        if(j==listToDraw->size())
        {
            tempList.push_back(dc);
        }
        i++;
    }

    i=0;
    while(i<tempList.size())
    {
        dc=tempList[i];
        dc->draw(painter);
        i++;
    }
}

void TMView::drawView(QPainter *painter)
{
   DrawableComponent *d;
   painter->eraseRect(10,10,600,600);
   QRectF rect(170,30,1400,911);
   QPen pen(Qt::black);
   pen.setWidth(10);
   painter->setPen(pen);
   painter->setBrush(QBrush(Qt::white));
   painter->fillRect(rect,Qt::SolidPattern);
   painter->drawRect(rect);

   int i=0;
   while(i<list.size())
   {
       d=list[i];
       d->draw(painter);
       i++;
       //MainWindow m;
       //m.update();
   }


}
