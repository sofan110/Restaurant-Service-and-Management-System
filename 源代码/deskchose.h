#ifndef DESKCHOSE_H
#define DESKCHOSE_H

#include <QDialog>
#include "order.h"
#include "restaurant.h"

namespace Ui {
class DeskChose;
}

class DeskChose : public QDialog
{
    Q_OBJECT

public:
    explicit DeskChose(QWidget *parent = 0);
    ~DeskChose();


private slots:
    void on_deskBtn1_clicked();

    void on_deskBtn2_clicked();

    void on_deskBtn3_clicked();

    void on_deskBtn4_clicked();

    void on_sureBtn_clicked();

    void on_exitBtn_clicked();

    void setUnable(int n);

    void setAble(int &n);

    bool IsDeskUsed(int &n);

private:
    Ui::DeskChose *ui;
    Order order;

};

#endif // DESKCHOSE_H
