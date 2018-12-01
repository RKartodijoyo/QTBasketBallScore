#ifndef SCORE_H
#define SCORE_H

#include <QWidget>

namespace Ui {
  class ScoRe;
}

class ScoRe : public QWidget
{
  Q_OBJECT
  
public:
  explicit ScoRe(QWidget *parent = 0);
  ~ScoRe();
  
private:
  Ui::ScoRe *ui;
};

#endif // SCORE_H
