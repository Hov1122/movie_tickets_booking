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
        string name;
        int id;
        string phone;
        static int userCount;

    public:
        void addMovie(int, int);
        User(string); // name
        static int getUserCount() {return userCount;};
        
};