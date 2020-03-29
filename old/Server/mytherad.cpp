#include "mytherad.h"

MyThread::MyThread(int ID,QObject *parent):QThread(parent){

    qDebug() << socketDescriptor<<" Created";
    socketDescriptor=ID;
}
void MyThread::run(){
    qDebug()<< socketDescriptor <<" Starting thread";
    socket=new QTcpSocket();
    if(!socket->setSocketDescriptor(this->socketDescriptor)){
        //emit error(socket->error());
        return;
    }
    connect(socket,SIGNAL(readyRead()),this,SLOT(mreadyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(mdisconnect()),Qt::DirectConnection);

    qDebug()<< socketDescriptor << " Client Connected";

    exec();

}

void MyThread::mreadyRead(){

    QByteArray data=socket->readAll();
    qDebug() << socketDescriptor<<" Data in:"<< data;
    socket->write(data);
}

void MyThread::mdisconnect(){
    qDebug()<< socketDescriptor<<" Disconectted";
    socket->deleteLater();
    exit(0);

}
