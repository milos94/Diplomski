#include "myclient.h"
#include "mytask.h"

MyTask::MyTask(QByteArray str,ClientArray* clients,MyCrypt *crypt,MyClient* cli)
{
    this->str=str;
    this->clients=clients;
    this->crypt=crypt;
    this->cli=cli;
}

void MyTask::run(){
    str=crypt->decrypt(str);
    QString message=str.data();

    list=message.split(' ');

    if(list[0]=="LOGIN") LogIn();
    else if (list[0]=="LOGOFF")  LogOff();
    else if (list[0]== "CONN") startConversation();
    else if (list[0]=="USRLIST") emit sendOnlineUsers(cli);
}

void MyTask::LogIn(){
    QString logstr="Login started\n"+list[1]+' ';
    QString name="NO";
    QByteArray response;
    if(ClientList::usernames.contains(list[1]) &&
                ClientList::passwords.at(ClientList::usernames.indexOf(list[1]))==list[2]){
        if(clients->contains(list[1])){
                response.append("FAIL1");
                logstr+="Login failed: User already loggedin!";
        }else{
        cli->setName(list[1]);
        cli->setPort(list[3].toLongLong());
        clients->add(cli);

        name=list[1];
        logstr+="Login sucessful!";
        response.append("SUCESS");
        }
    }else{
        logstr+="Login failed: Wrong username/password!";
        response.append("FAIL2");
    }
    response=crypt->encrypt(response);
    emit loggedIn(response,cli,name,logstr);

}

void MyTask::startConversation(){
    QByteArray response;
    QString logstr;
    if(clients->contains(list[1]) && clients->contains(list[2])){
        response.append("KEY "+list[1]+' '+list[2]+' ');
        response.append(crypt->makeKey()+' ');
        response.append(crypt->makeIV()+' ');
        response.append(clients->operator [](list[2])->getAddrAndPort());
        logstr=response.data();
        response=crypt->encrypt(response);
    }else {
        response.append("FAIL3");
        logstr=response.data();
        response=crypt->encrypt(response);
    }
    emit keyGenerated(response,clients->operator [](list[1]),logstr);
}


void MyTask::LogOff(){
    emit disconnected(list[1]);
}

MyTask::~MyTask(){
    cli=nullptr;
    clients=nullptr;
    crypt=nullptr;
}
