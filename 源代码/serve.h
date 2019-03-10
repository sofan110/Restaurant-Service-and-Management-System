#ifndef SERVE_H
#define SERVE_H

#include <QDialog>
#include "restaurant.h"
namespace Ui {
class Serve;
}

class Serve : public QDialog
{
    Q_OBJECT

public:
    explicit Serve(QWidget *parent = 0);
    ~Serve();
    void showDish(int n);

    void closeEvent(QCloseEvent *event);
private:
    Ui::Serve *ui;
};

#endif // SERVE_H
