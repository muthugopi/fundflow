#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <string>
#include <map>
#include <chrono>

struct Member {
    std::string name;
    double savings;
    double loan;
    float savingIntrest;
    float pendingIntrest;
    double intrestGiven;
    std::chrono::system_clock::time_point lastUpdated;
};

extern std::map<int, Member> member;
namespace DataManager {
    extern float SavingIntrestPercentage;
    extern float LoanIntrestPercentage;
}

/*
Plan to add : 

1.payLoan -> member can pay their laon by this function
2.Add intrest system for both savings and loan
*/

void addData(std::string &name, double amount);
void saveData();
void loadData();
void showData();
void showLogs();
void deleteData(const std::string &name);
void updateSaving(std::string name, double amount);

void giveLoan(std::string &name, long double amount);

void applyInterest(std::string &name);

Member* findMember(const std::string &name);


double totalAmount();
double totalSavingAmount();
double totalLoanAmount();

int getMonthsPassed(std::chrono::system_clock::time_point last);

#endif