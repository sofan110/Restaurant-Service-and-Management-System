#ifndef MCUSTOMER_H
#define MCUSTOMER_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class MCustomer;
}

class MCustomer : public QDialog
{
    Q_OBJECT

public:
    explicit MCustomer(QWidget *parent = 0);
    ~MCustomer();
    void showCustomer();
private:
    Ui::MCustomer *ui;
};

#endif // MCUSTOMER_H
