#include "bolt.h"
#include "ui_bolt.h"

Bolt::Bolt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bolt)
{
    ui->setupUi(this);
}

Bolt::~Bolt()
{
    delete ui;
}

