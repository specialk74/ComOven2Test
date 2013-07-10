/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 20 15:53:01 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *addressServer;
    QLineEdit *portServer;
    QPushButton *connectButton;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cmd1Button;
    QPushButton *cmd2Button;
    QPushButton *cmd3Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(457, 384);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addressServer = new QLineEdit(centralWidget);
        addressServer->setObjectName(QString::fromUtf8("addressServer"));

        horizontalLayout->addWidget(addressServer);

        portServer = new QLineEdit(centralWidget);
        portServer->setObjectName(QString::fromUtf8("portServer"));
        portServer->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(portServer);

        connectButton = new QPushButton(centralWidget);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));

        horizontalLayout->addWidget(connectButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cmd1Button = new QPushButton(centralWidget);
        cmd1Button->setObjectName(QString::fromUtf8("cmd1Button"));

        horizontalLayout_2->addWidget(cmd1Button);

        cmd2Button = new QPushButton(centralWidget);
        cmd2Button->setObjectName(QString::fromUtf8("cmd2Button"));

        horizontalLayout_2->addWidget(cmd2Button);

        cmd3Button = new QPushButton(centralWidget);
        cmd3Button->setObjectName(QString::fromUtf8("cmd3Button"));

        horizontalLayout_2->addWidget(cmd3Button);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 457, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        addressServer->setText(QApplication::translate("MainWindow", "127.0.0.1", 0, QApplication::UnicodeUTF8));
        portServer->setText(QApplication::translate("MainWindow", "6800", 0, QApplication::UnicodeUTF8));
        connectButton->setText(QApplication::translate("MainWindow", "&Connect", 0, QApplication::UnicodeUTF8));
        cmd1Button->setText(QApplication::translate("MainWindow", "CMD1", 0, QApplication::UnicodeUTF8));
        cmd2Button->setText(QApplication::translate("MainWindow", "CMD2", 0, QApplication::UnicodeUTF8));
        cmd3Button->setText(QApplication::translate("MainWindow", "CMD3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
