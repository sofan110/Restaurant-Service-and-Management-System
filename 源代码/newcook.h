#ifndef NEWCOOK_H
#define NEWCOOK_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class NewCook;
}

class NewCook : public QDialog
{
    Q_OBJECT

public:
    explicit NewCook(QWidget *parent = 0);
    ~NewCook();

    QString name;
    QString pwd;
private slots:
    void on_pushButton_clicked();

private:
    Ui::NewCook *ui;
};

#endif // NEWCOOK_H
