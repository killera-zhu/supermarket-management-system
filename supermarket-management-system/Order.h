#ifndef CIRCLE_H
#define CIRCLE_H
#include<QDebug>
#include<QDateTime>

using namespace std;

class Order
{
protected:
    QString category;
    QString name;
    QString time;
    int quantity, ID;
    double price;
    double money;
    int i;
public:
    QString gettime();
    int geti();
    int getquantity();
    int getID();
    QString getname();
    QString getcategory();
    double getmoney();
    double getprice();
    friend class Returnords;
};

#endif
