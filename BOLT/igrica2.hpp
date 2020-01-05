#ifndef IGRICA2_HPP
#define IGRICA2_HPP

#include <QWidget>

namespace Ui {
class Igrica2;
}

class Igrica2 : public QWidget
{
    Q_OBJECT

public:
    explicit Igrica2(QWidget *parent = nullptr);
    ~Igrica2();

private:
    Ui::Igrica2 *ui;
};

#endif // IGRICA2_HPP
