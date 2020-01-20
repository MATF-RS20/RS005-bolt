#include "headers/gameoverinvader.h"
#include "ui_form.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPalette>
#include "headers/bolt.hpp"

GameOverInvader::GameOverInvader(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Form)
{

    ui->setupUi(this);
    setFixedSize(800, 500);
    move(300, 150);

    QPixmap background(":/images/go.jpg");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paleta = palette();
    paleta.setBrush(QPalette::Background, background);
    setPalette(paleta);
    show();
}

void GameOverInvader::on_pushButton_clicked(){
    _main_ui = new Bolt();
    hide();
    _main_ui->show();
}
GameOverInvader::~GameOverInvader()
{

}



