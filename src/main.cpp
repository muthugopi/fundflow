#include <bits/stdc++.h>
#include <conio.h>
#include "../include/intrest.h"
#include "../include/data_manager.h"
#include "../include/auth/auth.h"
#include "../include/log_controller/log_service.h"
using namespace std;

int main() {
	string name, password;
	cout<<"Enter your username : ";
	cin >> name;
	cout<<"Enter your password : ";

	while(true) {
    char ch = _getch();

    if(ch == 13) { // Enter
        break;
    }
    else if(ch == 8) { // Backspace
        if(password.length() > 0) {
            password.pop_back();
            cout << "\b \b";
        }
    }
    else {
        password.push_back(ch);
        cout << "*";
    }
}

cout << endl;

	

	login(name, password);

	if(isLogined)
		cout<<"Access Granted !"<<endl;

	else 
		exit(0);
	
	system("cls");
	string line;
	start:
	cout << "==============================================" << endl;
	cout << "   Welcome to FundFlow - Finance Manager      " << endl;
	cout << "==============================================" << endl;
	cout << " Manage savings, loans, and interest easily!" << endl;
	cout << "----------------------------------------------" << endl;
	cout << " Type 'help' to see all commands.\n";
	cout<<endl;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
	loadData();
	while(true) {
		string cmd;
		cout<<" FundFlow> ";
		getline(cin, line);
		stringstream ss(line);

		ss >> cmd;
		if (cmd.empty()) continue;
		else if(cmd == "add") {
			string name;
			double amount = 0.0;
			ss >> name >> amount;
			//cout<<"Debugging -> Amount : "<<amount<<" Name : "<<name;
			if(name.empty() || ss.fail())
				cout<<"Correct usage : add [name] [amount]"<<endl;
			else
				addData(name, amount);
		}

		else if(cmd == "save") {
			if(member.size()) {
				saveData();
			}
			else {
				cout<<"there are no data to save!"<<endl;
				warnLog("Tried to save data.txt without data", username);
			}
		}

		else if(cmd == "load") {
			loadData();
		}

		else if(cmd == "update") {
			string name;
			double amount = 0.0;
			ss >> name >> amount;
			if(name.empty() || !amount) {
				cout << "Correct usage : update [name] [amount]"<<endl;
			}
			else {
				updateSaving(name, amount);
				stringstream ss;
			}
		}

		else if(cmd == "show") {
			showData();
		}

		else if(cmd == "showLogs") {
			showLogs();
		}

		else if(cmd == "delete") {
			string n;
			ss >> n;
			stringstream ss;
			ss << "Member " << n << " deleted ";
			addLog(ss.str(), username);
			deleteData(n);
		}

		else if(cmd == "find") {
				string n;
				ss >> n;

				Member *m = findMember(n);
				if(m) {
					cout << "Name        : " << m->name << endl;
					cout << "Savings     : " << m->savings << endl;
					cout << "Loan        : " << m->loan << endl;
					cout << "InterestGiven: " << m->intrestGiven << endl;
				}

				stringstream ss;

	}

		else if(cmd == "calculate") {
			string n;
			int t;
			double p;
			ss>> n >> p >> t;
			if(n.empty() || !t || !p) {
				cout<<"Correct usage : calculate [name] [percentage] [time]";
			}
			else {
				calculateInterest(n, p, t);
			}
		}
		
		else if(cmd == "exit") {
			break;
		}

		else if(cmd == "total") {
			long double total = totalAmount();
			cout<<"Total amount : "<<total<<endl;
			addLog("Calculated total", username);
		}

		else if(cmd == "totalSaving") {
			long double totalSaving = totalSavingAmount();
			cout<<"Total Saving Amount : "<<totalSaving<<endl;
			addLog("Calculated savings amount", username);
		}

		else if(cmd == "totalLoan") {
			long double totalLoan = totalLoanAmount();
			cout << "Total Loan Amount : "<<totalLoan<<endl;
			addLog("Calculated loan amount", username);
		}

		else if(cmd == "giveLoan") {
			string s; long double a;
			ss >> s >> a;
			if(s.empty() || !a) {
				cout<<"Correct Usage : giveLoan [name] [amount]"<<endl;
			}
			else
				giveLoan(s, a);
				stringstream ss;
				ss << "Loan Provied to "<<s;
				addLog(ss.str(), username);
		}

		else if(cmd == "applyIntrest") {
			string n;
			ss >> n;

			applyInterest(n);
			stringstream ss;
			ss << "Intrest applied to "<<n;
			addLog(ss.str(), username);
		}

		else if(cmd == "cls")
			system("cls");

		else if(cmd == "help") {
    cout << "=========== Available Commands ===========\n";

    cout << " add [name] [amount]        -> Add new member with savings\n";
    cout << " update [name] [amount]     -> Update member savings\n";
    cout << " delete [name]              -> Delete member data\n";
    cout << " find [name]                -> Find member details\n";

    cout << "\n save                        -> Save data to file\n";
    cout << " load                        -> Load data from file\n";
    cout << " show                        ->vv   Show all members\n";

    cout << "\n calculate [name] [p] [t]    -> Calculate compound interest\n";
    cout << " applyIntrest [name]         -> Apply interest to member\n";

    cout << "\n giveLoan [name] [amount]    -> Give loan to member\n";
    cout << " total                       -> Show total amount\n";
    cout << " totalSaving                 -> Show total savings\n";
    cout << " totalLoan                   -> Show total loan\n";

	cout << " cls                         ->  Clear the terminal\n";
    cout << "\n exit                        -> Exit the program\n";
    cout << "==========================================" << endl;
}

		// change it before production 0> exit or end
		else {
			cout<<"Unknown Command!"<<endl;
		}
		cout<<endl;

	}
	system("cls");
	cout<<"saving data before leaving the terminal..."<<endl;
	saveData();
	cout<<"thanks for using our terminal!"<<endl;	
	return 0;
}
