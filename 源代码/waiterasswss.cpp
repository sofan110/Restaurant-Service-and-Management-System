#include "waiterasswss.h"
#include "ui_waiterasswss.h"

WaiterAsswss::WaiterAsswss(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaiterAsswss)
{
    ui->setupUi(this);
    setWindowTitle("服务员报表");
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("服务员")<<tr("服务餐桌数")<<tr("平均评价");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

WaiterAsswss::~WaiterAsswss()
{
    delete ui;
}

void WaiterAsswss::showIt(const QString &name)
{
    ui->label->setText("服务员：" + name);

    QHash<int,Waiter>::iterator i;

    for(i=Restaurant::Instance()->WaiterHash.begin();i!=Restaurant::Instance()->WaiterHash.end();++i)
    {
        if(i.value().ReturnWaiterName() == name)
        {

            float ave = 0;
            int n =0;
            QHash<int,int>::iterator it;

            for(it = i.value().returnWAiterMark().begin();it!=i.value().returnWAiterMark().end();++it)
             {
                ave += it.value();
                n++;
            }
            ave = ave/n;
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(i.value().ReturnWaiterName()));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(n)));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(ave)));

        }
    }
}

void WaiterAsswss::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

}
