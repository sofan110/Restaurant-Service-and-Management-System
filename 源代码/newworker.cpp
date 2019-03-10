#include "newworker.h"
#include "ui_newworker.h"
#include  <QMessageBox>

NewWorker::NewWorker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewWorker)
{
    ui->setupUi(this);
    setWindowTitle("服务员注册");
}

NewWorker::~NewWorker()
{
    delete ui;
}

void NewWorker::on_pushButton_clicked()
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
    else if(Restaurant::Instance()->FindWaiterName(userName) == true)//判断用户名是否已经存在
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
                         Restaurant::Instance()->getWaiterHash(userName,passWord);

                         QDialog::accept();
                        this->close();

                     }

}
