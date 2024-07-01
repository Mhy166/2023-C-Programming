#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTimer>
#include<mythread.h>
#include<QSequentialAnimationGroup>
#include<QPropertyAnimation>
#include"okwidget.h"
#include"norwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startbon_pressed();
    void on_startbon_released();
    void on_changebutton_clicked();

    void dealback();
    void on_eazy_clicked();
    void on_hard_clicked();
    void on_insane_clicked();
    void on_demon_clicked();

    void dealdone();
    void stopthread();


    void on_Mainbutton_clicked();

    void on_rebon_clicked();

    void on_button_clicked();

    void on_OKButton_clicked();

    void on_OKButton2_clicked();

    void on_readyBon_clicked();

    void on_NorBon_clicked();

private:

    Ui::Widget *ui;
    QTimer *mytimer;
    Mythread *thread;
    int num;
    int ran;
    int value;
    QSequentialAnimationGroup*angroup;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QPropertyAnimation *animation4;
    QPropertyAnimation *animation40;
    QPropertyAnimation *animation41;


};
#endif // WIDGET_H
