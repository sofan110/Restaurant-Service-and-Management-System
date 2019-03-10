#include "cook.h"

Cook::Cook()
{

}

void Cook::CookIn(const QString &name,const QString &pwd)
{
    this->name = name;
    this->pwd = pwd;
}

QString &Cook::ReturnCookName()
{
    return this->name;
}

QString &Cook::ReturnCookPwd()
{
    return this->pwd;
}

int &Cook::reutrnDeskNum()
{
    return this->desknum;
}

void Cook::changeDesk(int n)
{
    this->desknum = n;
}

void Cook::getMark(const int n)
{
    int num = 0;
    QHash<int,int>::iterator i;

    for(i = CookMark.begin();i!=CookMark.end();++i)
    {
        num++;
    }
    CookMark.insert(num,n);
}

QHash <int,int>&Cook::returnCookMark()
{
    return this->CookMark;
}
