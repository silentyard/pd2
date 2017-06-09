#include "graphicsview.h"
#include"base.h"
#include"mana.h"
#include"basebullet.h"
#include"button.h"
#include"hero.h"
#include"heroicon.h"

#include"melee.h"
#include"caster.h"
#include"siege.h"
#include"super.h"
#include"storm.h"

#include"bluemeleeicon.h"
#include"purplemeleeicon.h"
#include<QDebug>
#include<QFont>

extern Hero *baron;
graphicsView::graphicsView():
    scene(new QGraphicsScene),
    summary(new QGraphicsScene),
    homepage(new QGraphicsScene),
    ranking(new QGraphicsScene),
    timer(new QTimer),
    cursor(nullptr),
    build(0)
{
    game_timer = new QTimer;
    connect(game_timer,SIGNAL(timeout()),this,SLOT(counting()));

    setScene(homepage);

    scene->setSceneRect(0,0,800,800);
    summary->setSceneRect(0,0,800,800);
    homepage->setSceneRect(0,0,800,800);
    ranking->setSceneRect(0,0,800,800);

    //Buttons
    Button *Start = new Button(QString("Start"));
    Start->setPos(500,700);
    homepage->addItem(Start);

    Button *Rank = new Button(QString("Rank"));
    Rank->setPos(250,700);
    homepage->addItem(Rank);

    Button *Back = new Button(QString("Back"));
    Back->setPos(500,700);
    summary->addItem(Back);

    Button *Back2 = new Button(QString("Back"));
    Back2->setPos(350,700);
    ranking->addItem(Back2);

    setFixedSize(800,850);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //rktime.resize(1);

    //debug

}

void graphicsView::setCursorPixmap(QString filename)
{
    if(cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem;
    cursor->setPixmap(QPixmap(filename).scaled(70,70));
    scene->addItem(cursor);
}

void graphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor)
        cursor->setPos(event->pos());
}

void graphicsView::mousePressEvent(QMouseEvent *event)
{
  if(event->button()==Qt::RightButton){
      if(cursor)
        scene->removeItem(cursor);
      cursor = nullptr;
      build=0;
  }
  switch(build){
  case 1:{
      if(bluemana->getnum()>=3){
          melee * bluemelee = new melee(1,event->x());
          bluemelee->setPos(event->pos());
          scene->addItem(bluemelee);
          bluemana->setnum(3);
          bluedeck->switchcard(build);
      }
      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 2:{
      if(purplemana->getnum()>=3){
          melee *purplemelee = new melee(0,event->x());
          purplemelee->setPos(event->pos());
          scene->addItem(purplemelee);
          purplemana->setnum(3);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 3:{
      if(bluemana->getnum()>=4){
          caster * bluecaster = new caster(1,event->x());
          bluecaster->setPos(event->pos());
          scene->addItem(bluecaster);
          bluemana->setnum(4);
          bluedeck->switchcard(build);
      }
      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 4:{
      if(purplemana->getnum()>=4){
          caster *purplecaster = new caster(0,event->x());
          purplecaster->setPos(event->pos());
          scene->addItem(purplecaster);
          purplemana->setnum(4);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 5:{
      if(bluemana->getnum()>=7){
          siege *bluesiege = new siege(1,event->x());
          bluesiege->setPos(event->pos());
          scene->addItem(bluesiege);
          bluemana->setnum(7);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 6:{
      if(purplemana->getnum()>=7){
          siege *purplesiege = new siege(0,event->x());
          purplesiege->setPos(event->pos());
          scene->addItem(purplesiege);
          purplemana->setnum(7);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 7:{
      if(bluemana->getnum()>=9){
          super *bluesuper = new super(1,event->x());
          bluesuper->setPos(event->pos());
          scene->addItem(bluesuper);
          bluemana->setnum(9);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 8:{
      if(purplemana->getnum()>=9){
          super *purplesuper = new super(0,event->x());
          purplesuper->setPos(event->pos());
          scene->addItem(purplesuper);
          purplemana->setnum(9);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  case 9:{
      if(bluemana->getnum()>=5){
          Storm *magic = new Storm;
          magic->setPos(event->pos()-QPointF(35,35));
          scene->addItem(magic);
          magic->shoot();
          bluemana->setnum(5);
          bluedeck->switchcard(build);
      }

      scene->removeItem(cursor);
      cursor = nullptr;
      build =0;
      break;
  }
  default:
      QGraphicsView::mousePressEvent(event);
  }
}

void graphicsView::keyPressEvent(QKeyEvent *key)
{
    if(baron){
        qDebug()<<"press";
        switch(key->key()){
        case Qt::Key_Space:{
            baron->attack();
            break;
        }
        case Qt::Key_Up:{
            baron->setPos(baron->x(),baron->y()-20);
            break;
        }
        case Qt::Key_Down:{
            baron->setPos(baron->x(),baron->y()+20);
            break;
        }
        case Qt::Key_Left:{
            baron->setPos(baron->x()-20,baron->y());
            break;
        }
        case Qt::Key_Right:{
            baron->setPos(baron->x()+20,baron->y());
            break;
        }
        }
    }
}

void graphicsView::purpleAI()
{
    int put;
    bool match = false;
    srand(time(NULL));
    while(!match){
        put = qrand()%4*2+2;
        for(int i=0;i<purpledeck->on_deck.size();i++){
            if(put==purpledeck->on_deck[i]){
                match=true;
                break;
            }
        }
    }

    int pos_rand = qrand()%2;
    QPointF pos = (pos_rand==0?QPointF(150,200):QPointF(550,200));
    switch(put){
        case 2:{
            if(purplemana->getnum()>=3){
                melee *purplemelee = new melee(0,pos.x());
                purplemelee->setPos(pos);
                scene->addItem(purplemelee);
                purplemana->setnum(3);
                purpledeck->switchcard(put);
                break;
            }
        }
        case 4:{
            if(purplemana->getnum()>=4){
                caster *purplecaster = new caster(0,pos.x());
                purplecaster->setPos(pos);
                scene->addItem(purplecaster);
                purplemana->setnum(4);
                purpledeck->switchcard(put);
                break;
            }
        }
            case 6:{
                if(purplemana->getnum()>=7){
                    siege *purplesiege = new siege(0,pos.x());
                    purplesiege->setPos(pos);
                    scene->addItem(purplesiege);
                    purplemana->setnum(7);
                    purpledeck->switchcard(put);
                }
        }
            case 8:{
                if(purplemana->getnum()>=9){
                    super *purplesuper = new super(0,pos.x());
                    purplesuper->setPos(pos);
                    scene->addItem(purplesuper);
                    purplemana->setnum(9);
                    purpledeck->switchcard(put);
                    break;
                }
        }
    }
}

void graphicsView::counting()
{
    gametime+=1;
    showtime->setPlainText(QString::number(gametime));
}

void graphicsView::showranking()
{
    ranking->clear();
    Button *Back2 = new Button("Back");
    Back2->setPos(350,700);
    ranking->addItem(Back2);
    qSort(rktime);
    if(rktime.size()>5)
        rktime.resize(5);
    qDebug()<<rktime.size();
    for(int i =0;i<rktime.size();++i){
        QGraphicsTextItem *score = new QGraphicsTextItem;
        if(rktime[i]==0) continue;
        score->setPlainText(QString::number(i+1)
                               +QString("\t\t")+QString::number(rktime[i]));
        score->setDefaultTextColor(Qt::black);
        score->setFont(QFont("time",40));
        score->setPos(300,200+i*80);
        ranking->addItem(score);
    }
}

void graphicsView::play()
{
    scene->clear();
    //Base
    Base *bluebase = new Base(1);
    Base *purplebase = new Base(0);

    bluebase->setObjectName(QString("bluebase"));
    purplebase->setObjectName(QString("purplebase"));

    bluebase->setPixmap(QPixmap(":/image/bluebase.png").scaled(100,100));
    purplebase->setPixmap(QPixmap(":/image/purplebase.png").scaled(100,100));

    bluebase->setPos(350,650);
    purplebase->setPos(350,50);

    scene->addItem(bluebase);
    scene->addItem(purplebase);

    //turrets
    Base *bluetower1 = new Base(1);
    Base *bluetower2 = new Base(1);
    Base *purpletower1 = new Base(0);
    Base *purpletower2 = new Base(0);

    bluetower1->setPixmap(QPixmap(":/image/blueturret.png").scaled(100,100));
    bluetower2->setPixmap(QPixmap(":/image/blueturret.png").scaled(100,100));
    purpletower1->setPixmap(QPixmap(":/image/purpleturret.png").scaled(100,100));
    purpletower2->setPixmap(QPixmap(":/image/purpleturret.png").scaled(100,100));

    bluetower1->setPos(150,550);
    bluetower2->setPos(550,550);
    purpletower1->setPos(150,150);
    purpletower2->setPos(550,150);

    scene->addItem(bluetower1);
    scene->addItem(bluetower2);
    scene->addItem(purpletower1);
    scene->addItem(purpletower2);

    //mana
    bluemana = new mana;
    purplemana = new mana;

    timer->start(1000);
    connect(timer,SIGNAL(timeout()),bluemana,SLOT(increase()));
    connect(timer,SIGNAL(timeout()),purplemana,SLOT(increase()));

    bluemana->setPos(0,750);
    purplemana->setPos(0,0);

    scene->addItem(bluemana);
    scene->addItem(purplemana);

    //deck
    bluedeck = new deck(1);
    bluedeck->setPos(620,700);
    scene->addItem(bluedeck);
    bluedeck->refresh();

    //AI
    purpledeck = new deck(0);
    scene->addItem(purpledeck);
    purpledeck->refresh();

    ai_timer = new QTimer();
    connect(ai_timer,SIGNAL(timeout()),this,SLOT(purpleAI()));
    ai_timer->start(5000);

    //gametime
    showtime = new QGraphicsTextItem;
    showtime->setPlainText(QString::number(gametime));
    showtime->setDefaultTextColor(Qt::black);
    showtime->setFont(QFont("time",16));
    showtime->setPos(10,400);
    scene->addItem(showtime);

    //hero
    icon = new HeroIcon;
    icon->setPos(150,700);
    scene->addItem(icon);
}

graphicsView::~graphicsView()
{

}
