#ifndef DAILY_H
#define DAILY_H
#include <QDebug>
#include"Goods.h"

using namespace std;

class DailyGoods : public Goods
{

public:
    DailyGoods();
    void setDailyGoods(QString a, int b, QString c, double d);
    void setDailyGoods(DailyGoods &r);
    void show() override;
    QString getdetails() override;
    QString getname();
};

#endif
