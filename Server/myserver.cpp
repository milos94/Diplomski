#include "myserver.h"

MyServer::MyServer(QTextEdit *txt,QListWidget *lst,QObject *parent):QTcpServer(parent)
{
    log=txt;
    userList=lst;
    bool ok=true;

    log->setReadOnly(true);

    clients=new ClientArray;

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
    if(this->listen(QHostAddress::Any,1234)){
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

    MyTask *task=new MyTask(str,clients,cli);

    task->setAutoDelete(true);

    connect(task,SIGNAL(loggedIn(QByteArray,MyClient*,QString,QString,QByteArray,QByteArray)),
            this,SLOT(loggedIn(QByteArray,MyClient*,QString,QString,QByteArray,QByteArray)),Qt::QueuedConnection);

    connect(task,SIGNAL(keyGenerated(QByteArray,MyClient*,QString)),
            this,SLOT(keyGenerated(QByteArray,MyClient*,QString)),Qt::QueuedConnection);

    connect(task,SIGNAL(disconnected(QString)),
            this,SLOT(clientDisconected(QString)),Qt::QueuedConnection);

    connect(task,SIGNAL(sendOnlineUsers(MyClient*)),
            this,SLOT(sendOnlineUsers(MyClient*)),Qt::QueuedConnection);

    QThreadPool::globalInstance()->start(task);
}

void MyServer::loggedIn(QByteArray msg, MyClient *client,QString name,QString logmessage,QByteArray connKey, QByteArray connIv){


    client->sendMessage(msg);
    client->setCrypt(connKey.data(),connIv.data());
    log->append(logmessage);
    qDebug()<<msg.data();

    if(name.compare("NO")!=0){
        QByteArray data;
        data.append(name);
        userList->addItem(name);
        for(QString s : onlineUsers)
            clients->operator [](s)->sendMessage(data);

        onlineUsers.append(name);
    }
}

void MyServer::keyGenerated(QByteArray data, MyClient *first,QString msg){

    if(first!=nullptr) first->sendMessage(data);

    log->append(msg);
}

void MyServer::clientDisconected(QString name){
    onlineUsers.removeAt(onlineUsers.indexOf(name));
    userList->clear();
    clients->remove(name);
    MyClient *temp;
    QByteArray data;
    data.append("DISCC "+name);
    for(QString s : onlineUsers){
        userList->addItem(s);
        temp=clients->operator [](s);
        temp->sendMessage(data);
    }
    temp=nullptr;
    data.clear();
}

void MyServer::logMessage(QString msg){

    log->append(msg);
}
void MyServer::sendOnlineUsers(MyClient *cli){
    QByteArray msg;
    for(QString s : onlineUsers)
        msg.append(s+' ');
    cli->sendMessage(msg);

}

 MyServer::~MyServer(){
     userList=nullptr;
     log=nullptr;
     delete sslKey;
     delete sslCertificate;
     delete clients;
 }
