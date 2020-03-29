#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogInDialog w;
    w.show();

    return a.exec();
}
