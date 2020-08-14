#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User 
{
    private:
        vector <int> movies;
        vector <int> seats;
        const char* name;
        int id;
        string phone;
        static int userCount;

    public:
        void addMovie(int, int);
        User(const char*); // name
        void setPhone(string);
        static int getUserCount() {return userCount;}
        
};
int User::userCount = 0;
User::User(const char* name) {
    this->name = name;
    id = ++userCount;
}