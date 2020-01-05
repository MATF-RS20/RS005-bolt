#include "igrica1.hpp"
#include "ui_igrica1.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

Igrica1::Igrica1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Igrica1)
{
    ui->setupUi(this);

    setWindowTitle("Igrica 1");
    resize(800, 600);
    move(300, 150);

    qDebug("AAA");
    QGraphicsScene scene;
    //    // Inicijalizujemo scenu
    scene.setSceneRect(0, 0, 800, 400);
    qDebug("AAA");
    // Iskljucujemo indeksiranje pozicija elemenata scene
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);

    // Kreiramo pogled za scenu
    QGraphicsView view(&scene);
    qDebug("AAA");
    // Ukljucujemo anti-aliasing
    view.setRenderHint(QPainter::Antialiasing);

    // Postavljamo sliku za pozadinu
    view.setStyleSheet("background-image: url(:/images/g1.jpg);");

    view.show();
}

Igrica1::~Igrica1()
{
    delete ui;
}
