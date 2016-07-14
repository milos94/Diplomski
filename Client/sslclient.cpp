#include "sslclient.h"

SslClient::SslClient(QObject *parent) : QObject(parent)
{
    client=new QSslSocket;
    connect(client,SIGNAL(encrypted()),this,SLOT(connectionEstablished()));
    connect(client,SIGNAL(sslErrors(QList<QSslError>)),this,SLOT(errOccured(QList<QSslError>)));
    connect(client,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void SslClient::errOccured(const QList<QSslError> &error){
    client->ignoreSslErrors();
}

void SslClient::connectionEstablished(){
    QSslCertificate cert=client->peerCertificate();
    emit connectedToServer(true);
}

void SslClient::start(){

    client->connectToHostEncrypted("192.168.1.249",1234);
}

void SslClient::sendMessage(QByteArray msg){
    client->write(msg);
    client->flush();
}

void SslClient::readyRead(){
    QByteArray msg=client->readAll();
    emit ServerMessage(msg);
}
