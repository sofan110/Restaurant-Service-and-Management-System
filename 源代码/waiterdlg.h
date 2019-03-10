#ifndef WAITERDLG_H
#define WAITERDLG_H

#include <QDialog>
#include "restaurant.h"
#include "connection.h"
#include "serve.h"

namespace Ui {
class WaiterDlg;
}

class WaiterDlg : public QDialog
{
    Q_OBJECT

public:
    explicit WaiterDlg(QWidget *parent = 0);
    ~WaiterDlg();
    void showWaiterDesk(const QString &waiter);
private slots:

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *event);
    void on_pushButton_2_clicked();

private:
    Ui::WaiterDlg *ui;
    Serve s;
    int chosedesk;
    QString waitername;
    QString username;
};

#endif // WAITERDLG_H
