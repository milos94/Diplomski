#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>

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
};

#endif // MYCLIENT_H
