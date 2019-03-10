#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include "logindialog.h"
#include "register.h"
#include "deskchose.h"
#include "administrator.h"
#include "waiterdlg.h"
#include "cookdlg.h"
#include "managerdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_loginBtn_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_commandLinkButton_clicked();
    
    void on_commandLinkButton_2_clicked();
    
    void closeEvent(QCloseEvent *event);
    void on_commandLinkButton_4_clicked();

private:
    Ui::MainWindow *ui;
    LoginDialog dlg;
    Register rg;
    DeskChose dc;
    Administrator baba;
    WaiterDlg wd;
    CookDlg cd;
    Order od;
    WatingFor wf;
    ManagerDlg md;
    Cooking co;
};

#endif // MAINWINDOW_H
