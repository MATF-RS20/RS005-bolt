#ifndef BOLT_H
#define BOLT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "igrica1.hpp"
#include "igrica2.hpp"
#include "igrica3.hpp"

namespace Ui { class Bolt;}


class Bolt : public QMainWindow
{
    Q_OBJECT

public:
    explicit Bolt(QWidget *parent = nullptr);
    ~Bolt();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Bolt *ui;
    Igrica1 *igrica1;
    Igrica2 *igrica2;
    Igrica3 *igrica3;
    void instructions();
};
#endif // BOLT_H
