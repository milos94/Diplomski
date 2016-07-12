/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QPushButton *btnSend;
    QLineEdit *txtMessage;
    QPlainTextEdit *txtDisplayMessages;

    void setupUi(QDialog *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QStringLiteral("ChatWindow"));
        ChatWindow->resize(240, 320);
        btnSend = new QPushButton(ChatWindow);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(170, 290, 61, 22));
        txtMessage = new QLineEdit(ChatWindow);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        txtMessage->setGeometry(QRect(10, 290, 151, 22));
        txtDisplayMessages = new QPlainTextEdit(ChatWindow);
        txtDisplayMessages->setObjectName(QStringLiteral("txtDisplayMessages"));
        txtDisplayMessages->setGeometry(QRect(10, 10, 221, 271));

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "Dialog", 0));
        btnSend->setText(QApplication::translate("ChatWindow", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
