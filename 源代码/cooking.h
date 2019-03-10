#ifndef COOKING_H
#define COOKING_H

#include <QDialog>
#include "restaurant.h"
#include <QCloseEvent>

namespace Ui {
class Cooking;
}

class Cooking : public QDialog
{
    Q_OBJECT

public:
    explicit Cooking(QWidget *parent = 0);
    ~Cooking();

    void showDish(int n);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);
private:
    Ui::Cooking *ui;

    int num;
};

#endif // COOKING_H
