#ifndef YOUWIN_HPP
#define YOUWIN_HPP

#include <QWidget>
#include "headers/bolt.hpp"
#include "headers/igrica1.hpp"

namespace Ui {
class YouWin;
}

class YouWin : public QWidget
{
    Q_OBJECT

public:
    explicit YouWin(QWidget *parent = nullptr);
    ~YouWin();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

private:
    Ui::YouWin *ui;
    Bolt *_main_ui;
    Igrica1 *_igrica1;

    int _windowWidth;
    int _windowHeight;
};

#endif // YOUWIN_HPP
