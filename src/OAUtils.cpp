//
// Created by Administrator on 24-9-2.
//

#include "../inc/OAUtils.h"
#include <iostream>
#include <limits>

using namespace std;

int OAUtils::inputNumber() {
    int choice = -1;
    cin >> choice;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> choice;
    }
    return choice;
}
