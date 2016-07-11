/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogInDialog
{
public:
    QLineEdit *txtUserName;
    QLineEdit *txtPass;
    QPushButton *btnLogIn;
    QPushButton *btnCancle;
    QLabel *label;
    QLabel *lblStatus;

    void setupUi(QDialog *LogInDialog)
    {
        if (LogInDialog->objectName().isEmpty())
            LogInDialog->setObjectName(QStringLiteral("LogInDialog"));
        LogInDialog->resize(364, 154);
        txtUserName = new QLineEdit(LogInDialog);
        txtUserName->setObjectName(QStringLiteral("txtUserName"));
        txtUserName->setGeometry(QRect(20, 50, 201, 22));
        txtPass = new QLineEdit(LogInDialog);
        txtPass->setObjectName(QStringLiteral("txtPass"));
        txtPass->setGeometry(QRect(20, 90, 201, 22));
        txtPass->setEchoMode(QLineEdit::Password);
        btnLogIn = new QPushButton(LogInDialog);
        btnLogIn->setObjectName(QStringLiteral("btnLogIn"));
        btnLogIn->setGeometry(QRect(250, 50, 80, 22));
        btnCancle = new QPushButton(LogInDialog);
        btnCancle->setObjectName(QStringLiteral("btnCancle"));
        btnCancle->setGeometry(QRect(250, 90, 80, 22));
        label = new QLabel(LogInDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 130, 141, 16));
        lblStatus = new QLabel(LogInDialog);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));
        lblStatus->setGeometry(QRect(20, 20, 201, 16));

        retranslateUi(LogInDialog);

        QMetaObject::connectSlotsByName(LogInDialog);
    } // setupUi

    void retranslateUi(QDialog *LogInDialog)
    {
        LogInDialog->setWindowTitle(QApplication::translate("LogInDialog", "Dialog", 0));
        btnLogIn->setText(QApplication::translate("LogInDialog", "Log In", 0));
        btnCancle->setText(QApplication::translate("LogInDialog", "Cancle", 0));
        label->setText(QApplication::translate("LogInDialog", "Connecting to server...", 0));
        lblStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LogInDialog: public Ui_LogInDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
