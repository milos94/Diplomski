#ifndef MYTASK_H
#define MYTASK_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <QListWidget>
#include <QTextEdit>
#include "mycrypt.h"
#include "myclient.h"
#include "myclientarray.h"
#include "clientslist.h"
#include "clientarray.h"

using namespace std;
class MyTask : public QObject, public QRunnable
{
    Q_OBJECT
private:
    MyClient* cli;
    QByteArray str;
    ClientArray *clients;
    QStringList list;
    void LogIn();
    void startConversation();
    void generateKey();
    void LogOff();

public:
    MyTask(QByteArray,ClientArray*,MyClient*);
    ~MyTask();
protected:
    void run();

signals:
    void loggedIn(QByteArray,MyClient*,QString,QString,QByteArray,QByteArray);
    void keyGenerated(QByteArray,MyClient*,QString);
    void disconnected(QString);
    void sendOnlineUsers(MyClient*);
};

#endif // MYTASK_H
