#ifndef MANAGERDISH_H
#define MANAGERDISH_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class ManagerDish;
}

class ManagerDish : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerDish(QWidget *parent = 0);
    ~ManagerDish();
    void showDishMap();

private slots:
    void on_pushButton_2_clicked();

    void OnBtnClicked();
    void on_pushButton_clicked();

     void closeEvent(QCloseEvent *event);
private:
    Ui::ManagerDish *ui;
};

#endif // MANAGERDISH_H
