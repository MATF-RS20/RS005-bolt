#include "igrica3.hpp"
#include "ui_igrica3.h"

Igrica3::Igrica3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Igrica3)
{
    ui->setupUi(this);
}

Igrica3::~Igrica3()
{
    delete ui;
}
