#include "../inc/OAAdmin.h"
#include "../inc/OADataCenter.h"

//无参构造函数的实现
OAAdmin::OAAdmin() = default;

//有参构造函数实现
OAAdmin::OAAdmin(const string &username, const string &password) {
    _username = username;
    _password = password;
}

//获取用户名函数的实现
string OAAdmin::username() {
    return _username;
}

bool OAAdmin::addUser(const string &username, const string &password, const string &department) {
    return OADataCenter::getInstance().addUser(username, password, department);
}

bool OAAdmin::deleteUser(const string &username) {
    return OADataCenter::getInstance().deleteUser(username);
}


//创建错误管理员
OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin();
