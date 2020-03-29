#include "client.h"
#include "ui_client.h"

Client::Client(SslClient* client,QString name,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowTitle(name);
    this->port=12350;
    this->client=client;
    this->name=name;
    this->server=new MyServer;

    while(!server->startServer(port)){
        port++;
    }

    connect(client,SIGNAL(ServerMessage(QByteArray)),
            this,SLOT(ServerMessage(QByteArray)),Qt::DirectConnection);

    connect(server,SIGNAL(someoneConnected(QByteArray,QTcpSocket*)),
            this,SLOT(someoneConnected(QByteArray,QTcpSocket*)));

    connect(ui->btnStartChat,SIGNAL(released()),
            this,SLOT(startChat_click()));


    QByteArray msg;
    msg.append("USRLIST "+QString::number(port));

    client->sendMessage(msg);

}

Client::~Client()
{
    delete ui;
    delete client;
    socket=nullptr;
}

void Client::ServerMessage(QByteArray msg){

    message=msg;
    qDebug()<<message.data();
    QString str=message.data();
    strList=str.split(' ');
    if(strList[0].compare("KEY")==0){
            socket=new QTcpSocket;
            qintptr port=strList[5].toLongLong();
            socket->connectToHost(strList[4],port);
            message=strList[6].toUtf8();
            connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));

     }else if(strList[0].compare("FAIL3")==0){
        qDebug()<<"Korisnik nije online";


    }else if(strList[0].compare("DISCC")==0){
        onlineUsers.removeAt(onlineUsers.indexOf(strList[1]));
        ui->lstUsers->clear();
        for(QString s:onlineUsers)
            ui->lstUsers->addItem(s);
    }


    else{
        for(QString s : strList){
            if(s!=name && s!=""){
                qDebug()<<s;
                onlineUsers.append(s);
                ui->lstUsers->addItem(s);
            }
        }
    }
 }

void Client::socketConnected(){

    socket->write(message);
    QByteArray key,iv;
    key.append(strList[2]);
    iv.append(strList[3]);
    ChatWindow *c=new ChatWindow(socket,strList[1],key,iv);
    socket=nullptr;
    c->show();
}

void Client::someoneConnected(QByteArray data, QTcpSocket *sock){

    data=client->decrypt(data);
    qDebug()<<data.data();
    QString str=data.data();
    strList=str.split(' ');
    QByteArray key,iv;
    key.append(strList[2]);
    iv.append(strList[3]);
    ChatWindow *c=new ChatWindow(sock,strList[1],key,iv);
    sock=nullptr;
    c->show();
}

void Client::startChat_click(){

    QByteArray message;
    QListWidgetItem *selected=ui->lstUsers->currentItem();
    if(selected!=nullptr){
        message.append("CONN "+name+' '+ selected->text() +' '+ QString::number(port));
        client->sendMessage(message);
        selected=nullptr;
    }
}

