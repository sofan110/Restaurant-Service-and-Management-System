#include "serve.h"
#include "ui_serve.h"

Serve::Serve(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Serve)
{
    ui->setupUi(this);
    setWindowTitle("服务界面");
    ui->tableWidget->setColumnCount(3);

    QStringList header;

    header<<tr("菜名")<<tr("状态")<<tr("是否催菜");//不一定要催菜
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    ui->tableWidget->horizontalHeader()->resizeSection(2,50);

    ui->tableWidget_2->setColumnCount(1);

    QStringList head;

    head<<tr("用户需求");
    ui->tableWidget_2->setHorizontalHeaderLabels(head);
    ui->tableWidget_2-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

Serve::~Serve()
{
    delete ui;
}

void Serve::showDish(int n)
{
    int row = ui->tableWidget->rowCount();
    int row2 = ui->tableWidget_2->rowCount();
    ui->tableNum->setText("服务桌号：" + QString::number(n));

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == n)
        {
            QHash<int,OneDish>::iterator it;

            for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
            {
                        ui->tableWidget->insertRow(row);
                        ui->tableWidget->setItem(row,0,new QTableWidgetItem(it.value().putDishName()));
                        ui->tableWidget->setItem(row,1,new QTableWidgetItem(it.value().putDishState()));
                        ui->tableWidget->setItem(row,2,new QTableWidgetItem(it.value().putUrgeOrder()));
                        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
                        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
                        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
                        row++;
            }

            if(i.value().returnRequest() != NULL)
            {
                ui->tableWidget_2->insertRow(row2);
                ui->tableWidget_2->setItem(row2,0,new QTableWidgetItem(i.value().returnRequest()));
                ui->tableWidget_2->item(row2,0)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}


void Serve::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

    int row2 = ui->tableWidget_2->rowCount();

    for(int i=0;i<row2;i++)
    {
        ui->tableWidget_2->removeRow(0);
    }
}
