#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include<QKeyEvent>
#include<QThread>
#include<QTime>
#include<QTextEdit>
#include<QRect>
#include<QEasingCurve>
#include<QPropertyAnimation>
#include<QGraphicsRotation>
#include<QMatrix>
#include<QMovie>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QPixmap>
#include<QParallelAnimationGroup>
#include<QSlider>
 static int i=0;
 static int k=10;
 static int add=20;
 int si=100;
 int dy=0;int skin=1;
 int max=0;
 int normax=0;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    thread=new Mythread(this);
    connect(this,&Widget::destroyed,this,&Widget::stopthread);
    connect(thread,&Mythread::isDone,this,&Widget::dealdone);

     //背景音乐

     musicback=new QMediaPlayer;
     QMediaPlaylist*list=new QMediaPlaylist;
     list->addMedia(QUrl("qrc:/n/Music/Jump Back.mp3"));
     list->setPlaybackMode(QMediaPlaylist::Loop);
     musicback->setPlaylist(list);
     musicback->play();


     //计时窗口
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
    this->setWindowTitle("跳一跳模拟小程序");
    this->resize(1000,1000);
    ui->startbon->hide();
    ui->changebutton->hide();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->rebonlabel->hide();
    ui->readyBon->hide();


    //计时器
    mytimer=new QTimer(this);
    connect(mytimer,&QTimer::timeout,
            [=]()
            {
                i++;
                ui->lcdNumber->display(i);
            }
            );



    //按压按钮
    connect(ui->rebon,&QPushButton::clicked,
    [=]()
    {
        i=0;
        ui->lcdNumber->display(i);
    });
    ui->obj1label->move(30,50);
    ui->obj1label->resize(200,200);
    ui->obj1label->hide();
    ui->label->hide();


    music1=new QMediaPlayer;
    QMediaPlaylist*musicl=new QMediaPlaylist;
    musicl->addMedia(QUrl("qrc:/n/Music/jump.mp3"));
    music1->setPlaylist(musicl);
    music1->setVolume(100);

    QMovie*stmovie=new QMovie(":/Photo/start.gif");
    ui->startlabel->setMovie(stmovie);
    ui->startlabel->setScaledContents(1);
    stmovie->start();

}


void Widget::stopthread(){
    thread->quit();
    thread->wait();
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_startbon_pressed()
{
  mytimer->start(k);
  ui->label->resize(40,110);
  music1->play();
  //压缩动画
   QPropertyAnimation*animation11 = new QPropertyAnimation(ui->label, "geometry");
        animation11->setDuration(500);
        animation11->setStartValue(QRect(130,250, 40,110));
        animation11->setEndValue(QRect(125, 280, 50,90));
        animation11->setEasingCurve(QEasingCurve::Linear);
   QPropertyAnimation*animation12 = new QPropertyAnimation(ui->obj1label, "geometry");
        animation12->setDuration(500);
        animation12->setStartValue(QRect(30,250, 200, 200));
        animation12->setEndValue(QRect(30, 280, 200, 170));
        animation12->setEasingCurve(QEasingCurve::Linear);
   QParallelAnimationGroup*group=new QParallelAnimationGroup(this);
   group->addAnimation(animation11);
   group->addAnimation(animation12);
   group->start();
}



void Widget::dealdone()
{
    qsrand(QTime(num%21,num%13,num%50).secsTo(QTime::currentTime()));
    while((num=qrand()%600)<200);
    QString str=QString::number(num);str+=" ";str+=QString::number(num+60);
    ui->changebutton->setText(str);
    ui->startbon->show();
    ui->obj2label->move(50+num,50);
    ui->obj2label->resize(200,200);
    ui->obj2label->show();
    animation4 = new QPropertyAnimation(ui->obj2label, "geometry");
    {
        animation4->setDuration(1000);
        animation4->setStartValue(QRect(50+num,50, 200, 200));
        animation4->setEndValue(QRect(50+num,250, 200,200));
        animation4->setEasingCurve(QEasingCurve::OutElastic);
    }
    animation4->start();

}
void Widget::on_startbon_released()
{
    music1->stop();
    mytimer->stop();
    ui->startbon->hide();
    ui->label->show();
          animation1 = new QPropertyAnimation(ui->label, "geometry");
          animation1->setDuration(500);
          animation1->setStartValue(QRect(125, 280, 50,90));
          animation1->setEndValue(QRect(130+i/2, 50, 40,110));
          animation1->setEasingCurve(QEasingCurve::OutQuart);
          animation2 = new QPropertyAnimation(ui->label, "geometry");
          animation2->setDuration(500);
          animation2->setStartValue(QRect(130+i/2, 50, 40,110));
          animation2->setEasingCurve(QEasingCurve::OutQuart);

          animation3 = new QPropertyAnimation(ui->label, "geometry");
                animation3->setDuration(500);
                animation3->setStartValue(QRect(130+i, 250, 40,110));
                animation3->setEndValue(QRect(130,250,40,110));
                animation3->setEasingCurve(QEasingCurve::Linear);
          QPropertyAnimation* animation31 = new QPropertyAnimation(ui->obj2label, "geometry");
                animation31->setDuration(500);
                animation31->setStartValue(QRect(50+num, 250, 200, 200));
                animation31->setEndValue(QRect(30,250,200,200));
                animation31->setEasingCurve(QEasingCurve::Linear);
          QPropertyAnimation* animation32 = new QPropertyAnimation(ui->obj1label, "geometry");
                animation32->setDuration(500);
                animation32->setStartValue(QRect(30, 250, 200, 200));
                animation32->setEndValue(QRect(-1000,250,200,200));
                animation32->setEasingCurve(QEasingCurve::Linear);
          QParallelAnimationGroup*group3=new QParallelAnimationGroup(this);
          group3->addAnimation(animation3);
          group3->addAnimation(animation31);
          group3->addAnimation(animation32);




    angroup=new QSequentialAnimationGroup(this);
    angroup->addAnimation(animation1);
    angroup->addAnimation(animation2);
    QPropertyAnimation*animation13 = new QPropertyAnimation(ui->obj1label, "geometry");
         animation13->setDuration(500);
         animation13->setStartValue(QRect(30,280, 200, 170));
         animation13->setEndValue(QRect(30, 250, 200, 200));
         animation13->setEasingCurve(QEasingCurve::Linear);
     animation13->start();


    //成功
    if(i<=num+60&&i>=num)
    {
        value+=add;
        animation2->setEndValue(QRect(130+i,250,40,110));
        angroup->addAnimation(group3);
        angroup->start();
        ui->changebutton->setText("继续");
        ui->proBar->setValue(value);

        //过关
        if(value>=100)
        {
            ui->stackedWidget_2->setCurrentIndex(2);
        }
    }
    //失败
    else{
        if(i>num+60)animation2->setEndValue(QRect(2000,500,40,110));
        if(i<num)animation2->setEndValue(QRect(num,500,40,110));
        angroup->removeAnimation(group3);
        angroup->start();
        ui->changebutton->hide();

    }

}

void Widget::on_changebutton_clicked()
{
    thread->start();
    i=0;
    ui->lcdNumber->display(i);
    ui->obj1label->move(30,250);
}

//难度按钮
void Widget::on_eazy_clicked()
{
    ui->readyBon->show();
    k=10;
    add=34;
    ui->level->hide();
}
void Widget::on_hard_clicked()
{
    ui->readyBon->show();
    k=8;
    add=20;
    ui->level->hide();
}
void Widget::on_insane_clicked()
{
    ui->readyBon->show();
    k=5;
    add=20;
    ui->level->hide();
}
void Widget::on_demon_clicked()
{
    ui->readyBon->show();
    k=1;
    add=10;
    ui->level->hide();
}
//主菜单按钮  开始
void Widget::on_Mainbutton_clicked()
{


    //初始化
    ui->stackedWidget->setCurrentIndex(0);
    ui->changebutton->setText("给予通关区间");
    ui->level->show();
    ui->label->move(130,250);
    ui->startbon->hide();
    ui->changebutton->hide();
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->obj2label->hide();
    ui->obj1label->show();
    ui->label->hide();
    QMovie*omovie=new QMovie(":/Photo/loser.gif");
    ui->overlabel->setMovie(omovie);
    ui->overlabel->setScaledContents(1);
    omovie->start();
    //进度条
    ui->proBar->setMinimum(0);
    ui->proBar->setMaximum(100);
    ui->proBar->resize(850,50);
    value=0;
    ui->proBar->setValue(value);
    //第一个平台落地
    animation41 = new QPropertyAnimation(ui->obj1label, "geometry");
          animation41->setDuration(1000);
          animation41->setStartValue(QRect(30,50, 200, 200));
          animation41->setEndValue(QRect(30,250, 200,200));
          animation41->setEasingCurve(QEasingCurve::OutElastic);
          animation41->start();
}
//重置按钮
void Widget::on_rebon_clicked()
{

    ui->stackedWidget->setCurrentIndex(1);
    ui->rebonlabel->show();
}
//认输按钮
void Widget::on_button_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void Widget::on_OKButton_clicked()
{
    ui->rebonlabel->show();
   if(k==10) ui->eazy->close();
   if(k==8)  ui->hard->close();
   if(k==5)  ui->insane->close();
   //最终局
   if(k==1)
   {
       this->close();return;
   }
   ui->stackedWidget->setCurrentIndex(1);
   OKwidget*w=new OKwidget;
   w->setFixedSize(1000,1000);
   w->show();
}
void Widget::on_OKButton2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->rebonlabel->show();
}

void Widget::on_readyBon_clicked()
{
    ui->readyBon->hide();
    ui->changebutton->show();
    ui->label->show();
    animation40 = new QPropertyAnimation(ui->label, "geometry");
          animation40->setDuration(1000);
          animation40->setStartValue(QRect(130,0, 40,110));
          animation40->setEndValue(QRect(130,250, 40,110));
          animation40->setEasingCurve(QEasingCurve::OutElastic);
    animation40->start();
}

void Widget::on_NorBon_clicked()
{
    dy=0;
    Norwidget*norwidget;
    norwidget=new Norwidget;
    connect(norwidget,&Norwidget::norbacksignal,this,&Widget::dealback);
    norwidget->show();
    this->hide();

}
void Widget::dealback()
{
    this->show();
}

void Widget::on_DYButton_clicked()
{
    dy=1;
    Norwidget*norwidget;
    norwidget=new Norwidget;
    connect(norwidget,&Norwidget::norbacksignal,this,&Widget::dealback);
    norwidget->show();
    this->hide();

}

void Widget::on_pushButton_clicked()
{
    skin=1;
    QPixmap p(":/Photo/character.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_2_clicked()
{
    skin=2;
    QPixmap p(":/Photo/chara2.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_3_clicked()
{
    skin=3;
    QPixmap p(":/Photo/chara3.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_4_clicked()
{
    skin=4;
    QPixmap p(":/Photo/chara5.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_5_clicked()
{
    skin=5;
    QPixmap p(":/Photo/chara4.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_pushButton_6_clicked()
{
    skin=6;
    QPixmap p(":/Photo/chara6.png");
    ui->label->setPixmap(p);
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_skinbon_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Widget::on_opButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    connect(ui->backmusic,&QSlider::valueChanged,
            [=]()
    {
        int vo=ui->backmusic->value();
        musicback->setVolume(vo);
    }

            );

}

void Widget::on_pushButton_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);

}
