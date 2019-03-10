#ifndef NEWWORKER_H
#define NEWWORKER_H

#include <QDialog>
#include "restaurant.h"
namespace Ui {
class NewWorker;
}

class NewWorker : public QDialog
{
    Q_OBJECT

public:
    explicit NewWorker(QWidget *parent = 0);
    ~NewWorker();

    QString name;
    QString pwd;
private slots:
    void on_pushButton_clicked();

private:
    Ui::NewWorker *ui;
};

#endif // NEWWORKER_H
