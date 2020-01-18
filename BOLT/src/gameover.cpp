#include "headers/gameover.hpp"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),ui(new Ui::GameOver),
    _windowWidth(600), _windowHeight(480)
{
    ui->setupUi(this);
    setWindowTitle("BOLT");
    setFixedSize(_windowWidth, _windowHeight);
    move(300, 150);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton1_clicked()
{
    //ili da posaljem signal u Bolt i tamo samo prikazem sa show() jer je taj prozor jos ziv
    _main_ui = new Bolt();
    hide();
    _main_ui->show();
}

void GameOver::on_pushButton2_clicked()
{
    _igrica1 = new Igrica1();
    close();
    _igrica1->show();
}
