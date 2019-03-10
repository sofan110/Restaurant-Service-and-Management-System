#ifndef MANGERCOOK_H
#define MANGERCOOK_H

#include <QDialog>
#include "restaurant.h"
#include "newcook.h"

namespace Ui {
class MangerCook;
}

class MangerCook : public QDialog
{
    Q_OBJECT

public:
    explicit MangerCook(QWidget *parent = 0);
    ~MangerCook();

    void showCook();
private slots:
    void on_pushButton_clicked();

    void OnBtnClicked();
    void on_pushButton_2_clicked();

     void closeEvent(QCloseEvent *event);
private:
    Ui::MangerCook *ui;
    NewCook NC;
};

#endif // MANGERCOOK_H
