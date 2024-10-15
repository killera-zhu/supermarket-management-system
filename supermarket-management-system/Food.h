#ifndef FOOD_H
#define FOOD_H
#include <QDebug>
#include"Goods.h"
using namespace std;

class Food : public Goods
{
    int guarantee;

public:
    Food();
    void setFood(QString a, int b, QString c, int d, double e);
    void setFood(Food &r);
    int getperiod();
    void show() override;
    QString getdetails() override;
};

#endif
