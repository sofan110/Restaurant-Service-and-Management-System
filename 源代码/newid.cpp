#include "newid.h"
#include "ui_newid.h"

NewId::NewId(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewId)
{
    ui->setupUi(this);
    setWindowTitle("注册");
}

NewId::~NewId()
{
    delete ui;
}

void NewId::on_registerBtn_clicked()
{
    QString userName;
    QString passWord;
    QString passWordSure;

    //读入用户名及密码
    userName = ui->userNameEdit->text();
    passWord = ui->pwdEdit->text();
    passWordSure = ui->sureEdit->text();
    if(userName.isEmpty())//判断用户名是否为空
    {
        QMessageBox::warning(this,tr("请输入用户名"),tr("请输入用户名！"),QMessageBox::Ok);//弹出提示信息
        ui->pwdEdit->clear();
        ui->sureEdit->clear();
        ui->userNameEdit->setFocus();
    }
    else if(Restaurant::Instance()->FindCustomerName(userName) == true)//判断用户名是否已经存在
            {
                QMessageBox::warning(this,tr("请输入用户名"),tr("用户名已存在！"),QMessageBox::Ok);//弹出提示信息
                ui->pwdEdit->clear();
                ui->sureEdit->clear();
                ui->userNameEdit->setFocus();
            }
         else if(passWord.isEmpty()||passWordSure.isEmpty())
                {
                    QMessageBox::warning(this,tr("请输入密码"),tr("请输入密码！"),QMessageBox::Ok);//弹出提示信息
                    ui->pwdEdit->clear();
                    ui->sureEdit->clear();
                    ui->pwdEdit->setFocus();
                }


                else if(passWord != passWordSure)
                        {
                            QMessageBox::warning(this,tr("密码错误"),tr("请检查两次输入的密码是否一致！"),QMessageBox::Ok);
                            ui->pwdEdit->clear();
                            ui->sureEdit->clear();
                            ui->pwdEdit->setFocus();
                        }
                        else
                            {
                                 ui->userNameEdit->clear();
                                 ui->pwdEdit->clear();
                                 ui->sureEdit->clear();
                                 ui->userNameEdit->setFocus();
                                 Restaurant::Instance()->desk.getCustomer(userName,passWord);
                                 Restaurant::Instance()->getCustomer(userName,passWord);
                                 this->close();
                                 des.show();
                            }

}
