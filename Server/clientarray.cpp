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
    for(Elem* pom=first;pom!=nullptr;pom=pom->next){
        if( pom->cl->getName()==descriptor){
            pom->next->prevous=pom->prevous;
            pom->prevous->next=pom->next;
            delete pom;
            break;
        }
    }
}

bool ClientArray::contains(QString descriptor){
    for(Elem* pom=first;pom!=nullptr;pom=pom->next)
        if( pom->cl->getName()==descriptor) return true;
    return false;
}
