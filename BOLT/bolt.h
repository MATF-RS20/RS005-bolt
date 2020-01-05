#ifndef BOLT_H
#define BOLT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsScene>

namespace Ui { class Bolt;}


class Bolt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bolt(QWidget *parent = nullptr);
    ~Bolt();


private:
    Ui::Bolt *ui;
    void instructions();
};
#endif // BOLT_H
