#include "bolt.hpp"
#include "ui_bolt.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPalette>

Bolt::Bolt(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Bolt)
{

    ui->setupUi(this);
    setWindowTitle("BOLT");
    resize(800, 400);
    move(300, 150);

    instructions();

    // Postavljanje pozadine
    QPixmap background(":/images/Game_Background.png");
    background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paleta = palette();
    paleta.setBrush(QPalette::Background, background);
    setPalette(paleta);
    show();
}


Bolt::~Bolt()
{

}


void Bolt::instructions() {
    qDebug() <<"Pokreni animaciju dugmetom G, pauziraj dugmetom P.";
    qDebug() <<"Za kretanje tenka koristiti strelice na levo i na desno.";
    qDebug() << "Za ispaljivanje munje koristi SPACE dugme na tastaturi.";
}

void Bolt::on_pushButton_clicked()
{
    igrica1 = new Igrica1();
    hide();
    igrica1->show();
}

void Bolt::on_pushButton_2_clicked()
{
    igrica2 = new Igrica2();
    hide();
    igrica2->show();
}



void Bolt::on_pushButton_3_clicked()
{
    igrica3 = new Igrica3();
    hide();
    igrica3->show();
}
