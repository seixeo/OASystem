#ifndef OAUSER_H
#define OAUSER_H
#include <iostream>
#include "OADataCenter.h"
using namespace std;

class OAUser {
    friend class OADataCenter;

private:
    string _username;
    string _password;
    string _department;

public:
    //无参构造函数
    OAUser();

    //有参构造函数
    OAUser(const string &username, const string &password, const string &department);

    //创建默认管理对象
    static OAUser ERROR_User;

    //获取用户名函数
    string username();

    string department();
};


#endif //OAUSER_H
