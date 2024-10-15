#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "form.h"
#include "add.h"
#include <QDebug>
#include<QFileDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<iostream>
#include<QDateTime>

const int N=30;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Supermarket mymarket;
Food myfood[N];
ElectricalAppliance myelectricalappliance[N];
DailyGoods mydailygoods[N];
Purchaseorder mypurchaseorder[10*N];
Returnchaseorder myreturnchaseorder[10*N];
int fi=0,ei=0,di=0,pi=1,ri=0,RowCont=0;
double earnings=0;
QString now,category,path;

double operator*(int a,Goods &r)
{
    return a*r.getprice().toDouble();
}

ostream& operator<<(ostream &cout, Purchaseorder &a)
{
    QString orderstring="time:"+a.gettime()+"\nID:"+QString::number(a.getID())+"\ncategory:"+a.getcategory()+"\nname:"+a.getname()+"\nprice:"+QString::number(a.getprice())+"\npurchase number:"+QString::number(a.getquantity())+"\ntotal money:"+QString::number(a.getmoney());

    QMessageBox abox;
    abox.setText(orderstring);
    abox.setWindowTitle("购买提示窗口");
    abox.exec();

    QString path = "./purchase"+QString::number(a.getID())+".txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream in(&file);
        in<<"time:"<<a.gettime()<<"\nID:"<<a.getID()<<"\ncategory:"<<a.getcategory()<<"\nname:"<<a.getname()<<"\nprice:"<<a.getprice()<<"\npurchase number:"<<a.getquantity()<<"\ntotal money:"<<a.getmoney();
    }
    file.close();
    return cout;
}

ostream& operator<<(ostream &cout, Returnchaseorder &a)
{
    QString orderstring="time:"+a.gettime()+"\nID:"+QString::number(a.getID())+"\nreason:"+a.getreason()+"\ncategory:"+a.getcategory()+"\nname:"+a.getname()+"\nprice:"+QString::number(a.getprice())+"\npurchase number:"+QString::number(a.getquantity())+"\ntotal money:"+QString::number(a.getmoney());

    QMessageBox abox;
    abox.setText(orderstring);
    abox.setWindowTitle("退货提示窗口");
    abox.exec();

    QString path = "./return"+QString::number(a.getID())+".txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream in(&file);
        in<<"time:"<<a.gettime()<<"\nID:"<<a.getID()<<"\nreason:"<<a.getreason()<<"\ncategory:"<<a.getcategory()<<"\nname:"<<a.getname()<<"\nprice:"<<a.getprice()<<"\npurchase number:"<<a.getquantity()<<"\ntotal money:"<<a.getmoney();
    }
    file.close();
    return cout;
}

ostream& operator<<(ostream &cout, Food &a)
{
    QString path = "./market_out.txt";
    QFile file(path);
    if(file.open(QIODevice::Append))
    {
        QTextStream in(&file);
        in<<a.getdetails();
    }
    file.close();
    return cout;
}

ostream& operator<<(ostream &cout, ElectricalAppliance &a)
{
    QString path = "./market_out.txt";
    QFile file(path);
    if(file.open(QIODevice::Append))
    {
        QTextStream in(&file);
        in<<a.getdetails();
    }
    file.close();
    return cout;
}

ostream& operator<<(ostream &cout, DailyGoods &a)
{
    QString path = "./market_out.txt";
    QFile file(path);
    if(file.open(QIODevice::Append))
    {
        QTextStream in(&file);
        in<<a.getdetails();
    }
    file.close();
    return cout;
}

ostream& operator<<(ostream &cout, Supermarket &a)
{
    QString path = "./market_out.txt";
    QFile file(path);
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream in(&file);
        QString buffer="Name: "+a.getname()+"\nCash: "+QString::number(a.getcash())+"\n\n";
        in<<buffer;
    }
    file.close();
    for(int i=0;i<fi;i++)
    {
        if(myfood[i].getname()!="" && myfood[i].getquan().toInt()!=0)
        {
            cout<<myfood[i];
        }
    }
    for(int i=0;i<di;i++)
    {
        if(mydailygoods[i].getname()!="" && mydailygoods[i].getquan().toInt()!=0)
        {
            cout<<mydailygoods[i];
        }
    }
    for(int i=0;i<ei;i++)
    {
        if(myelectricalappliance[i].getname()!="" && myelectricalappliance[i].getquan().toInt()!=0)
        {
            cout<<myelectricalappliance[i];
        }
    }

    return cout;
}

istream& operator>>(istream &cin, Supermarket &a)
{
    QFile file(path);
    QDateTime nowtime = QDateTime::currentDateTime();

    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        QString buffer,sname,scash,scate,squan,sdate,speriod,sprice,scolor;
        while(!in.atEnd())
        {
            buffer = in.readLine();
            if(buffer.startsWith("Name:"))
            {
                sname=buffer.section(' ',1,1);
            }
            if(buffer.startsWith("Cash:"))
            {
                scash=buffer.section(' ',1,1);
                a.FirstLoad(sname,scash.toInt());
                a.show();
            }
            if(buffer.startsWith("category"))
            {
                scate=buffer.section(' ',1,1);
                qDebug()<<scate;
                if(scate=="food")
                {
                    buffer = in.readLine();
                    sname=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    squan=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sdate=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    speriod=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sprice=buffer.section(' ',1,1);
                    int y=sdate.section('/',0,0).toInt();
                    int m=sdate.section('/',1,1).toInt();
                    int d=sdate.section('/',2,2).toInt();
                    QDateTime foodtime(QDate(y,m,d), QTime(0,0,0));
                    if(foodtime.daysTo(nowtime)<speriod.toInt())
                    {
                        myfood[fi].setFood(sname, squan.toInt(), sdate, speriod.toInt(), sprice.toDouble());
                        myfood[fi++].show();
                    }
                }
                if(scate=="DailyGoods")
                {
                    buffer = in.readLine();
                    sname=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    squan=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sdate=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sprice=buffer.section(' ',1,1);

                    mydailygoods[di].setDailyGoods(sname, squan.toInt(), sdate, sprice.toDouble());
                    mydailygoods[di++].show();
                }

                if(scate=="ElectricalAppliance")
                {
                    buffer = in.readLine();
                    sname=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    squan=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sdate=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    scolor=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    speriod=buffer.section(' ',1,1);
                    buffer = in.readLine();
                    sprice=buffer.section(' ',1,1);

                    myelectricalappliance[ei].setElectricalAppliance(sname, squan.toInt(), sdate, scolor, speriod.toInt(),sprice.toDouble());
                    myelectricalappliance[ei++].show();
                }
            }

        }
        file.close();
    }
    return cin;
}

void MainWindow::on_pushButton_10_clicked()
{
    QString text;
    for(int i=0;i<N;i++)
    {

        if(myfood[i].getname()==now)
        {
            text=myfood[i].getdetails();
        }
        else
            qDebug()<<myfood[i].getname()<<now;
    }
    for(int i=0;i<N;i++)
    {

        if(mydailygoods[i].getname()==now)
        {
            text=mydailygoods[i].getdetails();
        }
        else
            qDebug()<<mydailygoods[i].getname()<<now;
    }
    for(int i=0;i<N;i++)
    {

        if(myelectricalappliance[i].getname()==now)
        {
            text=myelectricalappliance[i].getdetails();
        }
        else
            qDebug()<<myelectricalappliance[i].getname()<<now;
    }
    Form *test = new Form;
    test->show();
    connect(this,&MainWindow::sendSub,test,&Form::recMain);
    emit sendSub(text);
}

void MainWindow::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    Q_UNUSED(previousRow);
    Q_UNUSED(previousColumn);
    QTableWidgetItem* item=ui->tableWidget->item(currentRow,currentColumn);
    if  (item==NULL)
        return;
    int colomn=0;
    item=ui->tableWidget->item(currentRow,colomn);
    now=item->text();
    qDebug()<<now;
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setFont(QFont("song", 12));
    ui->textEdit_2->setFont(QFont("song",18));
    ui->textEdit_2->setText("+0.0");

    fi=0,ei=0,di=0,pi=1,ri=0,RowCont=0,earnings=0;

    path = QFileDialog::getSaveFileName(this,"选择market_in.txt/maret_out.txt","./market_in.txt");
    cin>>mymarket;

    for(int i=0;i<fi;i++)
    {
        RowCont = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);
        ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myfood[i].getname()));
        ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myfood[i].getquan()));
        ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myfood[i].getdate()));
        ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myfood[i].getprice()));
    }
    for(int i=0;i<di;i++)
    {
        RowCont = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);
        ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(mydailygoods[i].getname()));
        ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(mydailygoods[i].getquan()));
        ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(mydailygoods[i].getdate()));
        ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(mydailygoods[i].getprice()));
    }
    for(int i=0;i<ei;i++)
    {
        RowCont = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);
        ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myelectricalappliance[i].getname()));
        ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myelectricalappliance[i].getquan()));
        ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myelectricalappliance[i].getdate()));
        ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myelectricalappliance[i].getprice()));
    }

}


void MainWindow::on_pushButton_5_clicked()
{
    Add *addgoods = new Add;
    addgoods->show();
    connect(addgoods,&Add::sendfood,this,&MainWindow::recfood);
    connect(addgoods,&Add::senddailygood,this,&MainWindow::recdailygoods);
    connect(addgoods,&Add::sendelectricalappliance,this,&MainWindow::recelectricalappliance);
}

void MainWindow::recfood(Food &r)
{
    QDateTime nowtime = QDateTime::currentDateTime();
    int y=r.getdate().section("/",0,0).toInt();
    int m=r.getdate().section("/",1,1).toInt();
    int d=r.getdate().section("/",2,2).toInt();
    QDateTime foodtime(QDate(y,m,d), QTime(0,0,0));
    if(foodtime.daysTo(nowtime)<r.getperiod())
    {
        myfood[fi].setFood(r);
        myfood[fi].show();
        RowCont = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(RowCont);
        ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myfood[fi].getname()));
        ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myfood[fi].getquan()));
        ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myfood[fi].getdate()));
        ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myfood[fi++].getprice()));
    }
    else
    {
        QMessageBox abox;
        abox.setWindowTitle("提示窗口");
        abox.setText("过期啦！！！");
        abox.exec();
    }
}

void MainWindow::recdailygoods(DailyGoods &r)
{
    mydailygoods[di].setDailyGoods(r);
    mydailygoods[di].show();

    RowCont = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(RowCont);
    ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(mydailygoods[di].getname()));
    ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(mydailygoods[di].getquan()));
    ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(mydailygoods[di].getdate()));
    ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(mydailygoods[di++].getprice()));
}

void MainWindow::recelectricalappliance(ElectricalAppliance &r)
{
    myelectricalappliance[ei].setElectricalAppliance(r);
    myelectricalappliance[ei].show();

    RowCont = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(RowCont);
    ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myelectricalappliance[ei].getname()));
    ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myelectricalappliance[ei].getquan()));
    ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myelectricalappliance[ei].getdate()));
    ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myelectricalappliance[ei++].getprice()));
}


void MainWindow::on_pushButton_6_clicked()
{
    bool ok1=false,ok2=false,ok3=false;

    QString cate =QInputDialog::getText(this,"删除商品","删除种类(food,dailygood,electricalappliance)",QLineEdit::Normal,"",&ok1);
    QString name =QInputDialog::getText(this,"删除商品","删除品名",QLineEdit::Normal,"",&ok2);
    int cnt = QInputDialog::getInt(this, "删除商品","删除数量", QLineEdit::Normal,1,100,1,&ok3);

    if(ok1==true && ok2==true && ok3==true)
    {
        QMessageBox msgBox;
        QString str;
        msgBox.setWindowTitle("删除提示窗口");
        msgBox.setText("删除失败！！！");

        if(cate=="food")
        {
            for(int i=0;i<fi;i++)
            {
                if(myfood[i].getname()==name)
                {
                    if(myfood[i].mydelete(cnt))
                    {
                        for(int in = 0; in < ui->tableWidget->rowCount(); in++){
                            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                                str = ui->tableWidget->item(in, j)->text();
                                if(str==name)
                                {
                                    if(myfood[i].getquan().toInt()==0)
                                        ui->tableWidget->removeRow(in);
                                    else
                                    {
                                        QTableWidgetItem *item = new QTableWidgetItem(myfood[i].getquan());
                                        item->setFont(QFont("strong",12));
                                        ui->tableWidget->setItem(in,1,item);
                                    }
                                }
                            }
                        }
                        msgBox.setText("成功删除");

                    }
                    break;
                }
            }
        }

        if(cate=="dailygood")
        {
            for(int i=0;i<di;i++)
            {
                if(mydailygoods[i].getname()==name)
                {
                    if(mydailygoods[i].mydelete(cnt))
                    {
                        for(int in = 0; in < ui->tableWidget->rowCount(); in++){
                            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                                str = ui->tableWidget->item(in, j)->text();
                                qDebug()<<mydailygoods[i].getquan()<<cnt;
                                if(str==name)
                                {
                                    if(mydailygoods[i].getquan().toInt()==0)
                                        ui->tableWidget->removeRow(in);
                                    else
                                    {
                                        QTableWidgetItem *item = new QTableWidgetItem(mydailygoods[i].getquan());
                                        item->setFont(QFont("strong",12));
                                        ui->tableWidget->setItem(in,1,item);
                                    }
                                }
                            }
                        }
                        msgBox.setText("成功删除");
                    }
                    break;
                }
            }
        }

        if(cate=="electricalappliance")
        {
            for(int i=0;i<ei;i++)
            {
                if(myelectricalappliance[i].getname()==name)
                {
                    if(myelectricalappliance[i].mydelete(cnt))
                    {
                        for(int in = 0; in < ui->tableWidget->rowCount(); in++){
                            for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                                str = ui->tableWidget->item(in, j)->text();
                                if(str==name)
                                {
                                    if(myelectricalappliance[i].getquan().toInt()==0)
                                        ui->tableWidget->removeRow(in);
                                    else
                                    {
                                        QTableWidgetItem *item = new QTableWidgetItem(myelectricalappliance[i].getquan());
                                        item->setFont(QFont("strong",12));
                                        ui->tableWidget->setItem(in,1,item);
                                    }
                                }
                            }
                        }
                        msgBox.setText("成功删除");
                    }
                    break;
                }
            }
        }

        msgBox.exec();
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    bool ok1,ok2,ok3;
    QString scate = QInputDialog::getText(this, tr("购买商品"),tr("请输入种类（food,dailygood,electricalappliance）："), QLineEdit::Normal,tr("food"), &ok1);
    QString sname = QInputDialog::getText(this, tr("购买商品"),tr("请输入品名："), QLineEdit::Normal,tr("apple"), &ok2);
    int quan = QInputDialog::getInt(this, tr("购买商品"),tr("请输入数量："), QLineEdit::Normal,1,1000,1, &ok3);

    QMessageBox msgBox;

    msgBox.setWindowTitle("购买提示窗口");
    msgBox.setText("购买失败！！！");

    bool ok=false;
    bool all=false;

    int number;

    if(ok1 && ok2 && ok3)
    {

        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy.MM.dd hh:mm");

        if(scate=="food")
        {
            for(int i=0;i<N;i++)
            {

                if(myfood[i].getname()==sname)
                {
                    earnings+=quan*myfood[i];
                    int temp=myfood[i].getquan().toInt();
                    if(temp>=quan && quan>0)
                    {
                        mypurchaseorder[pi].setPurchaseorder(current_date,scate,sname,quan,i,pi,myfood[i].getprice().toDouble());
                        ok=true;
                        if(quan==temp) all=true;
                        myfood[i].setquan(temp-quan);
                        number=temp-quan;
                    }
                }
            }
        }
        if(scate=="dailygood")
        {
            for(int i=0;i<N;i++)
            {

                if(mydailygoods[i].getname()==sname)
                {
                    qDebug()<<mydailygoods[i].getprice();
                    earnings+=quan*mydailygoods[i];
                    qDebug()<<"!!!!"<<earnings;
                    int temp=mydailygoods[i].getquan().toInt();
                    if(temp>=quan && quan>0)
                    {
                        mypurchaseorder[pi].setPurchaseorder(current_date,scate,sname,quan,i,pi,mydailygoods[i].getprice().toDouble());
                        ok=true;
                        if(quan==temp) all=true;
                        mydailygoods[i].setquan(temp-quan);
                        number=temp-quan;
                    }
                }
            }
        }
        if(scate=="electricalappliance")
        {
            for(int i=0;i<N;i++)
            {

                if(myelectricalappliance[i].getname()==sname)
                {
                    earnings+=quan*myelectricalappliance[i];
                    int temp=myelectricalappliance[i].getquan().toInt();
                    if(temp>=quan && quan>0)
                    {
                        mypurchaseorder[pi].setPurchaseorder(current_date,scate,sname,quan,i,pi,myelectricalappliance[i].getprice().toDouble());
                        ok=true;
                        if(quan==temp) all=true;
                        myelectricalappliance[i].setquan(temp-quan);
                        number=temp-quan;
                    }
                }
            }
        }

        if(ok)
        {
            cout<<mypurchaseorder[pi];

            msgBox.setText("购买成功");
            mymarket.setearnings(earnings);
            for(int i = 0; i < ui->tableWidget->rowCount(); i++){
                    QString str = ui->tableWidget->item(i, 0)->text();

                    if(str==sname)
                    {
                        if(all)
                            ui->tableWidget->removeRow(i);
                        else
                        {
                            QTableWidgetItem *item = new QTableWidgetItem(QString::number(number));
                            item->setFont(QFont("strong",12));
                            ui->tableWidget->setItem(i,1,item);
                        }
                    }
            }
            pi++;
        }

        msgBox.exec();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    QMessageBox myBox;

    myBox.setWindowTitle("退货提示窗口");
    myBox.setText("退货失败！！！");

    bool ok1,ok2;
    int id = QInputDialog::getInt(this, tr("退货"),tr("请输入订单号"), QLineEdit::Normal,1,200,1,&ok1);
    if(ok1) qDebug() << "string:" << id;
    QString reason = QInputDialog::getText(this, tr("退货"),tr("请输入原因"), QLineEdit::Normal,tr("apple is not sweet"), &ok2);
    if(ok2) qDebug() << "string:" << reason;
    if(ok1 && ok2)
    {
        if(mypurchaseorder[id].geti()!=-1)
        {
            myreturnchaseorder[ri].setreturnchaseorder(mypurchaseorder[id],reason);
            myBox.setText("退货成功");
            cout<<myreturnchaseorder[ri];
            int p=myreturnchaseorder[ri].geti();
            int q=myreturnchaseorder[ri].getquantity();
            if(myreturnchaseorder[ri].getcategory()=="food")
            {
                earnings-=q*myfood[p];
                int t=myfood[p].getquan().toInt();
                qDebug()<<t;
                myfood[p].setquan(t+q);
                if(t==0)
                {
                    RowCont = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(RowCont);
                    ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myfood[p].getname()));
                    ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myfood[p].getquan()));
                    ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myfood[p].getdate()));
                    ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myfood[p].getprice()));
                }
                else
                {
                    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
                        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                            QString str = ui->tableWidget->item(i,j)->text();
                            if(str==myfood[p].getname())
                            {
                                    QTableWidgetItem *item = new QTableWidgetItem(QString::number(t+q));
                                    item->setFont(QFont("strong",12));
                                    ui->tableWidget->setItem(i,1,item);
                            }
                        }
                    }
                }
            }
            if(myreturnchaseorder[ri].getcategory()=="dailygood")
            {
                earnings-=q*mydailygoods[p];
                qDebug()<<earnings;
                int t=mydailygoods[p].getquan().toInt();
                mydailygoods[p].setquan(t+q);
                if(t==0)
                {
                    RowCont = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(RowCont);
                    ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(mydailygoods[p].getname()));
                    ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(mydailygoods[p].getquan()));
                    ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(mydailygoods[p].getdate()));
                    ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(mydailygoods[p].getprice()));
                }
                else
                {
                    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
                        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                            QString str = ui->tableWidget->item(i, j)->text();
                            if(str==mydailygoods[p].getname())
                            {
                                QTableWidgetItem *item = new QTableWidgetItem(QString::number(t+q));
                                item->setFont(QFont("strong",12));
                                ui->tableWidget->setItem(i,1,item);
                            }
                        }
                    }
                }
                mydailygoods[p].show();
            }
            if(myreturnchaseorder[ri].getcategory()=="electricalappliance")
            {
                earnings-=q*myelectricalappliance[p];
                qDebug()<<earnings;
                int t=myelectricalappliance[p].getquan().toInt();
                myelectricalappliance[p].setquan(t+q);
                if(t==0)
                {
                    RowCont = ui->tableWidget->rowCount();
                    ui->tableWidget->insertRow(RowCont);
                    ui->tableWidget->setItem(RowCont, 0, new QTableWidgetItem(myelectricalappliance[p].getname()));
                    ui->tableWidget->setItem(RowCont, 1, new QTableWidgetItem(myelectricalappliance[p].getquan()));
                    ui->tableWidget->setItem(RowCont, 2, new QTableWidgetItem(myelectricalappliance[p].getdate()));
                    ui->tableWidget->setItem(RowCont, 3, new QTableWidgetItem(myelectricalappliance[p].getprice()));
                }
                else
                {
                    for(int i = 0; i < ui->tableWidget->rowCount(); i++){
                        for(int j = 0; j < ui->tableWidget->columnCount(); j++){
                            QString str = ui->tableWidget->item(i, j)->text();
                            if(str==myelectricalappliance[p].getname())
                            {
                                QTableWidgetItem *item = new QTableWidgetItem(QString::number(t+q));
                                item->setFont(QFont("strong",12));
                                ui->tableWidget->setItem(i,1,item);
                            }
                        }
                    }
                }
            }
            mymarket.setearnings(earnings);
            ri++;
            mypurchaseorder[id].seti(-1);
        }
    }

    myBox.exec();

}


void MainWindow::on_pushButton_7_clicked()
{
    ui->textEdit_2->setText("+"+QString::number(earnings));
}


void MainWindow::on_pushButton_9_clicked()
{
    QMessageBox thebox;
    thebox.setWindowTitle("保存成功");
    thebox.setText("保存文件market_out.txt");

    cout<<mymarket;

    thebox.exec();
}

