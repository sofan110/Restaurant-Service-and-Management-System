#ifndef MANAGERCUSTOMER_H
#define MANAGERCUSTOMER_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class ManagerCustomer;
}

class ManagerCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerCustomer(QWidget *parent = 0);
    ~ManagerCustomer();

    void showCustomer();
private slots:
    void on_pushButton_clicked();

    void OnBtnClicked();

     void closeEvent(QCloseEvent *event);
private:
    Ui::ManagerCustomer *ui;

};

#endif // MANAGERCUSTOMER_H
