#ifndef CLIENTARRAY_H
#define CLIENTARRAY_H

#include "myclient.h"
#include <exception>

using namespace std;
class ClientArray
{
private:
    struct Elem{
        MyClient *cl;
        Elem* next;
        Elem* prevous;
        Elem(MyClient* cl1){
            cl=cl1;
            next=prevous=nullptr;
            cl1=nullptr;
        }
    };
    Elem *first,*last;
public:
    ClientArray();
    void add(MyClient*);
    bool contains(QString);
    MyClient* operator[](QString);
    void remove(QString);
};

#endif // CLIENTARRAY_H
