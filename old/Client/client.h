#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QString>
#include "mycrypt.h"
#include "sslclient.h"
#include "chatwindow.h"
#include "myserver.h"

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(SslClient*,QString,QWidget *parent = 0);
    ~Client();

public slots:
    void ServerMessage(QByteArray);
    void socketConnected();
    void someoneConnected(QByteArray,QTcpSocket*);
    void startChat_click();


private:
    Ui::Client *ui;
    SslClient *client;
    QTcpSocket *socket;
    MyServer *server;
    qintptr port;
    QString name;
    QByteArray message;
    QStringList strList,onlineUsers;

};

#endif // CLIENT_H
