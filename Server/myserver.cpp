#include "myserver.h"
#include <crypto++/hex.h>

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
    clients=new ClientArray;
    crypt=new MyCrypt;
    StartServer();
}

void MyServer::StartServer(){
    qDebug()<<"Starting server...";
    if(this->listen(QHostAddress::LocalHost,1234)){
        qDebug()<<"Server Started";
    }else{
        qDebug()<<"Server could not start";
    }

}

void MyServer::incomingConnection(qintptr socketDescriptor){
    MyClient *client=new MyClient(this);
    client->setSocket(socketDescriptor);
    connect(client,SIGNAL(msgRcv(QByteArray,MyClient*)),
            this,SLOT(messageReceived(QByteArray,MyClient*)),Qt::QueuedConnection);
    connect(client,SIGNAL(cliDisconeccted(QString)),
            this,SLOT(clientDisconected(QString)),Qt::DirectConnection);
}

void MyServer::messageReceived(QByteArray str,MyClient* cli){
    MyTask *task=new MyTask(str,clients,crypt,cli);
    task->setAutoDelete(true);
    connect(task,SIGNAL(loggedIn(QByteArray,MyClient*)),
            this,SLOT(loggedIn(QByteArray,MyClient*)),Qt::QueuedConnection);
    connect(task,SIGNAL(keyGenerated(QByteArray,MyClient*,MyClient*)),
            this,SLOT(keyGenerated(QByteArray,MyClient*,MyClient*)),Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(task);
}

void MyServer::loggedIn(QByteArray msg, MyClient *client){
    client->sendMessage(msg);
    qDebug()<<msg.data();
}

void MyServer::keyGenerated(QByteArray data, MyClient *first, MyClient *second){
    if(first!=nullptr) first->sendMessage(data);
    if(second!=nullptr) second->sendMessage(data);
}

void MyServer::clientDisconected(QString name){
    try{
    clients->remove(name);
    }catch(exception e)
    {
        qDebug()<<e.what();
    }
}

