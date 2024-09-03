#include "../inc/OADataCenter.h"

// 默认存放的数据
OADataCenter::OADataCenter() {
    // 初始化管理员和普通用户
    admins.emplace_back("admin", "admin");
    users.emplace_back("chengyu", "123", "行政部");
    users.emplace_back("langpeng", "000", "人力资源部");
    // 初始化会议室
    rooms.emplace_back(OAMeetingRoom(1, 10));
    rooms.emplace_back(OAMeetingRoom(2, 20));
    rooms.emplace_back(OAMeetingRoom(3, 30));
}


// 访问私有的数据对象:_instance
OADataCenter &OADataCenter::getInstance() {
    return _instance;
}


// 创建数据中心对象
OADataCenter OADataCenter::_instance = OADataCenter();


// 管理员登录函数的实现
OAAdmin &OADataCenter::loginAdmin(const string &username, const string &password) {
    for (OAAdmin &admin: admins) {
        if (admin._username == username && admin._password == password) {
            return admin;
        }
    }
    //如果数据中心无对应的用户，则返回默认管理对象
    return OAAdmin::ERROR_ADMIN;
}


// 普通用户登录函数的实现
OAUser &OADataCenter::loginUser(const string &username, const string &password) {
    for (OAUser &user: users) {
        if (user._username == username && user._password == password) {
            return user;
        }
    }
    //如果数据中心无对应的用户，则返回默认管理对象
    return OAUser::ERROR_User;
}


// 添加普通用户函数的实现
bool OADataCenter::addUser(const string &username, const string &password, const string &department) {
    // 检查用户是否存在
    for (OAUser &user: users) {
        if (user._username == username) {
            return false;
        }
    }
    // 添加用户
    users.emplace_back(username, password, department);
    return true;
}


// 删除普通用户函数的实现
bool OADataCenter::deleteUser(const string &username) {
    // 检查用户是否存在
    auto it = users.begin();
    for (; it != users.end(); ++it) {
        if (it->username() == username) {
            break;
        }
    }

    // 判断是否找到了这个用户
    if (it == users.end()) {
        return false;
    }
    users.erase(it);
    return true;
}


//获取所有用户(备份)
vector<OAUser> OADataCenter::getUsers() const {
    vector users_bak(users);
    return users_bak;
}
