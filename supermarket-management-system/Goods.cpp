#include"Goods.h"

QString Goods::getname()
{
    return names;
}

QString Goods::getdate()
{
    return date;
}

QString Goods::getprice()
{
    return QString::number(price);
}

QString Goods::getquan()
{
    return QString::number(quantity);
}

bool Goods::mydelete(int a)
{
    if(a>0 && a<quantity)
    {
        quantity-=a;
        return true;
    }
    else if(a==quantity)
    {
        names="";
        quantity=0;
        return true;
    }
    else return false;
}

void Goods::setquan(int a)
{
    quantity=a;
}
