#include "myserver.h"

MyServer::MyServer(QTextEdit *txt,QListWidget *lst,QObject *parent):QTcpServer(parent)
{
    log=txt;
    userList=lst;
    bool ok=true;

    clients=new ClientArray;
    crypt=new MyCrypt;

    QByteArray key;
    QByteArray cert;

    log->append("Loading key...");

    QFile file_key("cert.key");

    if(file_key.open(QIODevice::ReadOnly))
    {
        key = file_key.readAll();
        file_key.close();
    }
    else
    {
        ok=false;
        log->append(file_key.errorString());
    }
    sslKey=new QSslKey(key,QSsl::Rsa);
    log->append("RSA key loaded");

    log->append("Loading certificate...");
    QFile file_cert("cert.crt");
    if(file_cert.open(QIODevice::ReadOnly))
    {
        cert = file_cert.readAll();
        file_cert.close();
    }
    else
    {
        ok=false;
        log->append(file_cert.errorString());
    }

    sslCertificate=new QSslCertificate(cert);
    log->append("Certificate loaded");

    if(ok)
        StartServer();
}

void MyServer::StartServer(){
    log->append("Starting server...");
    if(this->listen(QHostAddress::LocalHost,1234)){
        log->append("Server Started");
    }else{
        log->append("Server could not start");
    }

}

void MyServer::incomingConnection(qintptr socketDescriptor){

    MyClient *client=new MyClient(this);
    client->setSocket(socketDescriptor,*sslKey,*sslCertificate);

    connect(client,SIGNAL(msgRcv(QByteArray,MyClient*)),
            this,SLOT(messageReceived(QByteArray,MyClient*)),Qt::QueuedConnection);

    connect(client,SIGNAL(cliDisconeccted(QString)),
            this,SLOT(clientDisconected(QString)),Qt::DirectConnection);

    connect(client,SIGNAL(logMessage(QString)),
            this,SLOT(logMessage(QString)),Qt::AutoConnection);
}

void MyServer::messageReceived(QByteArray str,MyClient* cli){

    MyTask *task=new MyTask(str,clients,crypt,cli);

    task->setAutoDelete(true);

    connect(task,SIGNAL(loggedIn(QByteArray,MyClient*,QString,QString)),
            this,SLOT(loggedIn(QByteArray,MyClient*,QString,QString)),Qt::QueuedConnection);

    connect(task,SIGNAL(keyGenerated(QByteArray,MyClient*,MyClient*,QString)),
            this,SLOT(keyGenerated(QByteArray,MyClient*,MyClient*,QString)),Qt::QueuedConnection);

    connect(task,SIGNAL(disconnected(QString)),
            this,SLOT(clientDisconected(QString)),Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(task);
}

void MyServer::loggedIn(QByteArray msg, MyClient *client,QString name,QString logmessage){

    client->sendMessage(msg);
    log->append(logmessage);
    if(name.compare("NO")!=0)
        userList->addItem(new QListWidgetItem(name));

}

void MyServer::keyGenerated(QByteArray data, MyClient *first, MyClient *second,QString msg){

    if(first!=nullptr) first->sendMessage(data);
    //if(second!=nullptr) second->sendMessage(data);

    log->append(msg);
}

void MyServer::clientDisconected(QString name){

    clients->remove(name);

}

void MyServer::logMessage(QString msg){

    log->append(msg);
}

 MyServer::~MyServer(){
     userList=nullptr;
     log=nullptr;
     delete sslKey;
     delete sslCertificate;
     delete clients;
     delete crypt;
 }
