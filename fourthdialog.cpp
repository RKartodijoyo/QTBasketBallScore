#include "fourthdialog.h"
#include "ui_fourthdialog.h"
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include "mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QString>
#include <QTimer>
#include <QTextStream>

using namespace std;

QTextStream cout(stdout);
QTextStream cin(stdin);
int f;
int pp;
int h[20];
fourthdialog::fourthdialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::fourthdialog)
{
  ui->setupUi(this);
  timer_1s = new QTimer(this);
   timer_1s->start(1000);
  //settings = new MainWindow;
  m_autoResizeHandler=new AutoResize(this,this->rect().width(),this->rect().height());
  m_autoResizeHandler->setAutoResizeFlag(
          AutoResize::INCLUDE_BUTTON|AutoResize::INCLUDE_COMBOBOX|
          AutoResize::INCLUDE_EDITOR|AutoResize::INCLUDE_LABEL
        //AutoResize::INCLUDE_LCD
          );
  QFontDatabase::addApplicationFont(":/fonts/scoreboard.ttf");
    QFontDatabase::addApplicationFont(":/fonts/crashedscoreboard.ttf");
  //ui->label_2->setFont(QFontDatabase::addApplicationFont(“:/fonts/scoreboard.ttf”));
  //font()
  
  //add widget* manualy
  //m_autoResizeHandler->addOtherItem(ui->frame);
  m_autoResizeHandler->pushAllResizeItem();
}

fourthdialog::~fourthdialog()
{
  delete ui;
//delete settings;
}

void fourthdialog::resizeEvent(QResizeEvent *event)
{
    m_autoResizeHandler->doAutoResize();
}

void fourthdialog::on_pushButton_clicked()
{
  
  timer_1s = new QTimer(this);
 QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(10);
}

void fourthdialog::UpdateTime()
{ pp=0;
  std::string kowe;
QString timhome, timaway;
  QFile file("out.txt");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
      return;

  QTextStream in(&file);
  
  while (!in.atEnd()) {
      QString line = in.readLine();
//        qDebug()<<line;
      if(pp==11){
        timhome=line;
        pp++;
        }else if(pp==12){
         
            timaway=line;
            pp++;
        }else{
        kowe =line.toStdString();
        kowe.erase(remove( kowe.begin(), kowe.end(), '\"' ),kowe.end());
            
              h[pp++]=stoi(kowe);
             }
    }


ui->label_9->setText(QString::number(h[0]));
ui->label_10->setText(QString::number(h[1]));
ui->label_11->setText(QString::number(h[2]));
ui->label_12->setText(QString::number(h[3]));
ui->label_8->setText(QString::number(h[8]));
ui->label_16->setText(QString::number(h[5]));
ui->label_17->setText(QString::number(h[4]));
ui->label_4->setText(QString::number(h[7]));
ui->label_7->setText(QString::number(h[6]));
ui->label_18->setText(QString::number(h[10]));
ui->label_19->setText(QString::number(h[9]));
    ui->label_14->setText(timhome);
    ui->label_15->setText(timaway);

             
    }

