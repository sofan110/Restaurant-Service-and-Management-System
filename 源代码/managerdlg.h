#ifndef MANAGERDLG_H
#define MANAGERDLG_H

#include <QDialog>
#include "restaurant.h"
#include "waiterasswss.h"
#include "cookassess.h"

namespace Ui {
class ManagerDlg;
}

class ManagerDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ManagerDlg(QWidget *parent = 0);
    ~ManagerDlg();

    void showIt();
private slots:
    void on_tableWidget_doubleClicked(const QModelIndex &index);
    
    void on_tableWidget_2_doubleClicked(const QModelIndex &index);
    
private:
    Ui::ManagerDlg *ui;
    WaiterAsswss WA;
    CookAssess CA;
};

#endif // MANAGERDLG_H
