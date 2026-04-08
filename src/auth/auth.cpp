#include <iostream>
#include <fstream>
#include <string>
#include "../../include/auth/auth.h"
using namespace std;

//global variable

bool isLogined = true;
string username;
// login

void login(std::string name, std::string password) {
    if(name.empty() || password.empty()) {
        cout<<"both name and password required!"<<endl;
        return;
    }

    ifstream file("data/admin.txt");

    string fileName, filePassword;
    bool found = false;
    while(file >> fileName >> filePassword) {
        if(name == fileName && password == filePassword) {
            found = true;
            isLogined = true;
            username = name;
            break;
        }
    }

    if(found) {
        cout<<"Login successfully!"<<endl;
    } else {
        cout<<"Invalid credentials!"<<endl;
    }
}