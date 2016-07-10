#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{

}

void MyClient::setSocket(qintptr Descriptor){

    socketDescriptor=Descriptor;
    socket=new QTcpSocket(this);
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));

    qDebug()<< socketDescriptor <<"Client connected...";
}

void MyClient::connected(){

}

void MyClient::disconnected(){
    qDebug()<< socketDescriptor<<" Disconnected";
    emit cliDisconeccted(name);
}

void MyClient::readyRead(){
    QByteArray msg=socket->readAll();
    qDebug()<<socketDescriptor<<" sent:"<< msg;
    emit msgRcv(msg,this);
}



void MyClient::sendMessage(QString message){

    socket->write(message.toUtf8());
}
