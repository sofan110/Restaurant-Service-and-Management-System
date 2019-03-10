#include "comment.h"
#include "ui_comment.h"

comment::comment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::comment)
{
    ui->setupUi(this);
    setWindowTitle("用户评价界面");
}

comment::~comment()
{
    delete ui;
}

void comment::on_pushButton_clicked()
{
    QHash<int,Desk>::iterator i;

    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
    {
      if(i.value().returnDeskNum() == Restaurant::Instance()->desk.returnDeskNum())
        {
          QHash<int,Cook>::iterator it;

          for(it=Restaurant::Instance()->CookHash.begin();it!=Restaurant::Instance()->CookHash.end();++it)
          {
            if(i.value().returnCookName() == it.value().ReturnCookName())
              {
                qDebug()<<ui->comboBox_2->currentText().toInt()<<"cao";
                int n = ui->comboBox_2->currentText().toInt();
                it.value().getMark(n);
              }
          }
           i.value().ChangeDeskState("空闲");
           i.value().inputCookName(NULL);
        }
    }

    QHash<int,Waiter>::iterator mi;

    for(mi=Restaurant::Instance()->WaiterHash.begin();mi!=Restaurant::Instance()->WaiterHash.end();++mi)
    {
      if(mi.value().findDeskNum(Restaurant::Instance()->desk.returnDeskNum()))
        {
          mi.value().getMark(ui->comboBox->currentText().toInt());
          mi.value().clearDeskNum(Restaurant::Instance()->desk.returnDeskNum());
        }
    }

    QHash<int,Customer>::iterator cu;

    for(cu=Restaurant::Instance()->CustomerHash.begin();cu!=Restaurant::Instance()->CustomerHash.end();++cu)
    {
      if(cu.value().returnCustomName() == Restaurant::Instance()->desk.returnCustmer().returnCustomName())
        {
          cu.value().returnProcess() = 0;
        }
    }


    this->close();
}
