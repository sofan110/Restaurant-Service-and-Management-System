#include "logindialog.h"
#include "ui_logindialog.h"
#include "QDebug"


LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowTitle("登录");
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_LoginBtn_clicked()
{
    QString namestring;
    QString pwdstring;


    namestring = ui->userName->text();
    namestring = namestring.trimmed();
    pwdstring = ui->mimaEdit->text();
    name = namestring;
    if(namestring.isEmpty())
    {
        QMessageBox::information(this,tr("请输入用户名"),tr("请输入用户名"),QMessageBox::Ok);
        ui->mimaEdit->clear();
        ui->userName->setFocus();
    }
    else if(pwdstring.isEmpty())
            {
                QMessageBox::information(this,tr("请输入密码"),tr("请输入密码"),QMessageBox::Ok);
                ui->mimaEdit->clear();
                ui->userName->setFocus();
            }
        else
         {
            switch(this->ReturnType())
                {
                    case 1:if(Restaurant::Instance()->FindCustomerName(namestring) == true)
                            {
                                if(Restaurant::Instance()->FindCustomerPwd(pwdstring) == true)
                                    {
                                        ui->mimaEdit->clear();
                                        ui->userName->clear();
                                        Restaurant::Instance()->desk.getCustomer(namestring,pwdstring);//应该读入所有信息

                                        QDialog::accept();
                                    }
                                else
                                    {
                                    QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                     ui->mimaEdit->clear();
                                     ui->mimaEdit->setFocus();
                                     }
                            }
                            else
                            {
                                QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                ui->mimaEdit->clear();
                                ui->userName->setFocus();
                            }
                            break;
                    
                    case 2:  if(Restaurant::Instance()->FindAdminName(namestring) == true)
                                       {
                                             if(Restaurant::Instance()->FindAdminPwd(pwdstring) == true)
                                                  {
                                                      ui->mimaEdit->clear();
                                                      ui->userName->clear();
                                                      QDialog::accept();
                                                   }
                                              else
                                                  {
                                                    QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                                    ui->mimaEdit->clear();
                                                    ui->mimaEdit->setFocus();
                                                   }
                                        }
                             else
                               {
                                  QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                  ui->mimaEdit->clear();
                                  ui->userName->setFocus();
                              }
                             break;
                    case 3: if(Restaurant::Instance()->FindWaiterName(namestring) == true)
                                {
                                    if(Restaurant::Instance()->FindWaiterPwd(pwdstring) == true)
                                        {
                                            ui->mimaEdit->clear();
                                            ui->userName->clear();
                                            QDialog::accept();
                                        }
                                    else
                                        {
                                            QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                            ui->mimaEdit->clear();
                                            ui->mimaEdit->setFocus();
                                        }
                                }
                        else
                            {
                                QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                ui->mimaEdit->clear();
                                ui->userName->setFocus();
                            }
                            break;
                    case 4:if(Restaurant::Instance()->FindCookName(namestring) == true)
                                {
                                    if(Restaurant::Instance()->FindCookPwd(pwdstring) == true)
                                         {
                                            ui->mimaEdit->clear();
                                            ui->userName->clear();
                                            name = namestring;
                                            QDialog::accept();
                                        }
                                    else
                                        {
                                            QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                            ui->mimaEdit->clear();
                                            ui->mimaEdit->setFocus();
                                        }
                                 }
                           else
                                {
                                    QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                    ui->mimaEdit->clear();
                                    ui->userName->setFocus();
                                }
                             break;
                    case 5:if(Restaurant::Instance()->FindManagerName(namestring) == true)
                            {
                                if(Restaurant::Instance()->FindManagerPwd(pwdstring) == true)
                                {
                                    ui->mimaEdit->clear();
                                    ui->userName->clear();
                                    QDialog::accept();
                                }
                                else
                                    {
                                        QMessageBox::warning(this,tr("密码错误"),tr("请输入正确的密码再登录！"),QMessageBox::Ok);
                                        ui->mimaEdit->clear();
                                        ui->mimaEdit->setFocus();
                                    }
                            }
                            else
                                {
                                    QMessageBox::warning(this,tr("用户名不存在"),tr("请输入正确的用户名再登录！"),QMessageBox::Ok);
                                    ui->mimaEdit->clear();
                                    ui->userName->setFocus();
                                }
                            break;
                }
           }
}
