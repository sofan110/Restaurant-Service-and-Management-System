#ifndef COOKASSESS_H
#define COOKASSESS_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class CookAssess;
}

class CookAssess : public QDialog
{
    Q_OBJECT

public:
    explicit CookAssess(QWidget *parent = 0);
    ~CookAssess();

    void showIt(const QString name);//显示报表
private slots:
     void closeEvent(QCloseEvent *event);
private:
    Ui::CookAssess *ui;
};

#endif // COOKASSESS_H
