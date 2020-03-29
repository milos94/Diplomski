#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include "mycrypt.h"

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = 0);
    void setSocket(qintptr);
signals:
    void msgRcv(QByteArray,QTcpSocket*);
public slots:
    void readyRead();

private:
    QTcpSocket *socket;
    MyCrypt *crypt;
    bool isEncrypted;
};

#endif // MYCLIENT_H
