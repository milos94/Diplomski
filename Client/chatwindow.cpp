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
}

ChatWindow::~ChatWindow()
{
    delete ui;
}
void ChatWindow::read(){
    QByteArray data;
    data.append(name+": ");
    data.append(crypt->decrypt(socket->readAll()));
    qDebug()<< data.data();
    ui->txtDisplayMessages->appendPlainText(data);
}

void ChatWindow::send(){
    QByteArray data;
    data.append(ui->txtMessage->text());
    data=crypt->encrypt(data);
    socket->write(data);
    data.clear();
    data.append("You: ");
    data.append(ui->txtMessage->text());
    ui->txtDisplayMessages->appendPlainText(data.data());
    ui->txtMessage->setText("");
}
