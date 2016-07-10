#ifndef MYRUNNABLE_H
#define MYRUNNABLE_H

#include <QObject>
#include <QRunnable>
#include <QTcpSocket>
#include <QDebug>

class MyRunnable : public QRunnable
{
public:
    MyRunnable();
    qintptr socekDesriptor;

protected:
    void run();
};

#endif // MYRUNNABLE_H
