#ifndef SSLCLIENT_H
#define SSLCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QString>
#include <QByteArray>
#include <QList>
#include <QSslCertificate>
#include <QString>
#include "mycrypt.h"


class SslClient : public QObject
{
    Q_OBJECT
public:
    explicit SslClient(QObject *parent = 0);
    void start();
    void sendMessage(QByteArray);
    void setCrypt(QByteArray strKey,QByteArray strIv);
    QByteArray decrypt(QByteArray);
signals:
    void connectedToServer(bool);
    void ServerMessage(QByteArray);

public slots:
    void connectionEstablished();
    void errOccured(const QList<QSslError> &error);
    void readyRead();
private:
    QSslSocket *client;
    MyCrypt *crypt;
    bool isEnc;
};
#endif // SSLCLIENT_H
