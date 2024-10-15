#ifndef ELE_H
#define ELE_H
#include <QDebug>
#include"Goods.h"

using namespace std;

class ElectricalAppliance : public Goods
{
    QString color;
    int maintenance;

public:
    ElectricalAppliance();
    void setElectricalAppliance(QString a, int b, QString c, QString d, int e,double f);
    void setElectricalAppliance(ElectricalAppliance &r);
    void show() override;
    QString getdetails() override;
    QString getname();
};

#endif
