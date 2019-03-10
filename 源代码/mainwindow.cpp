#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "change.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    set_appraeance(this);
    setWindowTitle("登录界面");
   // ui->label_2->setPixmap(QPixmap(":/timg.jpg"));
    //ui->label_2->setScaledContents(true);
    //ui->label_2->setScaledContents(true);

    //QString(QPushButton{color : red; });
    //setStyleSheet("background-color: rgb(0,0,0);color: rgb(255,255,255);");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginBtn_clicked()
{
    dlg.ChangeType(1);
    if(dlg.exec() == QDialog::Accepted)
    {
        dlg.close();
        switch(Restaurant::Instance()->ReturnCustomerProcess(Restaurant::Instance()->desk.returnCustmer().returnCustomName()))
        {
            case 0:
                    dc.show();
                    break;
            case 1:
             {
                    QHash<int,Desk>::iterator i;

                    for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
                        {
                             if(i.value().returnCustmer().returnCustomName() == Restaurant::Instance()->desk.returnCustmer().returnCustomName())
                                 {
                                        Restaurant::Instance()->desk.changeDeskNumber(i.value().returnDeskNum());
                                 }
                        }
                    od.showDisH();
                    od.show();
                    break;
             }
            case 2:
            {
                     QHash<int,Desk>::iterator i;
                     for(i=Restaurant::Instance()->DeskHash.begin();i!=Restaurant::Instance()->DeskHash.end();++i)
                        {
                            if(i.value().returnCustmer().returnCustomName() == Restaurant::Instance()->desk.returnCustmer().returnCustomName())
                                {
                                    Restaurant::Instance()->desk.changeDeskNumber(i.value().returnDeskNum());

                                }
                        }
                    wf.showDish();
                    wf.show();
                    break;
            }
        }

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    rg.show();
}

void MainWindow::on_commandLinkButton_3_clicked()
{
    dlg.ChangeType(2);
    if(dlg.exec() == QDialog::Accepted)
    {
        dlg.close();
        baba.show();
    }
}

void MainWindow::on_commandLinkButton_clicked()
{
    dlg.ChangeType(3);
    if(dlg.exec() == QDialog::Accepted)
    {
        dlg.close();
        wd.showWaiterDesk(dlg.name);
        wd.show();
    }
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    dlg.ChangeType(4);
    if(dlg.exec() == QDialog::Accepted)
    {     
        QHash<int,Cook>::iterator i;

        for(i=Restaurant::Instance()->CookHash.begin();i!=Restaurant::Instance()->CookHash.end();++i)
           {
               if(i.value().ReturnCookName() == dlg.name && (i.value().reutrnDeskNum() != 0))
                   {
                        co.showDish(i.value().reutrnDeskNum());
                        dlg.close();
                        co.show();
                        break;
                   }
               else
                   {
                        cd.showCookDesk(dlg.name);
                        dlg.close();
                        cd.show();
                        break;
                   }
           }

    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton rb = QMessageBox::information(NULL,"提示","是否将数据存入数据库？",QMessageBox::Yes|QMessageBox::No,QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
       {
            qDebug()<<"fuck lu";
            Restaurant::Instance()->InsertCustomer();
            Restaurant::Instance()->InsertDish();
            Restaurant::Instance()->InsertCook();
        }
    else
        {

        }
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    dlg.ChangeType(5);
    if(dlg.exec() == QDialog::Accepted)
    {
        dlg.close();
        md.showIt();
        md.show();
    }
}
