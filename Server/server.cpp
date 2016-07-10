#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    if(!QSslSocket::supportsSsl()){
        qDebug()<<"SSL NOT SUPPORTED!";
    }
    srv=new MyServer;
}

Server::~Server()
{
    delete ui;
}
