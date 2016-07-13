#include "myclient.h"

MyClient::MyClient(QObject *parent) : QObject(parent)
{

}

void MyClient::setSocket(qintptr descriptor){
    socket=new QTcpSocket;
    socket->setSocketDescriptor(descriptor);
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
}

void MyClient::readyRead(){
    QByteArray data=socket->readAll();
    qDebug()<<data.data();
    emit msgRcv(data,socket);
    disconnect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    socket=nullptr;
}
