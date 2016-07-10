#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>
#include <QtCrypto/QtCrypto>
#include <string>

using namespace std;

class MyClient : public QObject
{
    Q_OBJECT

public:
    explicit MyClient(QObject *parent = 0);
    void setSocket(qintptr Descriptor);
    void sendMessage(QString message);
    void sendMessage(const char* msg){ socket->write(msg);}
    void sendMessage(QByteArray data){ socket->write(data);}
    QString getName(){ return name;}
    void setName(QString name){ this->name=name;}

signals:
    void msgRcv(QByteArray,MyClient*);

public slots:
    void connected();
    void disconnected();
    void readyRead();

private:
    QString name;
    qintptr socketDescriptor;
    QTcpSocket *socket;
};

#endif // MYCLIENT_H
