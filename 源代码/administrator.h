#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>
#include "managercustomer.h"
#include "managerdish.h"
#include "managerwaiter.h"
#include "mangercook.h"

namespace Ui {
class Administrator;
}

class Administrator : public QDialog
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = 0);
    ~Administrator();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Administrator *ui;
    ManagerCustomer MC;//顾客管理窗口
    ManagerDish MD;//菜单管理窗口
    ManagerWaiter MW;//服务员管理窗口
    MangerCook MCO;//厨师管理窗口
};

#endif // ADMINISTRATOR_H
