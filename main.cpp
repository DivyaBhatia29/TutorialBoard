#include "mainwindow.h"

#include <QApplication>
#include<QSplashScreen>
#include<QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap pixmap(":/images/splah4.png");
    QSplashScreen splash(pixmap,Qt::WindowStaysOnTopHint);
    splash.showMaximized();
    MainWindow w;
    QTimer::singleShot(2500,&splash,&QWidget::close);
    QTimer::singleShot(2500,&w,&QWidget::show);
    w.showFullScreen();
    return a.exec();
}
