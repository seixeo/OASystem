#include "../inc/OAAdmin.h"
#include "../inc/OADataCenter.h"

// 无参构造函数的实现
OAAdmin::OAAdmin() = default;

// 有参构造函数实现
OAAdmin::OAAdmin(const string &username, const string &password) {
    _username = username;
    _password = password;
}

// 获取用户名函数的实现
string OAAdmin::username() {
    return _username;
}

// 调用OADataCenter对象使用addUser方法添加用户
bool OAAdmin::addUser(const string &username, const string &password, const string &department) {
    return OADataCenter::getInstance().addUser(username, password, department);
}

// 调用OADataCenter对象使用deleteUser方法删除用户
bool OAAdmin::deleteUser(const string &username) {
    return OADataCenter::getInstance().deleteUser(username);
}

// 展示所有用户
void OAAdmin::showAllUsers() {
    system("cls");
    for (vector<OAUser> users = OADataCenter::getInstance().getUsers(); OAUser &user: users) {
        cout << "用户名:" << user.username() << '\t' << "部门:" << user.department() << endl;
    }
}


// 创建错误管理员
OAAdmin OAAdmin::ERROR_ADMIN = OAAdmin();
