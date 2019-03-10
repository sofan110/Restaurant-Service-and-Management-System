#ifndef COOK_H
#define COOK_H

#include <QString>
#include "QHash"
class Cook
{
public:
    Cook();
    void CookIn(const QString &name,const QString &pwd);
    QString &ReturnCookName();
    QString &ReturnCookPwd();
    int &reutrnDeskNum();
    void changeDesk(int n);
    void getMark(const int n);
    QHash <int,int>& returnCookMark();
private:
    QString name;//厨师名
    QString pwd;//密码
    int desknum =0 ;//服务餐桌号
    QHash<int,int> CookMark;//评价
};

#endif // COOK_H
