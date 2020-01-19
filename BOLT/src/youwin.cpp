#include "headers/youwin.hpp"
#include "ui_youwin.h"

YouWin::YouWin(QWidget *parent) :
    QWidget(parent), ui(new Ui::YouWin),
    _windowWidth(600), _windowHeight(480)
{
    ui->setupUi(this);
    setWindowTitle("BOLT");
    setFixedSize(_windowWidth, _windowHeight);
    move(300, 150);
}

YouWin::~YouWin()
{
    delete ui;
}

void YouWin::on_pushButton1_clicked()
{
    _main_ui = new Bolt();
    hide();
    _main_ui->show();
}

void YouWin::on_pushButton2_clicked()
{
    _igrica1 = new Igrica1();
    close();
    _igrica1->show();
}
