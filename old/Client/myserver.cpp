#include "myserver.h"

MyServer::MyServer()
{

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

bool MyServer::startServer(qintptr port){
    bool started=this->listen(QHostAddress::Any,port);
    if(started)
        qDebug()<<"Client Server Started on port: "+ port;
    else
        qDebug()<<"Client Server Could Not Start on port: "+port;
    return started;
}
