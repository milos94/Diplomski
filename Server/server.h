#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QMainWindow>
#include <QSslSocket>
#include "myserver.h"
#include "mycrypt.h"

namespace Ui {
class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = 0);
    ~Server();

private:
    MyServer *srv;
    Ui::Server *ui;


};

#endif // SERVER_H
