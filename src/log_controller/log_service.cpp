#include <bits/stdc++.h>
#include "../../include/log_controller/log_service.h"

using namespace std;

void addLog(string event, string name) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    ofstream file("data/log.txt", ios::app);

    if(!file)
        cout<<"Error while opening file!"<<endl;
    
    file<<"[ INFO ] "<<event<<" : user ["<<name<<"] -> [ "<<ltm->tm_hour<<":"<<ltm->tm_min<<" ]"<<endl;

    file.close();
}

void warnLog(string event, string name) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    ofstream file("data/log.txt", ios::app);

    if(!file)
        cout<<"Error while opening file!"<<endl;

    file<<"[ WARNING ] "<<event<<" user ["<<name<<"] -> [ "<<ltm->tm_hour<<":"<<ltm->tm_min<<" ]"<<endl;

    
}

void errorLog(string event, string name) {
    time_t now = time(0);
    tm* ltm = localtime(&now);

    ofstream file("data/log.txt", ios::app);

    if(!file)
        cout<<"Error while opening file!"<<endl;

    file<<"[ ERROR ] "<<event<<" user ["<<name<<"] -> [ "<<ltm->tm_hour<<":"<<ltm->tm_min<<" ]"<<endl;

    
}