#include "cookassess.h"
#include "ui_cookassess.h"

CookAssess::CookAssess(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CookAssess)
{
    ui->setupUi(this);
    setWindowTitle("厨师报表");
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("厨师")<<tr("服务餐桌数")<<tr("平均评价");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

CookAssess::~CookAssess()
{
    delete ui;

}

void CookAssess::showIt(const QString name)
{
    ui->label->setText("厨师：" + name);

    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        if(i.value().ReturnCookName() == name)
        {

            float ave = 0;
            int n =0;
            QHash<int,int>::iterator it;

            for(it = i.value().returnCookMark().begin();it!=i.value().returnCookMark().end();++it)
             {
                ave += it.value();
                n++;
            }
            if(n != 0)
            {
                ave = ave/n;
            }
            ui->tableWidget->insertRow(0);
            ui->tableWidget->setItem(0,0,new QTableWidgetItem(i.value().ReturnCookName()));
            ui->tableWidget->setItem(0,1,new QTableWidgetItem(QString::number(n)));
            ui->tableWidget->setItem(0,2,new QTableWidgetItem(QString::number(ave)));

        }
    }

}

void CookAssess::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

}
