#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    // Declaration of variables
    double weekly;
    double food, transpo, project, save;
    // Input
    cout << "------------------------------" << endl; 
    cout << "STUDENT'S BUDGETING BUDDY" << endl;
    cout << "Enter weekly allowance: PHP ";
    cin >> weekly;
    // Process
    food = (weekly * 0.4)/7;
    transpo = (weekly * 0.3)/7;
    project = (weekly * 0.2)/7;
    save = (weekly * 0.1)/7;
    double total = food + transpo + project + save;
    cout << fixed << setprecision(2);
    // Output
    cout << "------------------------------" << endl;
    cout << "DAILY BUDGET RECOMMENDATIONS" << endl;
    cout << "Food           (40%): PHP " << food << endl;
    cout << "Transportation (30%): PHP " << transpo << endl;
    cout << "School Projects(20%): PHP " << project << endl;
    cout << "Emergency Fund (10%): PHP " << save << endl;
    cout << "Total Daily Expenses: PHP " << total << endl;
    cout << "------------------------------" << endl;
    
    return 0;
}