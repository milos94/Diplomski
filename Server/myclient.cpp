#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{

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
    emit msgRcv(msg,this);
}



void MyClient::sendMessage(QString message){

    socket->write(message.toUtf8());
    socket->flush();
}

void MyClient::ready(){
    emit logMessage(QString::number(socketDescriptor)+" Client connected...");

}

QString MyClient::getAddrAndPort(){

    QString str;
    str.append(socket->peerAddress().toString()+' ');
    return str;
}

MyClient::~MyClient(){

    delete socket;
}
