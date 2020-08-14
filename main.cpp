#include <iostream>
#include <string>
#include "user.h"
#include <iterator>
#include <bits/stdc++.h> 
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int getIndex(vector<string> v, string K) 
{ 
    auto it = find(v.begin(), 
                   v.end(), K); 
  
    // If element was found 
    if (it != v.end()) { 
        // calculating the index 
        // of K 
        int index = distance(v.begin(), 
                             it); 
        return index;
    } 
    else { 
        // If the element is not 
        // present in the vector 
        return 2; 
    } 
} 

int main() {
    
    int lop;
    do {
        cout << "1. Login" << endl << "2. Register" << endl;
        cin >> lop;
        if (lop == 2) {
            string name, password;
            cout << "Name: ";
            cin >> name;
            cout << "Password";
            cin >> password;
            cout << "Do you want to add phone number? ";
            
            ofstream users;
            users.open ("users.txt");
            users << name + " " + password;
            users.close();  
        }
        else if (lop == 1) {
            string login, password;
            ifstream userF;
            userF.open("users.txt");
            vector <string> logins;
            vector <string> pass;
            int count = 0;
            while (userF.good()) { 
                string line;
                getline(userF, line, ' ');
                if (count % 2 == 0 ) logins.push_back(line);
                else {pass.push_back(line);}
                count++;
            }
            userF.close();
            bool flag = false;
            while(true) {
                system("clear");
                cout << "Login: ";
                cin >> login;
                cout << "Password: ";
                cin >> password;
                for (string l : logins) {
                    if (l == login) {
                        int index = getIndex(logins, login);
                        if (pass[index] == password) {
                            flag = true;
                            break;
                        }
                    }
                    
                }
                if (flag) break;
            }
            
        }
        
        else {
            system("clear");
            cout << "You must enter 1 or 2" << endl;
        }
        cout << lop;
    } while(lop != 1 && lop != 2);
    
   
    string menu = R"(Welcome to Movie Ticket Booking System

Menu
1. Book tiket
2. Show my tickets
3. Add new movie
4. Delete movie
5. Show movie list
6. Exit
Choose one: )";
    cout << menu << " ";
    int option = 0;
    do {
        cin >> option;
        switch (option) {
            case 1:
                system("clear"); // for windows use system("cls")
                break;
            case 2:
                
                break;
            case 3:
            
                break;
            case 4:
            
                break;
            case 5:
                {
                    system("clear");
                    ifstream moviesFile;
                    moviesFile.open("test.csv");
                    while (moviesFile.good()) {
                        string line;
                        getline(moviesFile, line, ',');
                        cout << line << " ";
                    }
                    break;
                }
            case 6:
                exit(0);
                break;

            default:
                cout << "You must enter integer between 1 and 7: ";
                break;
            }
        } while (option > 7 || option < 1);

}