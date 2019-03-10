#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "connection.h"
//#include "customer.h"
#include "restaurant.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

    QString name;
    void ChangeType(const int &type)
    {
        this->type = type;
    }

    int ReturnType()
    {
        return this->type;
    }
private slots:
    void on_LoginBtn_clicked();

private:
    Ui::LoginDialog *ui;
    int type;//代表不同的用户：1.顾客。2.餐厅管理员。3，服务员。4.厨师。5.餐厅经理。

};

#endif // LOGINDIALOG_H
