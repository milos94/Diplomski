#ifndef SSLCLIENT_H
#define SSLCLIENT_H

#include <QObject>
#include <QSslSocket>
#include <QString>
#include <QByteArray>
#include <QList>
#include <QSslCertificate>
#include <QString>
class SslClient : public QObject
{
    Q_OBJECT
public:
    explicit SslClient(QObject *parent = 0);
    void start();
    void sendMessage(QByteArray);
signals:
    void connectedToServer(bool);
    void ServerMessage(QByteArray);

public slots:
    void connectionEstablished();
    void errOccured(const QList<QSslError> &error);
    void readyRead();
private:
    QSslSocket *client;
};
#endif // SSLCLIENT_H
