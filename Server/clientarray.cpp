#include "clientarray.h"

ClientArray::ClientArray()
{
  first=last=nullptr;
}
void ClientArray::add(MyClient *c){
    if(first==0){
        first=last=new Elem(c);
    }else{
        Elem* pom=last;
        last->next=new Elem(c);
        last=last->next;
        last->prevous=pom;
    }
}
MyClient* ClientArray::operator [](QString descripror){
    for(Elem* pom=first;pom!=nullptr;pom=pom->next)
        if( pom->cl->getName()==descripror) return pom->cl;
    return nullptr;
}

void ClientArray::remove(QString descriptor){
    try{
    for(Elem* pom=first;pom!=nullptr;pom=pom->next){
        if( pom->cl->getName()==descriptor){
            if(pom==first)
                first=first->next;
            if(pom==last)
                last=last->prevous;
            if(pom->next!=nullptr)
                pom->next->prevous=pom->prevous;
            if(pom->prevous!=nullptr)
                pom->prevous->next=pom->next;
            delete pom;
            break;
        }
    }
    }catch(exception e){
        qDebug()<<e.what();
    }
}

bool ClientArray::contains(QString descriptor){
    for(Elem* pom=first;pom!=nullptr;pom=pom->next)
        if( pom->cl->getName()==descriptor) return true;
    return false;
}
