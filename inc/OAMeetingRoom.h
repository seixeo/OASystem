#ifndef OAMEETINGROOM_H
#define OAMEETINGROOM_H

#include "OAUser.h"
#include "OADataCenter.h"

class OAMeetingRoom {
    friend class OADataCenter;

private:
    // 编号
    int _id;
    // 容量
    int _category;
    // 使用状态
    OAUser _user = OAUser::ERROR_User;

public:
    OAMeetingRoom();

    OAMeetingRoom(int id, int category);

    int getId() const;

    int getCategory() const;

    OAUser &getUser();
};


#endif //OAMEETINGROOM_H
