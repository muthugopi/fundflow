#include <bits/stdc++.h>
#include "../include/data_manager.h"
#include "../include/log_controller/log_service.h"
#include "../include/auth/auth.h"
using namespace std;

map<int, Member> member;

namespace DataManager {
    float SavingIntrestPercentage = 0.01;
    float LoanIntrestPercentage = 0.03;
}


void addData(string &name, double amount) {
    for(auto &it : member) {
        if(it.second.name == name) {
            cout<<"Member already exist"<<endl;
            warnLog("Member "+name+" already exist! ", username);
            return;
        }
    }

    Member m;
    m.name = name;
    m.savings = amount;
    m.loan = 0.0;
    m.savingIntrest = 0.0f;
    m.pendingIntrest = 0.0f;
    m.intrestGiven  = 0.0;
    m.lastUpdated = std::chrono::system_clock::now(); 
    int nextID = member.empty() ? 1 : member.rbegin()->first + 1;
    member[nextID] = m;
    addLog("Member "+name+" added successfully!", username);
}


void saveData() {
    ofstream file("data/data.txt");
    for(auto &it: member) {        
        file << it.first << " "
             << it.second.name << " "
             << it.second.savings << " "
             << it.second.loan << " "
             << it.second.intrestGiven << "\n";
    }

    addLog("Saved data.txt", username);
}


void loadData() {
    ifstream file("data/data.txt");
    int id; Member m;

    if(!file) {
        cout<<"Error While Opening file!"<<endl;
        warnLog("Error while opening data.txt", username);
        exit(0);
    }

    member.clear();

    while(file >> id >> m.name >> m.savings >> m.loan >> m.intrestGiven) {
        member[id] = m;
    }
    addLog("Loaded data.txt", username);
}


void showData() {
    loadData();
    for(auto &it: member) {
        cout<<"\n";
        cout<<"ID : "<<it.first<<endl;
        cout<<"Name : "<<it.second.name<<endl;
        cout<<"Savings : "<<it.second.savings<<endl;
        cout<<"Loan : "<<it.second.loan<<endl;
        cout<<"IntrestGiven : "<<it.second.intrestGiven<<endl;
        cout<<"\n";
    }
    addLog("Viewed all member's data ", username);
    cout<<"Total datas : "<<member.size()<<endl;
}

void showLogs() {
    ifstream file("data/log.txt");

    if(!file) {
        cout<<"Error while opening the file!"<<endl;
        return;
    }

    string data;

    while(getline(file, data)) {
        cout << data << endl;
    }

    addLog("Fetched all logs", username);
}


void deleteData(const string &name) {
    for(auto it = member.begin(); it != member.end(); ++it) {
        if(it->second.name == name) {
            member.erase(it);
            cout << "Member Data Vanished!!" << endl;
            addLog("Member : " + name+ " deleted ", username);
            return;
        }
    }
    errorLog("Tried to delete unknown member : "+name, username);
    cout << "Member doesn't exist" << endl;

}


void updateSaving(string name, double amount) {
    for(auto &it : member) {
        if(it.second.name == name) {
            it.second.savings += amount;
            addLog("Updated member "+name+"'s amount to "+to_string(amount), username);
            return;
        }
    }
    cout<<"User doesn't exist"<<endl;
    errorLog("Tried to update unknow member "+name, username);
}

void applyInterest(string &name) {
    using namespace DataManager;
    Member *m = findMember(name);
    int months = getMonthsPassed(m->lastUpdated);
    if (months <= 0) return;
    m->savings *= pow(1 + SavingIntrestPercentage / 12.0, months);
    m->loan *= pow(1 + LoanIntrestPercentage / 12.0, months);
    m->lastUpdated = std::chrono::system_clock::now();
}

Member* findMember(const string &name) {
    for(auto &it : member) {
        if(it.second.name == name) {
            addLog("Fetched "+name+"'s data", username);
            return &it.second;
        }
    }
    warnLog("Member "+name+" doesn't exist ", username);
    cout << "Member Not Found!" << endl;
    return nullptr;
}

double totalSavingAmount() {
    long double t = 0;
    for(auto &it: member) {
        t += it.second.savings;
    }
    addLog("Viewed total saving amount", username);
    return t;
}

double totalLoanAmount() {
    long double t = 0;
    for(auto &it: member) {
        t += it.second.loan;
    }
    addLog("Viewed total loan amount", username);
    return t;
}

double totalAmount() {
    addLog("viewed total (available) amount", username);
    return totalSavingAmount() - totalLoanAmount();
}

void giveLoan(string &name, long double amount) {

    long double available = totalAmount();

    if(amount > available) {
        cout<<"Invalid Money!"<<endl;
        return;
    }

    Member *m = findMember(name);
    if(!m) return;

    m->loan += amount;

    cout<<"Loan Issued!"<<endl;
}

int getMonthsPassed(std::chrono::system_clock::time_point last) {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto diff = duration_cast<hours>(now - last).count();

    int months = diff / (24 * 30);
    return months;
}