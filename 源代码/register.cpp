#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    setWindowTitle("注册界面");
}

Register::~Register()
{
    delete ui;
}


void Register::on_continueBtn_clicked()
{
    QString phonenum;
    QByteArray ba;
    const char *s;
    int num = 0;

   phonenum = ui->phoneNum->text().trimmed();
   ba = phonenum.toLatin1();
   s = ba.data();
   while(*s && *s>='0' && *s<='9')
   {
       s++;
       num++;
   }
   if(*s)
   {
       QMessageBox::warning(this,tr("手机号错误"),tr("请输入正确的手机号!"),QMessageBox::Ok);
        ui->phoneNum->clear();
        ui->phoneNum->setFocus();
   }
   else if(num != 11)
         {
           QMessageBox::warning(this,tr("手机号错误"),tr("请输入正确的手机号！"),QMessageBox::Ok);
           ui->phoneNum->clear();
           ui->phoneNum->setFocus();
         }
         else
        {
             ui->phoneNum->clear();
             this->hide();
             ni.show();
        }
}
