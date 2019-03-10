#include "newcook.h"
#include "ui_newcook.h"
#include <QMessageBox>

NewCook::NewCook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCook)
{
    ui->setupUi(this);
    setWindowTitle("厨师注册");
}

NewCook::~NewCook()
{
    delete ui;
}

void NewCook::on_pushButton_clicked()
{
    QString userName;
    QString passWord;

    //读入用户名及密码
    userName = (ui->usernameEdit->text()).trimmed();
    passWord = ui->pwdEdit->text();
    name = userName;
    pwd = passWord;
    if(userName.isEmpty())//判断用户名是否为空
    {
        QMessageBox::warning(this,tr("提示"),tr("请输入用户名！"),QMessageBox::Ok);//弹出提示信息
        ui->pwdEdit->clear();
        ui->usernameEdit->setFocus();
    }
    else if(Restaurant::Instance()->FindCookName(userName) == true)//判断用户名是否已经存在
            {
                QMessageBox::warning(this,tr("提示"),tr("用户名已存在！"),QMessageBox::Ok);//弹出提示信息
                ui->pwdEdit->clear();
                ui->usernameEdit->clear();
                ui->usernameEdit->setFocus();
            }
         else if(passWord.isEmpty())
                {
                    QMessageBox::warning(this,tr("提示"),tr("请输入密码！"),QMessageBox::Ok);//弹出提示信息
                    ui->pwdEdit->clear();
                    ui->pwdEdit->setFocus();
                }
                else
                     {
                         ui->usernameEdit->clear();
                         ui->pwdEdit->clear();
                         ui->usernameEdit->setFocus();
                         Restaurant::Instance()->getCookHash(userName,passWord);

                         QDialog::accept();
                        this->close();

                     }

}
