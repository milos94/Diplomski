/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Server
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTextEdit *txtLog;
    QLabel *label_2;
    QListWidget *listUsers;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Server)
    {
        if (Server->objectName().isEmpty())
            Server->setObjectName(QStringLiteral("Server"));
        Server->resize(546, 388);
        centralWidget = new QWidget(Server);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 59, 14));
        txtLog = new QTextEdit(centralWidget);
        txtLog->setObjectName(QStringLiteral("txtLog"));
        txtLog->setGeometry(QRect(20, 30, 341, 291));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(390, 10, 59, 14));
        listUsers = new QListWidget(centralWidget);
        listUsers->setObjectName(QStringLiteral("listUsers"));
        listUsers->setGeometry(QRect(390, 30, 121, 291));
        Server->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Server);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 19));
        Server->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Server);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Server->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Server);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Server->setStatusBar(statusBar);

        retranslateUi(Server);

        QMetaObject::connectSlotsByName(Server);
    } // setupUi

    void retranslateUi(QMainWindow *Server)
    {
        Server->setWindowTitle(QApplication::translate("Server", "Server", 0));
        label->setText(QApplication::translate("Server", "LOG:", 0));
        label_2->setText(QApplication::translate("Server", "USERS:", 0));
    } // retranslateUi

};

namespace Ui {
    class Server: public Ui_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
