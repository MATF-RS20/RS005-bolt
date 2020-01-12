#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "tank.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    scene.setSceneRect(-300,-300,600,600);
    scene.setItemIndexMethod(QGraphicsScene::NoIndex);
    Tank* t=new Tank();
    t->setPos(0,250); // inicijalna pozicija
    t->setFlag(QGraphicsItem::ItemIsFocusable);

    scene.addItem(t);
    t->setFocus();
    QGraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);


    view.setWindowTitle("Spark :) ");
    view.resize(600, 600);
    view.show();

    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));

    timer.start(1000 / 33);
    return app.exec();
}
