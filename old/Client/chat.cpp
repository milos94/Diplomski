#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket* socket,QString name, QByteArray key, QByteArray iv, QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Chat)
{
    ui->setupUi(this);
    ui->txtDisplayMessages->setReadOnly(true);
    this->socket=socket;
    this->setWindowTitle(name);
    crypt=new MyCrypt(key.data(),iv.data());

    connect(this->socket,SIGNAL(readyRead()),
            this,SLOT(read()),Qt::DirectConnection);

    connect(this->ui->btnSend,SIGNAL(released()),
            this,SLOT(send()),Qt::DirectConnection);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::read(){
    ui->txtDisplayMessages->appendPlainText(crypt->decrypt(socket->readAll()));
}

void Chat::send(){
    QByteArray data;
    data.append(ui->txtMessage->text());
    data=crypt->encrypt(data);
    socket->write(data);
    ui->txtMessage->setText("");
}
