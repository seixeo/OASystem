#ifndef OAADMIN_H
#define OAADMIN_H
#include <iostream>
#include "OADataCenter.h"
using namespace std;

class OAAdmin {
    //定义友元类OADataCenter
    friend class OADataCenter;

private:
    string _username;
    string _password;

public:
    //无参构造函数
    OAAdmin();

    //有参构造函数
    OAAdmin(const string &username, const string &password);

    //创建默认管理对象
    static OAAdmin ERROR_ADMIN;

    //获取用户名函数
    string username();

    static bool addUser(const string &username, const string &password, const string &department);

    static bool deleteUser(const string &username);
};


#endif //OAADMIN_H
