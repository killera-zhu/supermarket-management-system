#include"purchaseorder.h"

Purchaseorder::Purchaseorder()
{
    i=-1;
}

void Purchaseorder::setPurchaseorder(QString t,QString a,QString b,int c,int d,int e,double f)
{
    time=t;
    category=a;
    name=b;
    quantity=c;
    i=d;
    ID=e;
    price=f;
    money=f*c;
}

void Purchaseorder::seti(int a)
{
    i=a;
}
