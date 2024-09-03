#include "../inc/OAUser.h"

//无参构造函数的实现
OAUser::OAUser() {
}

//有参构造函数实现
OAUser::OAUser(const string &username, const string &password, const string &department) {
    _username = username;
    _password = password;
    _department = department;
}

//获取用户名函数的实现
string OAUser::username() {
    return _username;
}

//获取部门名称函数的实现
string OAUser::department() {
    return _department;
}

//创建错误用户
OAUser OAUser::ERROR_User = OAUser();
