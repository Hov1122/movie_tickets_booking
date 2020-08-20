#include <iostream>
#include <string>
#include <bits/stdc++.h> 
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct info {
    vector <string> movie_id;
    vector <string> seat;
};


// helper functions
string login_reg(); //make login or registration
vector<string> splitSentence(string, char a = ' ');
int getIndex(vector<string> v, string K);
info getInfo(string);
//

// main functions // 

void showMenu();
void bookTicket(string, string, string);
void showMyTickets();
void showMovieList();
void exitOrMenu();
// 

string login;

int main() {
    
    login = login_reg(); // return login and create user object with that login
    showMenu();
    
    return 0;
}


/// main functions ///
/// main functions ///
/// main functions ///

void showMenu() {
    string menu = R"(Welcome to Movie Ticket Booking System

Menu
1. Book tiket
2. Show my tickets
3. Show movie list
4. Exit
Choose one: )";
    cout << menu << " ";
    int option;
    do {
        cin >> option; 
        switch (option) {
            case 1:
                {
                    system("clear"); // for windows use system("cls")
                    showMovieList();
                    string movie_id, seat;
                    cout << "Enter the id of movie which you want to book : ";
                    cin >> movie_id;
                    cout << "Where would you like to seat: ";
                    cin >> seat;
                    bookTicket(login, movie_id, seat);
                    cout << "Congratulations uou sucsesfully booked a ticket" << endl;
                    exitOrMenu();
                    break;
                }
            case 2:
                system("clear");
                showMyTickets();
                cout << endl;
                exitOrMenu();
                break;
            
            case 3:
                {
                    showMovieList();
                    exitOrMenu();
                    break;
                }
            case 4:
                exit(0);
                break;

            default:
                cout << "You should enter a number between 1 and 7: ";
                break;
            }
        } while (option > 4 || option < 1);
}

void bookTicket(string login, string movie_id, string seat) {
    vector <string> data;
    vector <string> resV;
    ifstream r("users.txt");
    string line;
    while(r.good()) {
        getline(r, line);
        data = splitSentence(line);
        if (data[0] == login) {
            if(data.size() > 2 ) {
                data[2] += movie_id + "#";
                data[3] += seat + "#";
            }
            else {
                data.push_back(movie_id + "#");
                data.push_back(seat + "#");
            }
            string res = data[0] + " " + data[1] + " " + data[2] + " " + data[3];
            resV.push_back(res);
            
        }
        else {
            resV.push_back(line);
        }
    }
    
    
    ofstream w("users.txt", ios::out);
    int count = 0;
    for (string s : resV) {
        count++;
        w << s;
        if (count < resV.size()) w << endl;  
        
    }
}

void showMyTickets() {
    // TO DO
    info data = getInfo(login);
    if (data.movie_id.empty()) {
        cout << "You didn't booked any ticket yet" << endl;
        return;
    }
    string line;
    ifstream f("movies.csv");
    bool flag = false;
    int count = 0;
    while (f.good()){
        getline(f, line);
        //cout << line << endl;
        vector <string> tokens = splitSentence(line, ',');
       // cout << tokens[0];
        for (string s : data.movie_id) {
            //cout << s << " " <<  tokens[0] << endl;
            if (s == tokens[0] || (tokens[0] == "ID" && !flag))
            {   
                for (string c : tokens) {
                    cout << c << " | ";
                }
                if (!flag) cout << "Your place |";
                else {cout << data.seat[count++] << " | ";}
                flag = true;
                cout << endl; 
            }
            
        }
    }

}

void showMovieList() {
    system("clear");
    ifstream moviesFile;
    moviesFile.open("movies.csv");
    while (moviesFile.good()) {
        string line;
        getline(moviesFile, line, ',');
        cout << line << " | ";
    }
    cout << endl;
}

void exitOrMenu() {
    string op;
    cout << "Press b to go back or anything else to close the program : ";
    cin >> op;
    if (op == "b") showMenu();
    else{exit(0);}
}

/// helper functions ///
/// helper functions ///
/// helper functions ///

vector<string> splitSentence(string line, char a) {
    vector <string> tokens; 
      
    // stringstream class check1 
    stringstream check1(line); 
      
    string intermediate; 
      
    // Tokenizing w.r.t.
    int count = 0;
    while(getline(check1, intermediate, a)) 
    {   
        
        tokens.push_back(intermediate); 
    } 
    return tokens;
}

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

string login_reg() {
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
            if (userF.peek() == std::ifstream::traits_type::eof()) {
                lop = -1;
            }
            else {
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
            
        }
        
        else {
            system("clear");
            cout << "You must enter 1 or 2" << endl;
        }
        system("clear");
    } while(lop != 1);

    system("clear");

    return login;
}

info getInfo(string login) {
    ifstream r("users.txt");
    info data;
    while(r.good()) {
        string line;
        getline(r, line);
        vector <string> tokens = splitSentence(line);
        if(tokens[0] == login) {
            if (tokens.size() <= 2) return data;
            int pos = 0;
            for (int i = 0; i < tokens[2].length(); i++) {
                if (tokens[2][i] == '#') {
                    string res = "";
                    for (int j = pos; j < i; j++) res += tokens[2][j];
                    data.movie_id.push_back(res);
                    pos = i + 1;
                }
            }
            pos = 0;
            for (int i = 0; i < tokens[3].length(); i++) {
                if (tokens[3][i] == '#') {
                    string res = "";
                    for (int j = pos; j < i; j++) res += tokens[3][j];
                    data.seat.push_back(res);
                    pos = i + 1;
                }
            }
        }
    }
    return data;
}
