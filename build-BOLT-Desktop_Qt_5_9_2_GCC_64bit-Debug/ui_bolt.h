/********************************************************************************
** Form generated from reading UI file 'bolt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOLT_H
#define UI_BOLT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bolt
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Bolt)
    {
        if (Bolt->objectName().isEmpty())
            Bolt->setObjectName(QStringLiteral("Bolt"));
        Bolt->resize(800, 600);
        centralwidget = new QWidget(Bolt);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        Bolt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Bolt);
        menubar->setObjectName(QStringLiteral("menubar"));
        Bolt->setMenuBar(menubar);
        statusbar = new QStatusBar(Bolt);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Bolt->setStatusBar(statusbar);

        retranslateUi(Bolt);

        QMetaObject::connectSlotsByName(Bolt);
    } // setupUi

    void retranslateUi(QMainWindow *Bolt)
    {
        Bolt->setWindowTitle(QApplication::translate("Bolt", "Bolt", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Bolt: public Ui_Bolt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOLT_H
