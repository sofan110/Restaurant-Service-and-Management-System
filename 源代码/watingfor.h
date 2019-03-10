#ifndef WATINGFOR_H
#define WATINGFOR_H

#include <QDialog>
#include "dish.h"
#include "comment.h"
#include "restaurant.h"
#include "pay.h"

namespace Ui {
class WatingFor;
}

class WatingFor : public QDialog
{
    Q_OBJECT

public:
    explicit WatingFor(QWidget *parent = 0);
    ~WatingFor();
    //Dish &getDish()
    //{
    //    return this->mydish;
    //}
    void showDish();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::WatingFor *ui;
    //Dish mydish;
    comment com;
    Pay p;
};

#endif // WATINGFOR_H
