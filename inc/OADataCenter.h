#ifndef OAUSERCENTER_H
#define OAUSERCENTER_H
#include <vector>
#include "OAAdmin.h"
#include "OAUser.h"
#include "OAMeetingRoom.h"

// 声明管理员类,普通用户类,会议室类
class OAAdmin;
class OAUser;
class OAMeetingRoom;

class OADataCenter {
private:
    // 创建vector容器存放管理员,普通用户,会议室
    vector<OAAdmin> admins;
    vector<OAUser> users;
    vector<OAMeetingRoom> rooms;

    // 无参构造函数私有化,让外部无法创建对象
    OADataCenter();

    // 静态对象
    static OADataCenter _instance;

public:
    // 访问私有的静态对象:_instance
    static OADataCenter &getInstance();

    // 管理员登录函数
    OAAdmin &loginAdmin(const string &username, const string &password);

    // 普通用户登录函数
    OAUser &loginUser(const string &username, const string &password);

    // 添加用户,返回值表示是否添加成功
    bool addUser(const string &username, const string &password, const string &department);

    // 删除用户
    bool deleteUser(const string &username);

    // 获取所有用户(备份)
    vector<OAUser> getUsers() const;

    // 添加会议室
};


#endif //OAUSERCENTER_H
