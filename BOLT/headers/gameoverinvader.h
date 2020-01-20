#ifndef GAMEOVERINVADER_H
#define GAMEOVERINVADER_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "headers/bolt.hpp"

namespace Ui { class Form;}
class GameOverInvader : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameOverInvader(QWidget *parent = nullptr);
    ~GameOverInvader();


private slots:
    void on_pushButton_clicked();


private:
    Ui::Form *ui;
    Bolt *_main_ui;
};

#endif // GAMEOVERINVADER_H
