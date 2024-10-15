#include"Food.h"

Food::Food()
{
    
}

void Food::setFood(QString a, int b, QString c, int d, double e)
{
    category = "food";
    names = a;
    quantity = b;
    date = c;
    guarantee = d;
    price = e;
}

void Food::setFood(Food &r)
{
    category=r.category;
    names=r.names;
    quantity=r.quantity;
    date=r.date;
    guarantee=r.guarantee;
    price=r.price;
}

void Food::show()
{
    qDebug()<<category<<names<<quantity<<date<<guarantee<<price;
}

QString Food::getdetails()
{
    QString text;
    text="category: "+category+"\nname: "+names+"\nquantity: "+QString::number(quantity)+"\nproduction_date: "+date+"\nguarantee_period: "+QString::number(guarantee)+"\nprice: "+QString::number(price)+"\n\n";
    return text;
}

int Food::getperiod()
{
    return guarantee;
}

