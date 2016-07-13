#include "myserver.h"

MyServer::MyServer(qintptr port)
{
    if(this->listen(QHostAddress::Any,port))
        qDebug()<<"Client Server Started";
    else
        qDebug()<<"Client Server Could Not Start";
}

void MyServer::incomingConnection(qintptr descriptor){
    MyClient *cli=new MyClient;
    cli->setSocket(descriptor);
    connect(cli,SIGNAL(msgRcv(QByteArray,QTcpSocket*)),
            this,SLOT(msgRcv(QByteArray,QTcpSocket*)));
}

void MyServer::msgRcv(QByteArray msg,QTcpSocket* soc){
    emit someoneConnected(msg,soc);
    soc=nullptr;
}
