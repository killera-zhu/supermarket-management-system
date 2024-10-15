#ifndef RETURNORDER_H
#define RETURNORDER_H

#include"Order.h"
#include"purchaseorder.h"

class Returnchaseorder: public Order
{
    QString reason;
public:
    void setreturnchaseorder(Purchaseorder &r,QString k);
    QString getreason();
};

#endif // RETURNORDER_H
