#include "myclient.h"
#include "mytask.h"

MyTask::MyTask(QByteArray str,ClientArray* clients,MyClient* cli)
{
    this->str=str;
    this->clients=clients;
    this->cli=cli;
}

void MyTask::run(){

    QString message=str.data();

    list=message.split(' ');

    if(list[0]=="LOGIN") LogIn();
    else if (list[0]=="LOGOFF")  LogOff();
    else if (list[0]== "CONN") startConversation();
    else if (list[0]=="USRLIST") {
        cli->setPort(list[1].toLongLong());
        emit sendOnlineUsers(cli);
    }
}

void MyTask::LogIn(){
    QString logstr="Login started\n"+list[1]+' ';
    QString name="NO";
    QByteArray connKey,connIv;
    QByteArray response;
    if(ClientList::usernames.contains(list[1]) &&
                ClientList::passwords.at(ClientList::usernames.indexOf(list[1]))==list[2]){
        if(clients->contains(list[1])){
                response.append("FAIL1");
                logstr+="Login failed: User already loggedin!";
        }else{
        cli->setName(list[1]);
        clients->add(cli);
        name=list[1];
        connKey=MyCrypt::makeKey();
        connIv=MyCrypt::makeIV();

        logstr+="Login sucessful!";
        response.append("SUCESS "+connKey+' '+connIv);
        }
    }else{
        logstr+="Login failed: Wrong username/password!";
        response.append("FAIL2");
    }

    emit loggedIn(response,cli,name,logstr,connKey,connIv);

}

void MyTask::startConversation(){
    QByteArray response;
    QString logstr;
    if(clients->contains(list[1]) && clients->contains(list[2])){
        QByteArray connKey=MyCrypt::makeKey();
        QByteArray connIv=MyCrypt::makeIV();
        response.append("KEY "+list[2]+' ');
        response.append(connKey+' ');
        response.append(connIv+' ');
        response.append(clients->operator [](list[2])->getAddrAndPort()+' ');
        QByteArray response2;
        response2.append("KEY "+cli->getName()+' '+connKey+' '+connIv);
        response2=clients->operator [](list[2])->encrypt(response2);
        response.append(response2);
        logstr=response.data();
    }else {
        response.append("FAIL3");
        logstr=response.data();
    }
    emit keyGenerated(response,cli,logstr);
}


void MyTask::LogOff(){
    emit disconnected(list[1]);
}

MyTask::~MyTask(){
    cli=nullptr;
    clients=nullptr;
}
