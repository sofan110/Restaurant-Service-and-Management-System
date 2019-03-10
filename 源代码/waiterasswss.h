#ifndef WAITERASSWSS_H
#define WAITERASSWSS_H

#include <QDialog>
#include "restaurant.h"

namespace Ui {
class WaiterAsswss;
}

class WaiterAsswss : public QDialog
{
    Q_OBJECT

public:
    explicit WaiterAsswss(QWidget *parent = 0);
    ~WaiterAsswss();

    void showIt(const QString &name);
private slots:
     void closeEvent(QCloseEvent *event);
private:
    Ui::WaiterAsswss *ui;
};

#endif // WAITERASSWSS_H
