#ifndef NORWIDGET_H
#define NORWIDGET_H

#include <QWidget>
#include <QTimer>
#include<QSequentialAnimationGroup>
#include<QPropertyAnimation>
#include<QMediaPlayer>
namespace Ui {
class Norwidget;
}

class Norwidget : public QWidget
{
    Q_OBJECT
signals:
    void norbacksignal();
    void stsignal();
public:

    explicit Norwidget(QWidget *parent = nullptr);
    ~Norwidget();

private slots:
    void on_norbackbon_clicked();
    void dealsig();
    void on_NORBON_pressed();
    void deal();
    void deal1();
    void on_NORBON_released();

    void on_ScoButton_clicked();

private:
    Ui::Norwidget *ui;
    int num;
    QTimer*nortimer;
    QTimer*ditimer;//动态
    QTimer*scotimer;
    QMediaPlayer *music;
    QSequentialAnimationGroup*angroup;
    QPropertyAnimation *animation1;
    QPropertyAnimation *animation2;
    QPropertyAnimation *animation3;
    QPropertyAnimation *animation4;
    QPropertyAnimation *animation40;
    QPropertyAnimation *animation41;
    QPropertyAnimation* animation61;
     QPropertyAnimation* animation62 ;
      QPropertyAnimation* animation63;
    QSequentialAnimationGroup*scodynamic;
};

#endif // NORWIDGET_H
