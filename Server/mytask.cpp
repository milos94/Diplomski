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
    for(int i=0;i<list.length();i++)
        qDebug()<<list[i];
    if(list[0].compare("LOGIN")==0) LogIn();
    else if (list[0]=="LOGOFF")  LogOff();
    else if (list[0]== "CONN") startConversation();
}

void MyTask::LogIn(){
    qDebug()<<"LOGIN STARTED";
    QByteArray response;
    if(ClientList::usernames.contains(list[1]) &&
                ClientList::passwords.at(ClientList::usernames.indexOf(list[1]))==list[2]){
        if(clients->contains(list[1])){
                response.append("FAIL1");
        }else{
        cli->setName(list[1]);
        clients->add(cli);
        response.append("SUCESS");
        }
    }else{
        response.append("FAIL2");
    }
    qDebug()<<response.data();
    response=crypt->encrypt(response);
    emit loggedIn(response,cli);

}

void MyTask::startConversation(){
    QByteArray response;
    if(clients->contains(list[1]) || clients->contains(list[2])){
        response.append("KEY "+list[1]+' '+list[2]+' ');
        response.append(crypt->makeKey()+' ');
        response.append(crypt->makeIV());
        response=crypt->encrypt(response);
    }else {
        response.append("User not online!");
    }
    emit keyGenerated(response,clients->operator [](list[1]),clients->operator [](list[2]));
}


void MyTask::LogOff(){

}
