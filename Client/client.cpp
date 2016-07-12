#include "client.h"
#include "ui_client.h"

Client::Client(SslClient* client,MyCrypt* crypt,QString name,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    this->setWindowTitle(name);
    this->port=12351;
    this->client=client;
    this->crypt=crypt;
    this->name=name;
    this->server=new MyServer(port);

    connect(client,SIGNAL(ServerMessage(QByteArray)),
            this,SLOT(ServerMessage(QByteArray)),Qt::DirectConnection);

    connect(server,SIGNAL(someoneConnected(QByteArray,QTcpSocket*)),
            this,SLOT(someoneConnected(QByteArray,QTcpSocket*)));

    connect(ui->btnStartChat,SIGNAL(released()),
            this,SLOT(startChat_click()));
}

Client::~Client()
{
    delete ui;
    delete client;
    delete crypt;
    socket=nullptr;
}

void Client::ServerMessage(QByteArray msg){
    message=crypt->decrypt(msg);
    QString str=message.data();
    strList=str.split(' ');


    if(strList[0].compare("KEY")==0){
        if(strList[2].compare(name)==0){
            socket=new QTcpSocket;
            qintptr port=strList[6].toLongLong();
            socket->connectToHost(strList[5],port);
            connect(socket,SIGNAL(connected()),this,SLOT(socketConnected()));
        }
     }else if(strList[0].compare("FAIL3")){
        qDebug()<<"Korisnik nije online";
    }
 }

void Client::socketConnected(){
    socket->write(crypt->encrypt(message));
    QByteArray key,iv;
    key.append(strList[3]);
    iv.append(strList[4]);
    ChatWindow *c=new ChatWindow(socket,strList[2],key,iv);
    c->show();
    socket=nullptr;
    this->hide();
}

void Client::someoneConnected(QByteArray data, QTcpSocket *sock){
    data=crypt->decrypt(data);
    QString str=data.data();
    strList=str.split(' ');
    QByteArray key,iv;
    key.append(strList[3]);
    iv.append(strList[4]);
    ChatWindow *c=new ChatWindow(sock,strList[1],key,iv);
    c->show();
    this->hide();
}

void Client::startChat_click(){
    QByteArray message;
    message.append("CONN "+name+' '+ui->lineEdit->text()+' '+QString::number(port));
    client->sendMessage(crypt->encrypt(message));
}
