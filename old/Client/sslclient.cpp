#include "sslclient.h"

SslClient::SslClient(QObject *parent) : QObject(parent)
{
    client=new QSslSocket;
    connect(client,SIGNAL(encrypted()),this,SLOT(connectionEstablished()));
    connect(client,SIGNAL(sslErrors(QList<QSslError>)),this,SLOT(errOccured(QList<QSslError>)));
    connect(client,SIGNAL(readyRead()),this,SLOT(readyRead()));
    isEnc=false;
}

void SslClient::errOccured(const QList<QSslError> &error){
    client->ignoreSslErrors();
}

void SslClient::connectionEstablished(){
    QSslCertificate cert=client->peerCertificate();
    emit connectedToServer(true);
}

void SslClient::start(){

    client->connectToHostEncrypted("localhost",1234);
}

void SslClient::sendMessage(QByteArray msg){
    if(isEnc)
        msg=crypt->encrypt(msg);
    client->write(msg);
    client->flush();
}

void SslClient::readyRead(){
    QByteArray msg=client->readAll();
    if(isEnc)
        msg=crypt->decrypt(msg);
    emit ServerMessage(msg);
}

void SslClient::setCrypt(QByteArray strKey, QByteArray strIv){
    crypt=new MyCrypt(strKey.data(),strIv.data());
    isEnc=true;
}

QByteArray SslClient::decrypt(QByteArray data){
    return (isEnc)?crypt->decrypt(data):data;
}
