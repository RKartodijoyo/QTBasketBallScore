#ifndef FOURTHDIALOG_H
#define FOURTHDIALOG_H
#include <QDialog>
#include "AutoResize.h"
//#include "mainwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui {
  class fourthdialog;
}
QT_END_NAMESPACE
class MainWindow;
class fourthdialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit fourthdialog(QWidget *parent = 0);
  ~fourthdialog();
  //Settings settings() const;
  
private slots:
  void on_pushButton_clicked();
  void UpdateTime();
private:
  Ui::fourthdialog *ui;
      QTimer *timer_1s;
  AutoResize *m_autoResizeHandler;
  void resizeEvent(QResizeEvent * event);
//     Settings currentSettings;
};
// Derived class

#endif // FOURTHDIALOG_H
