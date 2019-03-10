#ifndef PAY_H
#define PAY_H

#include <QDialog>
#include "restaurant.h"
namespace Ui {
class Pay;
}

class Pay : public QDialog
{
    Q_OBJECT

public:
    explicit Pay(QWidget *parent = 0);
    ~Pay();

    void showDish();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Pay *ui;
};

#endif // PAY_H
