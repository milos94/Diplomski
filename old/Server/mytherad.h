#ifndef MYTHERAD_H
#define MYTHERAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(int ID, QObject *parent=0);
    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void mreadyRead();
    void mdisconnect();

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // MYTHERAD_H
