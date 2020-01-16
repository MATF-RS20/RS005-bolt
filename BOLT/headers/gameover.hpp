#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#include <QWidget>
#include "headers/bolt.hpp"
#include "headers/igrica1.hpp"

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();


private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::GameOver *ui;
    Bolt *_main_ui;
//    Igrica1 *_igrica1;

    int _windowWidth;
    int _windowHeight;
};

#endif // GAMEOVER_HPP
