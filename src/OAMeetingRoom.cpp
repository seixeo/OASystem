#include "../inc/OAMeetingRoom.h"

OAMeetingRoom::OAMeetingRoom() {
    _id = 0;
    _category = 0;
    _user = OAUser::ERROR_User;
}

OAMeetingRoom::OAMeetingRoom(const int id, const int category) {
    _id = id;
    _category = category;
}

int OAMeetingRoom::getId() const {
    return _id;
}

int OAMeetingRoom::getCategory() const {
    return _category;
}

OAUser &OAMeetingRoom::getUser() {
    return _user;
}
