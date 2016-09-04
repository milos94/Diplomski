#ifndef MYSERVER_H
#define MYSERVER_H


#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QSsl>
#include <QSslKey>
#include <QStringList>
#include <QFile>
#include <QTextEdit>
#include <QListWidget>
#include "myclient.h"
#include "mytask.h"
#include "clientarray.h"
#include "mycrypt.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QTextEdit*,QListWidget*,QObject *parent=nullptr);
    void StartServer();
    ~MyServer();
protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    QSslKey *sslKey;
    QSslCertificate *sslCertificate;
    ClientArray *clients;
    QTextEdit *log;
    QListWidget *userList;
    QStringList onlineUsers;


public slots:
    void sendOnlineUsers(MyClient*);
    void messageReceived(QByteArray,MyClient*);
    void loggedIn(QByteArray,MyClient*,QString,QString,QByteArray,QByteArray);
    void keyGenerated(QByteArray,MyClient*,QString);
    void clientDisconected(QString);
    void logMessage(QString);

signals:
    void userAddRem(bool,QString);
    void logData(QString);
};

#endif // MYSERVER_H
