#ifndef BOLT_H
#define BOLT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Bolt; }
QT_END_NAMESPACE

class Bolt : public QMainWindow
{
    Q_OBJECT

public:
    Bolt(QWidget *parent = nullptr);
    ~Bolt();

private:
    Ui::Bolt *ui;
};
#endif // BOLT_H
