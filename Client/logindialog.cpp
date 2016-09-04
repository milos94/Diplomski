#include "logindialog.h"
#include "ui_logindialog.h"

LogInDialog::LogInDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogInDialog)
{
    ui->setupUi(this);
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
    cli->sendMessage(message);

    ui->txtUserName->setEnabled(false);
    ui->txtPass->setEnabled(false);
    ui->btnLogIn->setEnabled(false);
}

void LogInDialog::readMessage(QByteArray msg){

    qDebug()<<msg.data();
    QString str=msg.data();
    QStringList list=str.split(' ');

    if(list[0].compare("FAIL1")==0)
        ui->lblStatus->setText("User already logged in!");

    else if(list[0].compare("FAIL2")==0)
        ui->lblStatus->setText("Wrong username/password!");

    else if(list[0].compare("SUCESS")==0){
        cli->setCrypt(list[1].toUtf8(),list[2].toUtf8());
        Client *clWindow= new Client(cli,ui->txtUserName->text());
        disconnect(cli,SIGNAL(ServerMessage(QByteArray)),this,SLOT(readMessage(QByteArray)));
        clWindow->show();
        this->close();
    }

    ui->txtUserName->setEnabled(true);
    ui->txtPass->setEnabled(true);
    ui->btnLogIn->setEnabled(true);
}
