#include "myserver.h"

MyServer::MyServer(QObject *parent):QTcpServer(parent)
{
    bool ok=true;

    clients=new ClientArray;
    crypt=new MyCrypt;

    QByteArray key;
    QByteArray cert;

    qDebug()<<"Loading key...";

    QFile file_key("cert.key");

    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {
        ok=false;
        qDebug() << file_key.errorString();
    }
    sslKey=new QSslKey(key,QSsl::Rsa);
    qDebug()<<"RSA key loaded";

    qDebug()<<"Loading certificate...";
    QFile file_cert("cert.crt");
    if(file_cert.open(QIODevice::ReadOnly))
    {
        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        ok=false;
        qDebug() << file_cert.errorString();
    }

    sslCertificate=new QSslCertificate(cert);
    qDebug()<<"Certificate loaded";

    if(ok)
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
    client->setSocket(socketDescriptor,*sslKey,*sslCertificate);

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

 MyServer::~MyServer(){

     delete sslKey;
     delete sslCertificate;
     delete clients;
     delete crypt;
 }
