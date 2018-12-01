#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QTimer>
#include <QTime>
#include "score.h"
int pointHome,pointAway;
int a=0,ronde=1,foulaway,foulhome,section,puluhmenit,menit,puluhdetik,detik,waktu,b24,detikku24,puluhdetikku24,suarasekali;

float b,c;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
ui->lcdNumber_Ronde->display(ronde);
kirim();
timer_1s = new QTimer(this);
     timer_1s->start(10);
   }
MainWindow::~MainWindow()
{

    delete ui;
}
MainWindow::Settings MainWindow::settings() const
{
    return currentSettings;
}
void MainWindow::on_pushButton_1_Home_clicked()
{
pointHome+=1;
ui->lcdNumber_Home->display(pointHome);
currentSettings.scoreHome = pointHome;
kirim();
}
void MainWindow::on_pushButton_2_Home_clicked()
{
pointHome+=2;
ui->lcdNumber_Home->display(pointHome);
currentSettings.scoreHome = pointHome;
kirim();
}
void MainWindow::on_pushButton_3_Home_clicked()
{
pointHome+=3;
ui->lcdNumber_Home->display(pointHome);
currentSettings.scoreHome = pointHome;
kirim();
}
void MainWindow::on_pushButton_min1_Home_clicked()
{
if(pointHome<=0){
ui->lcdNumber_Home->display(pointHome);
  }else{
    pointHome-=1;
    ui->lcdNumber_Home->display(pointHome);
  }
currentSettings.scoreHome = pointHome;
kirim();  
}
void MainWindow::on_pushButton_1_Away_clicked()
{
pointAway+=1;
ui->lcdNumber_Away->display(pointAway);
currentSettings.scoreAway = pointAway;
kirim();
}
void MainWindow::on_pushButton_2_Away_clicked()
{
pointAway+=2;
ui->lcdNumber_Away->display(pointAway);
currentSettings.scoreAway = pointAway;
kirim();
}
void MainWindow::on_pushButton_3_Away_clicked()
{
pointAway+=3;
ui->lcdNumber_Away->display(pointAway);
currentSettings.scoreAway = pointAway;
kirim();
}
void MainWindow::on_pushButton_min1_Away_clicked()
{
if(pointAway<=0){
ui->lcdNumber_Away->display(pointAway);
  }else{
    pointAway-=1;
    ui->lcdNumber_Away->display(pointAway);
  kirim();}
currentSettings.scoreAway = pointAway;
}
void MainWindow::on_pushButton_resetAll_clicked()
{
  pointHome=0;
  pointAway=0;
  ui->lcdNumber_Home->display(pointHome);
  
  ui->lcdNumber_Away->display(pointAway);
kirim();}
void MainWindow::on_pushButton_startTime_clicked(){
  b24=2401;
  if(a>0){
 if(section==0){
 timer_1s = new QTimer(this);
QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
   timer_1s->start(10);
   
   }
  section=1;
}
kirim();}
void MainWindow::on_pushButton_pauseTime_clicked(){
  if(a>0){
  
  section=0;
 QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(PauseTime()));
}
kirim();}
void MainWindow::on_pushButton_resetTime_clicked(){
  

  a=0;
    detik=a/100;
    detik=detik%10;
    puluhdetik=a/1000;
    puluhdetik=puluhdetik%6;
    menit=a/6000;
    menit=menit%10;
    puluhmenit=a/60000;
    puluhmenit=puluhmenit%6;
    
    ui->label_puluhmenit->setText(QString::number(puluhmenit));
    
    ui->label_menit->setText(QString::number(menit));
    ui->label_puluhdetik->setText(QString::number(puluhdetik));
    
    ui->label_detik->setText(QString::number(detik));
    b24=2401;
    detikku24=b24/100;
    detikku24=detikku24%10;
    puluhdetikku24=b24/1000;
    
    ui->label_puluhdetik_24->setText(QString::number(puluhdetikku24));
    
    ui->label_detik_24->setText(QString::number(detikku24));
//    qDebug()<<puluhdetikku24;
    kirim();
}
void MainWindow::UpdateTime()
{   if(a>=0){
  a--;
     detik=a/100;
     detik=detik%10;
     puluhdetik=a/1000;
     puluhdetik=puluhdetik%6;
     menit=a/6000;
     menit=menit%10;
     puluhmenit=a/60000;
     puluhmenit=puluhmenit%6;
    ui->label_puluhmenit->setText(QString::number(puluhmenit));
    
    ui->label_menit->setText(QString::number(menit));
    ui->label_puluhdetik->setText(QString::number(puluhdetik));
    
    ui->label_detik->setText(QString::number(detik));
    if(b24>=0){
    b24--;
    detikku24=b24/100;
    detikku24=detikku24%10;
    puluhdetikku24=b24/1000;
    
    ui->label_puluhdetik_24->setText(QString::number(puluhdetikku24));
    
    ui->label_detik_24->setText(QString::number(detikku24));
      }else{if(suarasekali==0){QSound::play(":/tet.wav");
          suarasekali=1;}}
}else{timer_1s->stop();section=0;}
   kirim(); 
    }
void MainWindow::PauseTime(){
  
     timer_1s->stop();
     detik=a/100;
     detik=detik%10;
     puluhdetik=a/1000;
     puluhdetik=puluhdetik%6;
     menit=a/6000;
     menit=menit%10;
     puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
     
     ui->label_puluhmenit->setText(QString::number(puluhmenit));
     
     ui->label_menit->setText(QString::number(menit));
     ui->label_puluhdetik->setText(QString::number(puluhdetik));
     
     ui->label_detik->setText(QString::number(detik));
     b24=2401;
     detikku24=b24/100;
     detikku24=detikku24%10;
     puluhdetikku24=b24/1000;
     
     ui->label_puluhdetik_24->setText(QString::number(puluhdetikku24));
     
     ui->label_detik_24->setText(QString::number(detikku24));
     suarasekali=0;
     kirim();
}
void MainWindow::on_pushButton_set15min_clicked(){
  a=90000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
  kirim();
}
void MainWindow::on_pushButton_set1min_clicked(){
  a=6000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
  kirim();
}
void MainWindow::on_pushButton_set5min_clicked(){
  a=30000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
  kirim();
}
void MainWindow::on_pushButton_set10min_clicked(){
  a=60000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
 kirim();
}
void MainWindow::on_pushButton_set3min_clicked(){
  a=18000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
kirim();
}
void MainWindow::on_pushButton_tambah1menit_clicked(){
  a+=6000;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
 kirim();
}
void MainWindow::on_pushButton_tambah1detik_clicked(){
  a+=100;
  detik=a/100;
  detik=detik%10;
  puluhdetik=a/1000;
  puluhdetik=puluhdetik%6;
  menit=a/6000;
  menit=menit%10;
  puluhmenit=a/60000;      puluhmenit=puluhmenit%6;
  
  ui->label_puluhmenit->setText(QString::number(puluhmenit));
  
  ui->label_menit->setText(QString::number(menit));
  ui->label_puluhdetik->setText(QString::number(puluhdetik));
  
  ui->label_detik->setText(QString::number(detik));
kirim();
}
void MainWindow::on_pushButton_tambahronde_clicked(){
  if(ronde<5){
  ronde+=1;
  ui->lcdNumber_Ronde->display(ronde);

    }
kirim();}
void MainWindow::on_pushButton_kurangironde_clicked(){
  if(ronde>1){
  ronde-=1;
  ui->lcdNumber_Ronde->display(ronde);
}kirim();}
void MainWindow::on_pushButton_tambahfoulhome_clicked(){
  if(foulhome<5){
  foulhome+=1;
  ui->lcdNumber_foulHome->display(foulhome);
}kirim();}
void MainWindow::on_pushButton_kurangifoulhome_clicked(){
  if(foulhome>0){
  foulhome-=1;
  ui->lcdNumber_foulHome->display(foulhome);
}kirim();}
void MainWindow::on_pushButton_tambahfoulaway_clicked(){
  if(foulaway<5){
  foulaway+=1;
  ui->lcdNumber_foulAway->display(foulaway);
}kirim();}
void MainWindow::on_pushButton_kurangifoulaway_clicked(){
  if(foulaway>0){
  foulaway-=1;
  ui->lcdNumber_foulAway->display(foulaway);
}kirim();}
 void MainWindow::on_actionTime_Score_triggered(){
   
  fourthDialog = new fourthdialog(this);

   fourthDialog->show();
}
int getA(){
  return a;
}
void MainWindow::kirim(){
  QString timhome = ui->lineEdit_Home->text();
  QString timeaway = ui->lineEdit_Away->text();
  
  QFile file("out.txt");
      if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
          return;
      QTextStream out(&file);
      out << puluhmenit<<"\n"<<menit<<"\n"<<puluhdetik<<"\n"<<detik<<"\n"<<foulaway<<"\n"<<foulhome<<"\n"<<pointAway<<"\n"<<pointHome<<"\n"<<ronde<<"\n"<<detikku24<<"\n"<<puluhdetikku24<<"\n"<<timhome<<"\n"<<timeaway;
  
}

void MainWindow::on_pushButton_clicked()
{
    
  b24=2401;
  suarasekali=0;
}

void MainWindow::on_pushButton_tet_clicked()
{
    QSound::play(":/tet.wav");
}

