#ifndef ADD_H
#define ADD_H

#include <QWidget>
#include<Goods.h>
#include<DailyGoods.h>
#include<ElectricalAppliance.h>
#include<Food.h>

namespace Ui {
class Add;
}

class Add : public QWidget
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();

    void recMain(QString str);
signals:
    void sendcate(QString a);
    void sendfood(Food &r);
    void senddailygood(DailyGoods &r);
    void sendelectricalappliance(ElectricalAppliance &r);
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Add *ui;
};

#endif // ADD_H
