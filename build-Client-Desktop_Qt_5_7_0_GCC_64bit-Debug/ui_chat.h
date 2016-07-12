/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QWidget *dockWidgetContents;
    QLineEdit *txtMessage;
    QPushButton *btnSend;
    QPlainTextEdit *txtDisplayMessages;

    void setupUi(QDockWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QStringLiteral("Chat"));
        Chat->resize(240, 320);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        txtMessage = new QLineEdit(dockWidgetContents);
        txtMessage->setObjectName(QStringLiteral("txtMessage"));
        txtMessage->setGeometry(QRect(10, 260, 171, 22));
        btnSend = new QPushButton(dockWidgetContents);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(190, 260, 41, 22));
        txtDisplayMessages = new QPlainTextEdit(dockWidgetContents);
        txtDisplayMessages->setObjectName(QStringLiteral("txtDisplayMessages"));
        txtDisplayMessages->setGeometry(QRect(10, 0, 221, 251));
        Chat->setWidget(dockWidgetContents);

        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QDockWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "DockWidget", 0));
        btnSend->setText(QApplication::translate("Chat", "Send", 0));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
