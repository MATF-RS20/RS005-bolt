#ifndef IGRICA3_HPP
#define IGRICA3_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
namespace Ui {
class Igrica3;
}

class Igrica3 : public QWidget
{
    Q_OBJECT

public:
    explicit Igrica3(QWidget *parent = nullptr,int _invaderNumber = 5);
    ~Igrica3();

private:
    Ui::Igrica3 *ui;
    QGraphicsScene *scene;
    int _windowWidth;
    int _windowHeight;
    int _invaderSpeed;
    int _invaderNumber;
    int _bingo;
     QTimer *timer ;
     QMediaPlayer * music = new QMediaPlayer();
     bool over=false;
    void pokreniIgricu();
    void gameOver();
public slots:
    void checkState();

signals:
    void valueChanged();


};

#endif // IGRICA3_HPP
