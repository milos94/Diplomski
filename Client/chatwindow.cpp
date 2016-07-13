#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QTcpSocket* socket,QString name, QByteArray key, QByteArray iv,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    ui->txtDisplayMessages->setReadOnly(true);
    this->socket=socket;
    this->name=name;
    this->setWindowTitle(name);
    crypt=new MyCrypt(key.data(),iv.data());

    connect(this->socket,SIGNAL(readyRead()),
            this,SLOT(read()),Qt::DirectConnection);

    connect(this->ui->btnSend,SIGNAL(released()),
            this,SLOT(send()),Qt::DirectConnection);

    connect(this->socket,SIGNAL(disconnected()),
            this,SLOT(clientDisconnected()),Qt::DirectConnection);
}

ChatWindow::~ChatWindow()
{
    qDebug()<<"ChatWindow Destructor";
    delete ui;
    delete socket;
    socket=nullptr;
    delete crypt;
}
void ChatWindow::read(){
    QByteArray rData=socket->readAll();
    rData=crypt->decrypt(rData);
    QByteArray data;
    data.append(name+": ");
    data.append(rData);
    qDebug()<<data.data();
    ui->txtDisplayMessages->appendPlainText(data);

}

void ChatWindow::send(){
    QByteArray data;
    data.clear();
    data.append(ui->txtMessage->text());
    data=crypt->encrypt(data);
    socket->write(data);
    qDebug()<<data.data();
    data.clear();
    data.append("You: ");
    data.append(ui->txtMessage->text());
    ui->txtDisplayMessages->appendPlainText(data.data());
    ui->txtMessage->setText("");
}

void ChatWindow::clientDisconnected(){
    ui->txtDisplayMessages->appendPlainText(name+" Disconnected...");
    ui->btnSend->setEnabled(false);
}

void ChatWindow::closeEvent(QCloseEvent *e){

    delete socket;
    socket=nullptr;
    delete crypt;
}
