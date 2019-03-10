#ifndef CHANGE_H
#define CHANGE_H

#include <QWidget>
#include <QDesktopWidget>

void set_appraeance(QWidget * widget)
{
    widget->move(QApplication::desktop()->width()/2-widget->width()/2,QApplication::desktop()->height()/2-widget->height()/2);
    widget->setStyleSheet("QPushButton:hover{"
                          "background-color: green;"
                          "}");
}

#endif // CHANGE_H
