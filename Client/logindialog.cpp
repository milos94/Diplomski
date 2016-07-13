#include "logindialog.h"
#include "ui_logindialog.h"

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
    crypt=new MyCrypt("1AAE0C7222C0D716B4A197321E602F2BE31D4344AF0A0577EE029D23154DA9EA","81D605853779AD15B106C8FDE4E2A9D3");
    connect(ui->btnCancle,SIGNAL(released()),this,SLOT(CancleClicked()),Qt::AutoConnection);
    connect(ui->btnLogIn,SIGNAL(released()),this,SLOT(LogInClicked()),Qt::AutoConnection);
    ui->btnLogIn->setEnabled(false);
    cli=new SslClient;
    cli->start();
    connect(cli,SIGNAL(connectedToServer(bool)),this,SLOT(connectionEstablised(bool)),Qt::DirectConnection);
    connect(cli,SIGNAL(ServerMessage(QByteArray)),this,SLOT(readMessage(QByteArray)));

}

LogInDialog::~LogInDialog()
{
    delete ui;
}

void LogInDialog::connectionEstablised(bool ok){
    if(ok){
        ui->label->setText("Connected to server!");
        ui->btnLogIn->setEnabled(true);
    }
    else
        ui->label->setText("Unable to connect to server!");
}

void LogInDialog::CancleClicked(){

    this->close();
}

void LogInDialog::LogInClicked(){

    QByteArray message("LOGIN ");

    message.append(ui->txtUserName->text()+' ');
    message.append(ui->txtPass->text());
    message=crypt->encrypt(message);
    cli->sendMessage(message);

    ui->txtUserName->setEnabled(false);
    ui->txtPass->setEnabled(false);
    ui->btnLogIn->setEnabled(false);
}

void LogInDialog::readMessage(QByteArray msg){
    qDebug()<<msg.data();
    msg=crypt->decrypt(msg);
    qDebug()<<msg.data();
    QString str=msg.data();
    if(str.compare("FAIL1")==0)
        ui->lblStatus->setText("User already logged in!");
    else if(str.compare("FAIL2")==0)
        ui->lblStatus->setText("Wrong username/password!");    
    else if(str.compare("SUCESS")==0){
        Client *clWindow= new Client(cli,crypt,ui->txtUserName->text());
        clWindow->show();
        disconnect(cli,SIGNAL(ServerMessage(QByteArray)),this,SLOT(readMessage(QByteArray)));
        this->close();
    }
    ui->txtUserName->setEnabled(true);
    ui->txtPass->setEnabled(true);
    ui->btnLogIn->setEnabled(true);
}
