#include "waiter.h"

Waiter::Waiter()
{
    desknum = 0;
}

void Waiter::getName(QString name)
{
    this->name = name;
}

void Waiter::getPwd(QString pwd)
{
    this->pwd = pwd;
}

QString &Waiter::ReturnWaiterName()
{
    return this->name;
}

QString &Waiter::ReturnWaiterPwd()
{
    return this->pwd;
}

int Waiter::returnMarkTime()//返回服务员被评价的次数,即服务过的餐桌数
{
    int n = 0;
    QHash<int,int>::iterator i;
    
    for(i = WaiterMark.begin();i!=WaiterMark.end();++i)
    {
        n++;
    }
   return n;
}

void Waiter::getMark(const int &n)//打一次分
 {
       WaiterMark.insert(returnMarkTime(),n);
 }

void Waiter::getDeskNum(const int &n)//服务一桌
 {
    int num = 0;
    QHash<int,int>::iterator i;

    for(i = WaiterDeskNum.begin();i!=WaiterDeskNum.end();++i)
    {
        num++;
    }
    WaiterDeskNum.insert(num,n);

 }
 void Waiter::clearDeskNum(const int &n)//结束服务一桌
  {
     QHash<int,int>::iterator i;

     for(i = WaiterDeskNum.begin();i!=WaiterDeskNum.end();++i)
     {
        if(i.value() == n)
        {
            WaiterDeskNum.erase(i);
        }
     }
  }

 QHash <int,int> &Waiter::returnDeskNum()
 {
     return this->WaiterDeskNum;
 }

 QHash <int,int> &Waiter::returnWAiterMark()
 {
     return this->WaiterMark;
 }

 bool Waiter::findDeskNum(const int &n)
 {
     QHash<int,int>::iterator i;

     for(i = WaiterDeskNum.begin();i!=WaiterDeskNum.end();++i)
     {
        if(i.value() == n)
        {
            return true;
        }
     }
     return false;
 }

