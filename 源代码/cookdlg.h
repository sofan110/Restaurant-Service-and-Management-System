#ifndef COOKDLG_H
#define COOKDLG_H

#include <QDialog>
#include "connection.h"
#include "restaurant.h"
#include "cooking.h"

namespace Ui {
class CookDlg;
}

class CookDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CookDlg(QWidget *parent = 0);
    ~CookDlg();
    void showCookDesk(const QString &name);
private slots:
    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void closeEvent(QCloseEvent *event);
private:
    Ui::CookDlg *ui;
    Cooking c;//做菜窗口
    QString username;//用户名
    int desknum;//餐桌号
};

#endif // COOKDLG_H
