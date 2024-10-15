#ifndef PURCHASEORDER_H
#define PURCHASEORDER_H

#include"Order.h"

class Purchaseorder: public Order
{

public:
    Purchaseorder();

    void setPurchaseorder(QString t,QString a,QString b,int c,int d,int e,double f);
    void seti(int a);

    friend class Returnchaseorder;
};

#endif // PURCHASEORDER_H
