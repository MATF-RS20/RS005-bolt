#ifndef IGRICA3_HPP
#define IGRICA3_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
namespace Ui {
class Igrica1;
}

class Igrica3 : public QWidget
{
    Q_OBJECT

public:
    explicit Igrica3(QWidget *parent = nullptr);
    ~Igrica3();

private:
    Ui::Igrica1 *ui;
    QGraphicsScene *scene;

    int _windowWidth;
    int _windowHeight;

    void pokreniIgricu();
};

#endif // IGRICA3_HPP
