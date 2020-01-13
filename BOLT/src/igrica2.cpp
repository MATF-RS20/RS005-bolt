#include "headers/igrica2.hpp"
#include "ui_igrica2.h"

Igrica2::Igrica2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Igrica2)
{
    ui->setupUi(this);
}

Igrica2::~Igrica2()
{
    delete ui;
}
