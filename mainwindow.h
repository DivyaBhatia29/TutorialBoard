#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QListWidgetItem>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

private slots:
    void on_redColorButton_clicked();

    void on_greenColorButton_clicked();

    void on_blueColorButton_clicked();

    void on_blackColorButton_clicked();

    void on_lineButton_clicked();

    void on_rectangleButton_clicked();

    void on_circleButton_clicked();

    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

    void mouseReleaseEvent(QMouseEvent *);
    void on_shapeList_itemSelectionChanged();

    void on_shapeList_itemClicked(QListWidgetItem *item);

    void on_clearButton_clicked();

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

    void on_groupButton_clicked();

    void on_ungroupButton_clicked();

    void on_saveButton_clicked();

    void on_openButton_clicked();

    void on_freehandButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
