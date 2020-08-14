#include "user.h"

User::User(string name) {
    this->name = name;
    id = getUserCount() + 1;
    userCount++; 
}

static int User::getUserCount() {
    return userCount;
}