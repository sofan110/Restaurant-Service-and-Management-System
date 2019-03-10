#ifndef NEWID_H
#define NEWID_H

#include <QDialog>
#include <QMessageBox>
#include "deskchose.h"
#include "restaurant.h"

namespace Ui {
class NewId;
}

class NewId : public QDialog
{
    Q_OBJECT

public:
    explicit NewId(QWidget *parent = 0);
    ~NewId();

private slots:
    void on_registerBtn_clicked();

private:
    Ui::NewId *ui;
    DeskChose des;
};

#endif // NEWID_H
