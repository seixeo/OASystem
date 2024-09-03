#ifndef OAADMIN_H
#define OAADMIN_H
#include <iostream>
#include "OADataCenter.h"
using namespace std;

class OAAdmin {
    // 定义友元类OADataCenter
    friend class OADataCenter;

private:
    string _username;
    string _password;

public:
    // 无参构造函数
    OAAdmin();

    // 有参构造函数
    OAAdmin(const string &username, const string &password);

    // 创建默认管理对象
    static OAAdmin ERROR_ADMIN;

    // 获取用户名函数
    string username();

    // 添加用户
    static bool addUser(const string &username, const string &password, const string &department);

    // 删除用户
    static bool deleteUser(const string &username);

    // 展示所有用户
    static void showAllUsers();
};


#endif //OAADMIN_H
