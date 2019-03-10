#include "mcustomer.h"
#include "ui_mcustomer.h"

MCustomer::MCustomer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MCustomer)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(3);

    QStringList header;
    header<<tr("顾客名")<<tr("密码")<<tr(" ");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget-> horizontalHeader()->setStretchLastSection(true);//设置充满表宽度
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设置只能选取一行
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑

}

MCustomer::~MCustomer()
{
    delete ui;
}

void ManagerCustomer::showCustomer()
{
    int rowcount = 0;
    QHash<int,Customer>::iterator i;

    for(i=Restaurant::Instance()->CustomerHash.begin();i!=Restaurant::Instance()->CustomerHash.end();++i)
    {
        QPushButton * pBtn = new QPushButton();
        pBtn->setText("删除该用户");

        ui->tableWidget->insertRow(rowcount);
        ui->tableWidget->setItem(rowcount,0,new QTableWidgetItem(i.value().returnCustomName()));
        ui->tableWidget->setItem(rowcount,1,new QTableWidgetItem(i.value().returnPwd()));

        connect(pBtn, SIGNAL(clicked()), this, SLOT(OnBtnClicked()));
        ui->tableWidget->setCellWidget(rowcount,2,pBtn);
    }

}

void ManagerCustomer::OnBtnClicked()
{
    QPushButton * senderObj=qobject_cast<QPushButton *>(sender());
    if(senderObj == 0)
    {
        return;
    }
    QModelIndex index =ui->tableWidget->indexAt(QPoint(senderObj->frameGeometry().x(),senderObj->frameGeometry().y()));

    int row=index.row();
    ui->tableWidget->removeRow(row);

}
void ManagerCustomer::on_pushButton_clicked()
{
    this->close();
}
