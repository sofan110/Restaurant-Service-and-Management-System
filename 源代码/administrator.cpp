#include "administrator.h"
#include "ui_administrator.h"

Administrator::Administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
    setWindowTitle("系统管理员界面");
}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::on_pushButton_clicked()//转到顾客管理窗口
{
    MC.showCustomer();
    MC.show();
}

void Administrator::on_pushButton_2_clicked()//转到菜单管理窗口
{
    MD.showDishMap();
    MD.show();
}

void Administrator::on_pushButton_3_clicked()//转到服务员管理界面
{
    MW.showWiter();
    MW.show();
}

void Administrator::on_pushButton_4_clicked()//转到厨师管理界面
{
    MCO.showCook();
    MCO.show();
}
