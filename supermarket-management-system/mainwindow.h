#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<Supermarket.h>
#include<Goods.h>
#include<DailyGoods.h>
#include<ElectricalAppliance.h>
#include<Food.h>
#include<Order.h>
#include<purchaseorder.h>
#include<returnorder.h>
#include <QMainWindow>
#include"form.h"
#include"add.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void reccate(QString a);
    void recfood(Food &r);
    void recelectricalappliance(ElectricalAppliance &r);
    void recdailygoods(DailyGoods &r);

signals:
    void sendSub(QString str);

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);
    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
