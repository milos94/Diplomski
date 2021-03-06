#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "sslclient.h"
#include "mycrypt.h"
#include "client.h"

namespace Ui {
class LogInDialog;
}

class LogInDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LogInDialog(QWidget *parent = 0);
    ~LogInDialog();

public slots:
    void connectionEstablised(bool);
    void LogInClicked();
    void CancleClicked();
    void readMessage(QByteArray);

private:
    Ui::LogInDialog *ui;
    SslClient *cli;
};

#endif // LOGINDIALOG_H
