#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const int EMPLOYEES = 5;
const int DAYS = 7;

string getStatus(int status)
{
    if(status == 1) return "P";
    if(status == 2) return "A";
    if(status == 3) return "E";
    return "?";
}

int countPresent (int status)
{
    if(status == 1) return 1;

    return 0;
}

int main()
{
    int total = 0;
    int day = 0;
    int bestTotal = 0;
    double bestAttendance = 0;
    int bestEmployee = 0;
    string status = "";
    // Sample employee names
    string empNames[EMPLOYEES] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

    // 2D array: employees × days
    int attendance[EMPLOYEES][DAYS] = {
        {1, 1, 1, 2, 1, 3, 1},  // Alice
        {1, 1, 1, 1, 1, 1, 1},  // Bob
        {1, 2, 3, 1, 2, 1, 1},  // Charlie
        {1, 1, 1, 1, 1, 2, 3},  // Diana
        {1, 1, 1, 1, 1, 1, 2}   // Eve
    };

    cout << "========= WEEKLY ATTENDANCE REPORT =========\n";
    cout << setw(11) << left << "\nEmployee";

    for (int i = 0; i < DAYS; i ++) {

        cout << setw(5) << left << "Day" + to_string(i + 1);

    }
    cout << setw(6) << left << "Total" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < EMPLOYEES; i++) {

        cout << setw(12) << left << empNames[i];

        for (int j = 0; j < DAYS; j++) {

            status = getStatus(attendance[i][j]);
            cout << setw(5) << left << status;
            total += countPresent(attendance[i][j]);

        }
        cout << setw(5) << left << to_string(total) + "/7" << endl;


        if (total > bestTotal) {
            bestTotal = total;
            bestEmployee = i;
            bestAttendance = (total / 7.0) * 100;  // 7.0 for float
        }


        total = 0;
    }
    cout << "---------------------------------------------------" << endl;

    cout << setw(12) << left << "Day Total:";

    for (int i = 0; i < DAYS; i++) {

        for (int j = 0; j < EMPLOYEES; j++) {

            if (countPresent(attendance[j][i])== 1) {
                day++;
            }
        }
        cout << setw(5) << day;
        day = 0;

    }

    cout << "\n\nBest Attendance: " << empNames [bestEmployee] << " (" << bestAttendance << "%)";

    return 0;
}
