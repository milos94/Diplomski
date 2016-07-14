#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QTcpSocket>
#include <QThreadPool>
#include <QDebug>
#include <QSslKey>
#include <QHostAddress>
#include <QSslConfiguration>
#include <QtCrypto/QtCrypto>
#include <string>

using namespace std;

class MyClient : public QObject
{
    Q_OBJECT

public:
    explicit MyClient(QObject *parent = 0);
    void setSocket(qintptr Descriptor,QSslKey,QSslCertificate);
    void sendMessage(QString message);
    void sendMessage(const char* msg){ socket->write(msg);  socket->flush();}
    void sendMessage(QByteArray data){ socket->write(data); socket->flush();}
    QString getName(){ return name;}
    void setName(QString name){ this->name=name;}
    QString getAddrAndPort();
    void setPort(qintptr);
    ~MyClient();

signals:
    void msgRcv(QByteArray,MyClient*);
    void cliDisconeccted(QString);
    void logMessage(QString);

public slots:
    void connected();
    void disconnected();
    void readyRead();
    void ready();

private:
    QString name;
    qintptr socketDescriptor;
    QSslSocket *socket;
    qintptr port;
};

#endif // MYCLIENT_H
