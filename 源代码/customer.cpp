#include "customer.h"

 QString &Customer::returnCustomName()
 {
     return this->name;
 }

 QString &Customer::returnPwd()
 {
     return this->pwd;
 }

 void Customer::changeName(const QString mname)
 {
     name = mname;
 }

 int & Customer::returnProcess()
 {
     return this->process;

 }

