#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{
    isEncripted=false;
}

void MyClient::setSocket(qintptr Descriptor,QSslKey key,QSslCertificate cert){

    socketDescriptor=Descriptor;
    socket=new QSslSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    socket->setPrivateKey(key);
    socket->setLocalCertificate(cert);
    socket->setPeerVerifyMode(QSslSocket::VerifyNone);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(encrypted()),this,SLOT(ready()));

    socket->startServerEncryption();

}

void MyClient::connected(){

}

void MyClient::disconnected(){
    emit logMessage(QString::number(socketDescriptor)+" Disconnected");
    emit cliDisconeccted(name);
}

void MyClient::readyRead(){
    QByteArray msg=socket->readAll();
    if(isEncripted)
        msg=crypt->decrypt(msg);
    emit msgRcv(msg,this);
}



void MyClient::sendMessage(QString message){

    QByteArray data=message.toUtf8();
    if(isEncripted){
        data=crypt->encrypt(data);
    }
    socket->write(data);
    socket->flush();
}
void MyClient::sendMessage(const char* msg){
    QByteArray data=msg;
    if(isEncripted)
        data=crypt->encrypt(data);
    socket->write(msg);
}

void MyClient::sendMessage(QByteArray data){
    if(isEncripted)
        data=crypt->encrypt(data);
    socket->write(data);
}

void MyClient::ready(){
    emit logMessage(QString::number(socketDescriptor)+" Client connected...");

}

QString MyClient::getAddrAndPort(){

    QString str;
    str.append(socket->peerAddress().toString()+' '+QString::number(port));
    return str;
}

MyClient::~MyClient(){

    delete socket;
    delete crypt;
}

void MyClient::setPort(qintptr prtnumb){
    port=prtnumb;
}

QByteArray MyClient::encrypt(QByteArray data){

    return (isEncripted)?crypt->encrypt(data):data;
}


void MyClient::setCrypt(std::string key, std::string iv){
    crypt=new MyCrypt;
    crypt->setKeyIv(key,iv);
    isEncripted=true;
}
