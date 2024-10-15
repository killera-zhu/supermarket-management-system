#ifndef MARKET_H
#define MARKET_H
#include <QDebug>
#include<QFileDialog>

using namespace std;

class Supermarket
{
    QString name;
    double cash;
    double earnings;
    
public:
    Supermarket();
    void FirstLoad(QString s,int x);
    void show();
    void setearnings(double a);
    double getcash();
    QString getname();
};

#endif
