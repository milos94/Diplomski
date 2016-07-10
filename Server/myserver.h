#ifndef MYSERVER_H
#define MYSERVER_H


#include <QObject>
#include <QTcpServer>
#include <QDebug>
#include <QSsl>
#include <QSslKey>
#include <QStringList>
#include <QFile>
#include "myclient.h"
#include "mytask.h"
#include "clientarray.h"
#include "mycrypt.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer(QObject *parent=nullptr);
    void StartServer();
    ~MyServer();
protected:
    void incomingConnection(qintptr socketDescriptor);

private:
    QSslKey *sslKey;
    QSslCertificate *sslCertificate;
    ClientArray *clients;
    MyCrypt *crypt;

public slots:
    void messageReceived(QByteArray,MyClient*);
    void loggedIn(QByteArray,MyClient*);
    void keyGenerated(QByteArray,MyClient*,MyClient*);
    void clientDisconected(QString);
};

#endif // MYSERVER_H