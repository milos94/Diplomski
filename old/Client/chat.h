#ifndef CHAT_H
#define CHAT_H

#include <QDockWidget>
#include <QTcpSocket>
#include <QWindow>
#include "mycrypt.h"
namespace Ui {
class Chat;
}

class Chat : public QDockWidget
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket*,QString,QByteArray,QByteArray,QWidget *parent = 0);
    ~Chat();

private:
    QTcpSocket* socket;
    MyCrypt *crypt;
    Ui::Chat *ui;
public slots:
    void read();
    void send();
};

#endif // CHAT_H
