#include "../inc/OASystemUI.h"
#include "../inc/OADataCenter.h"
#include "../inc/OAUtils.h"
#include <iostream>
using namespace std;

#define FLAG_ADMIN 1
#define FLAG_USER 0

// 添加用户
void showAdminAddUserPage(OAAdmin &admin) {
    system("cls");
    string username, password, department;
    cout << "请输入添加的用户名:";
    cin >> username;
    cout << "请输入该用户的密码:";
    cin >> password;
    cout << "请输入该用户的部门:";
    cin >> department;

    if (OAAdmin::addUser(username, password, department)) {
        cout << "添加成功" << endl;
    } else {
        cout << "添加失败，此用户已存在" << endl;
    }
    system("pause");
}

// 删除用户
void showAdminDeleteUserPage(OAAdmin &admin) {
    system("cls");
    string username;
    cout << "请输入需要删除的用户名:";
    cin >> username;

    if (OAAdmin::deleteUser(username)) {
        cout << "删除成功" << endl;
    } else {
        cout << "删除失败，未找到该用户" << endl;
    }
}

// 列举所有用户
void showAdminListUser(OAAdmin &admin) {
    admin.showAllUsers();
}

// 管理员的主界面
void showAdminMainPage(OAAdmin &admin) {
    while (true) {
        system("cls");
        cout << "欢迎管理员:" << admin.username() << endl;
        cout << "--------------------" << endl;
        cout << "1.添加一个普通用户" << endl;
        cout << "2.删除一个普通用户" << endl;
        cout << "3.列举所有的普通用户" << endl;
        cout << "4.添加一个会议室" << endl;
        cout << "5.删除一个会议室" << endl;
        cout << "6.列举所有的会议室" << endl;
        cout << "7.重置会议室状态" << endl;
        cout << "8.退出登录" << endl;
        cout << "--------------------" << endl;
        cout << "请输入您的选择:";
        switch (int choice = OAUtils::inputNumber()) {
            case 1:
                showAdminAddUserPage(admin);
                break;
            case 2:
                showAdminDeleteUserPage(admin);
                break;
            case 3:
                showAdminListUser(admin);
                break;
            case 4:
                cout << "添加一个会议室" << endl;
                break;
            case 5:
                cout << "删除一个会议室" << endl;
                break;
            case 6:
                cout << "列举所有的会议室" << endl;
                break;
            case 7:
                cout << "重置会议室状态" << endl;
                break;
            case 8:
                goto end;
            case 9:
            default:
                cout << "请重新输入" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
end:
    cout << "再见" << endl;
}

// 显示登录界面，flag表示的身份
// 1：管理员登录
// 0：普通用户登录
void showLogin(const int flag) {
    system("cls");
    if (flag == FLAG_ADMIN) {
        cout << "管理员登录" << endl;
    } else {
        cout << "普通用户登录" << endl;
    }
    cout << "--------------------" << endl;
    string username, password;
    cout << "请输入用户名：";
    cin >> username;
    cout << "请输入密码：";
    cin >> password;

    OADataCenter &dataCenter = OADataCenter::getInstance();

    if (flag == FLAG_ADMIN) {
        OAAdmin &admin = dataCenter.loginAdmin(username, password);
        if (&admin == &(OAAdmin::ERROR_ADMIN)) {
            cout << "登陆失败,回到上一层" << endl;
        } else {
            showAdminMainPage(admin);
        }
    } else {
        OAUser &user = dataCenter.loginUser(username, password);
        if (&user == &(OAUser::ERROR_User)) {
            cout << "登陆失败,回到上一层" << endl;
        } else {
            cout << "登陆成功,欢迎" << user.department() << "的" << user.username() << endl;
        }
    }
}

// OA系统主界面
void OASystemUI::displayMainPage() {
    while (true) {
        cout << "欢迎使用OA会议室预定系统" << endl;
        cout << "-----------------------" << endl;
        cout << "1. 管理员登录" << endl;
        cout << "2. 普通用户登录" << endl;
        cout << "3. 退出系统" << endl;
        cout << "-----------------------" << endl;
        cout << "请输入您的选择:";

        // 让用户进行控制台的输入选择
        switch (int choice = OAUtils::inputNumber()) {
            case 1:
                showLogin(FLAG_ADMIN);
                break;
            case 2:
                showLogin(FLAG_USER);
                break;
            case 3:
                goto end;
            default:
                cout << "请重新输入" << endl;
                break;
        }
        system("pause");
        system("cls");
    }
end:
    cout << "欢迎下次使用" << endl;
}
