#include "watingfor.h"
#include "ui_watingfor.h"
#include <QDebug>
#include <QMessageBox>

WatingFor::WatingFor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WatingFor)
{
    ui->setupUi(this);
    setWindowTitle("等待界面");
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("菜名")<<tr("价格")<<tr("状态");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑  
}

WatingFor::~WatingFor()
{
    delete ui;
}

void WatingFor::showDish()
{
    int row_count = ui->tableWidget->rowCount();

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
        {
            QHash<int,OneDish>::iterator it;

            for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
            {
                ui->tableWidget->insertRow(row_count);
                ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(it.value().putDishName()));
                ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(it.value().putDishPrice()));
                ui->tableWidget->setItem(row_count,2,new QTableWidgetItem(it.value().putDishState()));
                ui->tableWidget->item(row_count,0)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->item(row_count,1)->setTextAlignment(Qt::AlignCenter);
                ui->tableWidget->item(row_count,2)->setTextAlignment(Qt::AlignCenter);

                if(it.value().putDishState() != "已做完")
                    {
                        ui->pushButton->setDisabled(true);
                    }
            }
        }
    }


}

void WatingFor::on_pushButton_clicked()
{
    p.show();
    p.showDish();
    if(p.exec() == QDialog::Accepted)
    {
        this->close();
        com.show();
    }
}

void WatingFor::on_pushButton_2_clicked()
{
   int row = ui->tableWidget->rowCount();

   for(int i =0 ;i<row;i++)
   {
       ui->tableWidget->removeRow(0);
   }
   showDish();
}

void WatingFor::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

}

void WatingFor::on_pushButton_4_clicked()
{
    if(ui->tableWidget->isItemSelected(ui->tableWidget->currentItem()))//判断是否选择了表格的一行
    {
        int n = ui->tableWidget->currentRow();
        QHash<int,Desk>::iterator i;

        for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
        {
            if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
            {
                QHash<int,OneDish>::iterator it;

                for(it=i.value().returnDish().getDishmap().begin();it!=i.value().returnDish().getDishmap().end();++it)
                {
                   if(it.value().putDishName() == ui->tableWidget->item(n,0)->text() && it.value().putDishState() == ui->tableWidget->item(n,2)->text())
                   {
                       it.value().changeUrgeOrder();
                       break;
                   }
                }
            }
        }
        QMessageBox::information(NULL,"提示","已为您催菜！",QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this,tr("提示"),tr("请选择一道菜！"),QMessageBox::Ok);
    }
}

void WatingFor::on_pushButton_3_clicked()
{
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
        if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
        {
            i.value().getRequest("加水");
        }
    }
    QMessageBox::information(NULL,"提示","已通知服务员为您加水！",QMessageBox::Yes);
}
