#include "Supermarket.h"

Supermarket::Supermarket()
{
    name = "null";
    cash = 0;
}
void Supermarket::FirstLoad(QString s,int x)
{
    name = s;
    cash = x;
}
void Supermarket::show()
{
    qDebug()<<"mymarket"<<name<<cash;
}

void Supermarket::setearnings(double a)
{
    earnings=a;
}

double Supermarket::getcash()
{
    return cash+earnings;
}

QString Supermarket::getname()
{
    return name;
}
