#include <iostream>
#include <string>
#include "user.h"
#include <bits/stdc++.h> 
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

vector<string> splitSentence(string);

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
        return -1; 
    } 
} 
void showMenu();
void showMyTickets(int);
void showMovieList();
void exitOrMenu();

int main() {
    
    int lop;
    string login;
    do {
        cout << "1. Login" << endl << "2. Register" << endl;
        cin >> lop;
        system("clear");
        if (lop == 2) {
            
            string name, password;
            cout << "Name: ";
            cin >> name;
            cout << "Password: ";
            cin >> password;
            ifstream users("users.txt");
            ofstream Users("users.txt", ios::app);
            users.seekg(0, ios::end);  
            if (users.tellg() == 0) {    
                Users << name + " " + password; 
            }
            else{
                Users << endl;
                Users << name + " " + password;
            }
            users.close();  
            Users.close();
        }
        else if (lop == 1) {
            string password;
            ifstream userF;
            userF.open("users.txt");
            vector <string> logins;
            vector <string> pass;
            int count = 0;
            while (userF.good()) { 
                string line;
                getline(userF, line);
                
                vector<string> results = splitSentence(line);
                logins.push_back(results[0]);
                pass.push_back(results[1]);
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
                        if (index == -1) exit(1);
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
        system("clear");
    } while(lop != 1);
    
    system("clear");
    User user(login);
    showMenu();
    

}

void showMenu() {
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
    int option;
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
                    showMovieList();
                    exitOrMenu();
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

void showMyTickets(int id) {
    ifstream moviesFile;
    moviesFile.open("test.csv");
    int count = 1;
    while (moviesFile.good()) {
        string line;
        getline(moviesFile, line, ',');
        cout << line << " ";
        if (count % 3 == 1 && stoi(line) == id) {
            string row;
            getline(moviesFile, row);
            cout << row;
        }
        count++;
    }
    moviesFile.close();
}

void showMovieList() {
    system("clear");
    ifstream moviesFile;
    moviesFile.open("test.csv");
    while (moviesFile.good()) {
        string line;
        getline(moviesFile, line, ',');
        cout << line << " | ";
    }
    cout << endl;
}

vector<string> splitSentence(string line) {
    vector <string> tokens; 
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t. space ' ' 
    while(getline(check1, intermediate, ' ')) 
    { 
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

void exitOrMenu() {
    char op;
    cout << "Press b to go back or anything else to close the program : ";
    cin >> op;
    if (op == 'b') showMenu();
    else{exit(0);}
}