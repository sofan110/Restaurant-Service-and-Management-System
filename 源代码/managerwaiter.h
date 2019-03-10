#ifndef MANAGERWAITER_H
#define MANAGERWAITER_H

#include <QDialog>
#include "restaurant.h"
#include "newworker.h"

namespace Ui {
class ManagerWaiter;
}

class ManagerWaiter : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerWaiter(QWidget *parent = 0);
    ~ManagerWaiter();

    void showWiter();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

   void OnBtnClicked();

    void closeEvent(QCloseEvent *event);
private:
    Ui::ManagerWaiter *ui;
    NewWorker NW;

};

#endif // MANAGERWAITER_H
