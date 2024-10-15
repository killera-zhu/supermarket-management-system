#include "DailyGoods.h"

DailyGoods::DailyGoods()
{
    
}

void DailyGoods::setDailyGoods(QString a, int b, QString c, double d)
{
    category = "DailyGoods";
    names = a;
    quantity = b;
    date = c;
    price = d;
}

void DailyGoods::setDailyGoods(DailyGoods &r)
{
    category=r.category;
    names=r.names;
    quantity=r.quantity;
    date=r.date;
    price=r.price;
}

void DailyGoods::show()
{
    qDebug()<<category<<names<<quantity<<date<<price;
}

QString DailyGoods::getdetails()
{
    QString text;
    text="category: "+category+"\nname: "+names+"\nquantity: "+QString::number(quantity)+"\nproduction_date: "+date+"\nprice: "+QString::number(price)+"\n\n";
    // text="类别："+category+"\n名字："+names+"\n生产日期："+date+"\n价格："+QString::number(price);
    return text;
}

QString DailyGoods::getname()
{
    return names;
}

