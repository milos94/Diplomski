#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QDialog>
#include <QTcpSocket>
#include "mycrypt.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChatWindow(QTcpSocket*,QString,QByteArray,QByteArray,QWidget *parent = 0);
    ~ChatWindow();

private:
    Ui::ChatWindow *ui;

private:
    QTcpSocket* socket;
    MyCrypt *crypt;
    QString name;

public slots:
    void read();
    void send();
};

#endif // CHATWINDOW_H
