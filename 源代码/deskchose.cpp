#include "deskchose.h"
#include "ui_deskchose.h"

DeskChose::DeskChose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeskChose)
{
    ui->setupUi(this);
    setWindowTitle("选桌界面");
    ui->sureBtn->setDisabled(true);
    ui->Btn1->setDisabled(true);

    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中")
        {
            setUnable(i.value().returnDeskNum());
        }
    }
}

DeskChose::~DeskChose()
{
    delete ui;
}

void DeskChose::setUnable(int n)
{
    switch(n)
    {
        case 1:ui->deskBtn1->setDisabled(true);
                break;
        case 2:ui->deskBtn2->setDisabled(true);
                break;
        case 3:ui->deskBtn3->setDisabled(true);
                break;
        case 4:ui->deskBtn4->setDisabled(true);
                break;

    }

}

void DeskChose::setAble(int &n)
{
    switch(n)
    {
        case 1:ui->deskBtn1->setEnabled(true);
                break;
        case 2:ui->deskBtn2->setEnabled(true);
                break;
        case 3:ui->deskBtn3->setEnabled(true);
                break;
        case 4:ui->deskBtn4->setEnabled(true);
                break;
    }

}

bool DeskChose::IsDeskUsed(int &n)
{
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskState() == "用餐中"&&i.value().returnDeskNum() == n)
        {
            return true;
        }
    }

    return false;
}

void DeskChose::on_deskBtn1_clicked()//选桌操作，可以考虑写成函数//考虑更多
{
    Restaurant::Instance()->desk.changeDeskNumber(1);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(1);

    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sureBtn->setEnabled(true);
    ui->deskBtn1->setDisabled(true);
    ui->sureBtn->setFocus();
}

void DeskChose::on_deskBtn2_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(2);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(2);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sureBtn->setEnabled(true);
    ui->deskBtn2->setDisabled(true);
    ui->sureBtn->setFocus();
}

void DeskChose::on_deskBtn3_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(3);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(3);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sureBtn->setEnabled(true);
    ui->deskBtn3->setDisabled(true);
    ui->sureBtn->setFocus();
}

void DeskChose::on_deskBtn4_clicked()
{
    Restaurant::Instance()->desk.changeDeskNumber(4);
    Restaurant::Instance()->desk.returnCustmer().ChangeTable(4);


    for(int i =1;i < 5;i ++)
    {
        if(IsDeskUsed(i))
        {
            setUnable(i);
        }
        else
            setAble(i);
    }
    ui->sureBtn->setEnabled(true);
    ui->deskBtn4->setDisabled(true);
    ui->sureBtn->setFocus();
}

void DeskChose::on_sureBtn_clicked()
{
    Restaurant::Instance()->ChangeDeskState(Restaurant::Instance()->desk.returnDeskNum());
    Restaurant::Instance()->ChangeDeskUser(Restaurant::Instance()->desk.returnCustmer().returnCustomName(),Restaurant::Instance()->desk.returnDeskNum());
    Restaurant::Instance()->ChangeCustomerProcess(Restaurant::Instance()->desk.returnCustmer().returnCustomName());
    this->close();
    order.showDisH();
    order.show();
}

void DeskChose::on_exitBtn_clicked()
{
    this->close();
}
