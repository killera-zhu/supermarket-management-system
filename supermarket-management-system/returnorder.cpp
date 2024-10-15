#include"returnorder.h"

void Returnchaseorder::setreturnchaseorder(Purchaseorder &r,QString k)
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm");

    time=current_date;
    category=r.category;
    name=r.name;
    quantity=r.quantity;
    i=r.i;
    qDebug()<<i<<r.i;
    ID=r.ID;
    reason=k;
    price=r.price;
    money=r.money;
}

QString Returnchaseorder::getreason()
{
    return reason;
}
