#ifndef IGRICA3_HPP
#define IGRICA3_HPP

#include <QWidget>

namespace Ui {
class Igrica3;
}

class Igrica3 : public QWidget
{
    Q_OBJECT

public:
    explicit Igrica3(QWidget *parent = nullptr);
    ~Igrica3();

private:
    Ui::Igrica3 *ui;
};

#endif // IGRICA3_HPP
