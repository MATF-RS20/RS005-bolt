#ifndef IGRICA1_HPP
#define IGRICA1_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>

namespace Ui {
class Igrica1;
}

class Igrica1 : public QWidget
{
    Q_OBJECT

public:
    explicit Igrica1(QWidget *parent = nullptr);
    ~Igrica1();

private:
    Ui::Igrica1 *ui;
//    QGraphicsScene *scene;
};

#endif // IGRICA1_HPP
