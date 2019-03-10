#include "mangercook.h"
#include "ui_mangercook.h"
#include <QMessageBox>

MangerCook::MangerCook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MangerCook)
{
    ui->setupUi(this);
    setWindowTitle("厨师管理界面");
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("厨师")<<tr("密码")<<tr(" ");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
}

MangerCook::~MangerCook()
{
    delete ui;
}

void MangerCook::showCook()
{
    int rowcount = 0;
    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除");

        ui->tableWidget->insertRow(rowcount);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(i.value().ReturnCookName()));
        ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(i.value().ReturnCookPwd()));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(rowcount,2,pBtn);
        rowcount ++;
    }

}

void MangerCook::OnBtnClicked()
{
    QPushButton * senderObj = qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));

    int row=index.row();

    QHash<int,Cook>::iterator i;

    for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
    {
        if(i.value().ReturnCookName() == ui->tableWidget->item(row,0)->text())
        {
            Restaurant::Instance()->CookHash.erase(i);
        }
    }

    ui->tableWidget->removeRow(row);

}

void MangerCook::on_pushButton_clicked()
{
    if(NC.exec() == QDialog::Accepted)
    {
        int row_count = ui->tableWidget->rowCount();

        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除");

        ui->tableWidget->insertRow(row_count);
        ui->tableWidget->setItem(row_count,0,new QTableWidgetItem(NC.name));
        ui->tableWidget->setItem(row_count,1,new QTableWidgetItem(NC.pwd));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(row_count,2,pBtn);
    }
}

void MangerCook::on_pushButton_2_clicked()
{
        QMessageBox::information(NULL,"提示","修改成功",QMessageBox::Yes);
}

void MangerCook::closeEvent(QCloseEvent *event)
{
    int row = ui->tableWidget->rowCount();

    for(int i=0;i<row;i++)
    {
        ui->tableWidget->removeRow(0);
    }

}
