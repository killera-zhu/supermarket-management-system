#ifndef _MY_GOODS
#define _MY_GOODS
#include<QDebug>

using namespace std;

class Goods
{
protected:
    QString category;
    QString names;
    QString date;
    int quantity;
    double price;
public:
    void setquan(int a);
    QString getname();
    QString getdate();
    QString getquan();
    QString getprice();
    virtual void show()=0;
    virtual QString getdetails()=0;
    bool mydelete(int a);
};

#endif
