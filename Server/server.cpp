#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    if(!QSslSocket::supportsSsl()){
        ui->txtLog->append("SSL NOT SUPPORTED!\n\r");
    }else{
    srv=new MyServer(ui->txtLog,ui->listUsers,this);
    }
}

Server::~Server()
{
    delete ui;
}
