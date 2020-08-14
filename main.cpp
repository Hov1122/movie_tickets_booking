#include <iostream>
#include <string>
#include "user.h"

using namespace std;

int main() {
    string menu = R"(Welcome to Movie Ticket Booking System

Menu
1. Book tiket
2. Show my tickets
3. Add new movie
4. Delete movie
5. Show movie list
6. Exit
7. Choose one: )";
    cout << menu << " ";
    int option = 0;
    do {
        cin >> option;
        switch (option) {
            case 1:

                break;
            case 2:
            
                break;
            case 3:
            
                break;
            case 4:
            
                break;
            case 5:
            
                break;
            case 6:
            
                break;
            case 7:
            
                break;

            default:
                cout << "You must enter integer between 1 and 7: ";
                break;
            }
        } while (option > 7 || option < 1);
}