#include "score.h"
#include "ui_score.h"

ScoRe::ScoRe(QWidget *parent) :
  QWidget(parent),
  ui(new Ui:ScoRe)
{
  ui->setupUi(this);
}

ScoRe::~ScoRe()
{
  delete ui;
}
