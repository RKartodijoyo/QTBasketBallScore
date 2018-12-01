#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLCDNumber>
#include<QVBoxLayout>
#include "secdialog.h"
#include "thrddialog.h"
#include "fourthdialog.h"
#include <QSound>
namespace Ui {

  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
  int getrizaldi(){
    int h=3;
    return h;
  }
public:
  struct Settings {
      
      int scoreHome;
      int scoreAway;
      int foulHome;
      int foulAway;
      };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Settings settings() const;
    
private slots:
//    void on_pushButton_1_Home_clicked();
    void on_pushButton_2_Home_clicked();
    void on_pushButton_3_Home_clicked();
    void on_pushButton_min1_Home_clicked();
    void on_pushButton_1_Away_clicked();
    void on_pushButton_2_Away_clicked();
    void on_pushButton_3_Away_clicked();
    void on_pushButton_min1_Away_clicked();
    void on_pushButton_resetAll_clicked();
    void UpdateTime();
    void PauseTime();
    void kirim();
    void on_pushButton_startTime_clicked();
    void on_pushButton_pauseTime_clicked();
    void on_pushButton_resetTime_clicked();
    void on_pushButton_set15min_clicked();
    void on_pushButton_set1min_clicked();
    void on_pushButton_set10min_clicked();
    void on_pushButton_set5min_clicked();
    void on_pushButton_set3min_clicked();
    void on_pushButton_tambah1menit_clicked();
    void on_pushButton_tambah1detik_clicked();
    void on_pushButton_tambahronde_clicked();
    void on_pushButton_kurangironde_clicked();
    void on_pushButton_tambahfoulhome_clicked();
    void on_pushButton_kurangifoulhome_clicked();
    void on_pushButton_tambahfoulaway_clicked();
    void on_pushButton_kurangifoulaway_clicked();
    void on_actionTime_Score_triggered();
    void on_pushButton_1_Home_clicked();
    void on_pushButton_clicked();
    //void detik24();
    void on_pushButton_tet_clicked();
    
    
private:
    Ui::MainWindow *ui;
    QTimer *timer_1s;
//    secdialog *secDialog;
//    thrddialog *thrDdialog;
    fourthdialog *fourthDialog;
     Settings currentSettings;
};

#endif // MAINWINDOW_H
