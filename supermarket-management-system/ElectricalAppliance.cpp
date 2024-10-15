#include "ElectricalAppliance.h"

ElectricalAppliance::ElectricalAppliance()
{
    
}

void ElectricalAppliance::setElectricalAppliance(QString a, int b, QString c, QString d, int e,double f)
{
    category = "ElectricalAppliance";
    names = a;
    quantity = b;
    date = c;
    color = d;
    maintenance = e;
    price=f;
}

void ElectricalAppliance::setElectricalAppliance(ElectricalAppliance &r)
{
    category=r.category;
    names=r.names;
    quantity=r.quantity;
    date=r.date;
    color=r.color;
    maintenance=r.maintenance;
    price=r.price;
}

void ElectricalAppliance::show()
{
    qDebug()<<category<<names<<quantity<<date<<color<<maintenance<<price;
}

QString ElectricalAppliance::getdetails()
{
    QString text;
    text="category: "+category+"\nname: "+names+"\nquantity: "+QString::number(quantity)+"\nproduction_date: "+date+"\ncolor: "+color+"\nmaintence: "+QString::number(maintenance)+"\nprice: "+QString::number(price)+"\n\n";
    // text="类别："+category+"\n名字："+names+"\n生产日期："+date+"\n颜色："+color+"\n保修期："+QString::number(maintenance)+"\n价格："+QString::number(price);
    return text;
}

QString ElectricalAppliance::getname()
{
    return names;
}

