#include "myrunnable.h"

MyRunnable::MyRunnable()
{

}

void MyRunnable::run(){
    if(!socekDesriptor) return;

    QTcpSocket socket;
    socket.setSocketDescriptor(socekDesriptor);

    socket.write("Hello World");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}
