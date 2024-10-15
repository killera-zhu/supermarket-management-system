#include "add.h"
#include "ui_add.h"
#include<QInputDialog>

Add::Add(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Add)
{
    ui->setupUi(this);
}

Add::~Add()
{
    delete ui;
}

void Add::on_pushButton_2_clicked()
{
    Food newfood;
    bool ok1,ok2,ok3,ok4,ok5;
    QString sname = QInputDialog::getText(this, tr("增加食品"),tr("请输入商品名："), QLineEdit::Normal,tr("banana"), &ok1);
    if(ok1) qDebug() << "string:" << sname;
    QString squan = QInputDialog::getText(this, tr("增加食品"),tr("请输入数量："), QLineEdit::Normal,tr("1"), &ok2);
    if(ok2) qDebug() << "string:" << squan;
    QString sdate = QInputDialog::getText(this, tr("增加食品"),tr("请输入生产日期："), QLineEdit::Normal,tr("2024/5/29"), &ok3);
    if(ok3) qDebug() << "string:" << sdate;
    QString sprice = QInputDialog::getText(this, tr("增加食品"),tr("请输入价格："), QLineEdit::Normal,tr("5"), &ok4);
    if(ok4) qDebug() << "string:" << sprice;
    QString speriod = QInputDialog::getText(this, tr("增加食品"),tr("请输入保质期："), QLineEdit::Normal,tr("20"), &ok5);
    if(ok5) qDebug() << "string:" << speriod;
    if(ok1 && ok2 && ok3 && ok4 && ok5)
    {
        newfood.setFood(sname, squan.toInt(), sdate, speriod.toInt(), sprice.toDouble());
        emit sendfood(newfood);
        qDebug()<<"sentnew";
    }
}



void Add::on_pushButton_3_clicked()
{
    DailyGoods newdailygood;
    bool ok1,ok2,ok3,ok4;
    QString sname = QInputDialog::getText(this, tr("增加日常用品"),tr("请输入商品名："), QLineEdit::Normal,tr("cap"), &ok1);
    if(ok1) qDebug() << "string:" << sname;
    QString squan = QInputDialog::getText(this, tr("增加日常用品"),tr("请输入数量："), QLineEdit::Normal,tr("1"), &ok2);
    if(ok2) qDebug() << "string:" << squan;
    QString sdate = QInputDialog::getText(this, tr("增加日常用品"),tr("请输入生产日期："), QLineEdit::Normal,tr("2024/5/29"), &ok3);
    if(ok3) qDebug() << "string:" << sdate;
    QString sprice = QInputDialog::getText(this, tr("增加日常用品"),tr("请输入价格："), QLineEdit::Normal,tr("5"), &ok4);
    if(ok4) qDebug() << "string:" << sprice;
    if(ok1 && ok2 && ok3 && ok4)
    {
        newdailygood.setDailyGoods(sname, squan.toInt(), sdate, sprice.toInt());
        emit senddailygood(newdailygood);
        qDebug()<<"sentnew";
    }
}


void Add::on_pushButton_4_clicked()
{
    ElectricalAppliance newelectricalappliance;
    bool ok1,ok2,ok3,ok4,ok5,ok6;
    QString sname = QInputDialog::getText(this, tr("增加家电"),tr("请输入商品名："), QLineEdit::Normal,tr("computer"), &ok1);
    if(ok1) qDebug() << "string:" << sname;
    QString squan = QInputDialog::getText(this, tr("增加家电"),tr("请输入数量："), QLineEdit::Normal,tr("1"), &ok2);
    if(ok2) qDebug() << "string:" << squan;
    QString sdate = QInputDialog::getText(this, tr("增加家电"),tr("请输入生产日期："), QLineEdit::Normal,tr("2024/5/29"), &ok3);
    if(ok3) qDebug() << "string:" << sdate;
    QString scolor = QInputDialog::getText(this, tr("增加家电"),tr("请输入颜色："), QLineEdit::Normal,tr("black"), &ok4);
    if(ok4) qDebug() << "string:" << scolor;
    QString speriod = QInputDialog::getText(this, tr("增加家电"),tr("请输入保修期："), QLineEdit::Normal,tr("365"), &ok5);
    if(ok5) qDebug() << "string:" << speriod;
    QString sprice = QInputDialog::getText(this, tr("增加家电"),tr("请输入价格："), QLineEdit::Normal,tr("5"), &ok6);
    if(ok6) qDebug() << "string:" << sprice;

    if(ok1 && ok2 && ok3 && ok4 && ok5 && ok6)
    {
        newelectricalappliance.setElectricalAppliance(sname, squan.toInt(), sdate, scolor,speriod.toInt(),sprice.toDouble());
        emit sendelectricalappliance(newelectricalappliance);
        qDebug()<<"sentnew";
    }
}

