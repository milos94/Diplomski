#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include "myclient.h"

class MyServer : public QTcpServer
{
    Q_OBJECT
public:
    MyServer();
    bool startServer(qintptr);

protected:
    void incomingConnection(qintptr);

signals:
    void someoneConnected(QByteArray,QTcpSocket*);

public slots:
    void msgRcv(QByteArray,QTcpSocket*);

private:


};

#endif // MYSERVER_H
