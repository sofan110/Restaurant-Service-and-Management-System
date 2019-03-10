#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QMessageBox>
#include "newid.h"
namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();

private slots:

    void on_continueBtn_clicked();

private:
    Ui::Register *ui;
    NewId ni;
};

#endif // REGISTER_H
