#ifndef MYTASK_H
#define MYTASK_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
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
    MyCrypt *crypt;
    QStringList list;
    void LogIn();
    void startConversation();
    void generateKey();
    void LogOff();

public:
    MyTask(QByteArray,ClientArray*,MyCrypt*,MyClient*);
    ~MyTask();
protected:
    void run();

signals:
    void loggedIn(QByteArray,MyClient*);
    void keyGenerated(QByteArray,MyClient*,MyClient*);
};

#endif // MYTASK_H
