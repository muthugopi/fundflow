#include <bits/stdc++.h>
#include "../include/intrest.h"
#include "../include/data_manager.h"

using namespace std;

void calculateInterest(const string &name, double percentage, int time) {
    for (auto &it : member) { 
        if (it.second.name == name) {
            double principal = it.second.savings;
            double total = principal * pow(1 + percentage / 100.0, time); 
            cout << "Total amount for " << name << " after " << time << " year(s) is " << total << endl;
            return;
        }
    }
    cout << "There are no data for: " << name << endl;
}