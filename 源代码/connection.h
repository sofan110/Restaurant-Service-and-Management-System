#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql>
#include <QDebug>

class DataBase
{
public:
    static DataBase *Insitial();

     bool createConnection();//创建关联

     /*bool findCustomer(const QString &name)
    {
        QSqlQuery customerquery;//创建顾客表

        customerquery.exec("select name  from user");
        while(customerquery.next())
        {
            if(customerquery.value(0).toString() == name)
            {
               return true;
            }
        }
        return false;
    }
    bool findPsw(const QString &psw)
    {
        QSqlQuery customerquery;//创建顾客表

        customerquery.exec("select pwd from user");
        while(customerquery.next())
        {
            if(customerquery.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }


    
    bool findAdmini(const QString &name)
   {
       QSqlQuery adminiquery;//创建管理员

       adminiquery.exec("select name  from admini");
       while(adminiquery.next())
       {
           if(adminiquery.value(0).toString() == name)
           {
              return true;
           }
       }
       return false;
   }

    bool findPswAdmini(const QString &psw)
    {
        QSqlQuery query;//创建管理员

        query.exec("select pwd from admini");
        while(query.next())
        {
            if(query.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }

    QString resdDeskState(const int &n)//读取餐桌状态
    {
        QSqlQuery query;//创建管理员

        query.exec("select * from desk");
        while(query.next())
        {
            if(query.value(0).toInt() == n && query.value(1).toString() == "用餐中")
            {
               return query.value(1).toString();
            }
        }
        return NULL;
    }

    void changeDeskState(const int &n)//更改餐桌状态
    {
       QSqlQuery query;//创建餐桌表

        query.prepare("UPDATE INTO desk(num,state) VALUES(?,?)");
        query.addBindValue(n);
        query.addBindValue("用餐中");

        if(!query.exec())
            qDebug()<<"搞事啊";
    }

    bool findWaiter(const QString &name)
   {
       QSqlQuery query;//创建管理员

       query.exec("select name  from waiter");
       while(query.next())
       {
           if(query.value(0).toString() == name)
           {
              return true;
           }
       }
       return false;
   }

    bool findPswWaiter(const QString &psw)
    {
        QSqlQuery query;//创建管理员

        query.exec("select pwd from waiter");
        while(query.next())
        {
            if(query.value(0).toString() == psw)
            {
               return true;
            }
        }
        return false;
    }
    bool findCook(const QString &name)
    {
        QSqlQuery query;

        query.exec("select name from cook");
        while(query.next())
        {
            if(query.value(0).toString() == name)
            return true;
        }
        return false;
    }*/
    bool findPwdCook(const QString &pwd);
    void inserct(const QString &name,const QString &pwd);//不可删除
    void insertInDishMap(const QString &dishname,const QString &dishprice);//插入菜单表
    void insertInCook(const QString &name,const QString &pwd);//插入厨师表

private:
    DataBase() {}
    static DataBase *database;//设置为单例模式
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");//创建数据库
};
#endif // CONNECTION_H
