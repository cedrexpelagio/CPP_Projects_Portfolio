#include<iostream>
#include<string>
#include<limits>
using namespace std;

// Process: Assigning Value to Remark using function
string getRemark(int score) {
    if (score >= 90 && score <= 100) {
        return "Excellent";
    } else if (score >= 75 && score <= 89) {
        return "Passed";
    } else if (score >= 0 && score <= 74) {
        return "Failed";
    } else {
        return "Invalid Grade";
    }
}
/* Input and Process: Taking the user input
and assigning value to passed and failed
*/
void quizSystem () {
    int stud_num = 0;
    int score = 0;
    string stud_name = "";
    string remark = "";
    int passed = 0;
    int failed = 0;

    cout << "\nHow many student? ";
    cin >> stud_num;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < stud_num; i++) {
        cout << "\nEnter name: ";
        getline (cin, stud_name);
        cout << "Enter score: ";
        cin >> score;
        remark = getRemark(score);
        cout << "Remark: " << remark << endl;
        cout << "---------------------------------------" << endl;

        if (remark == "Excellent" || remark == "Passed") {
            passed += 1;
        } else if (remark == "Failed") {
            failed += 1;
        }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }

    cout << "Total Passed: " << passed << endl;
    cout << "Total Failed: " << failed << endl;
    cout << "---------------------------------------" << endl;

}

// Output: Using calling a function to display the values
int main()
{
    char yes_no;
    cout << "--------- Student Quiz System ---------" << endl;
    do {
    quizSystem ();
    cout << endl;
    do {
    cout << "Do you want to enter again? (Y/N): ";
    cin >> yes_no;
    } while (yes_no != 'Y' && yes_no != 'y' && yes_no != 'N' && yes_no != 'n');
    
    } while (yes_no == 'Y' || yes_no == 'y');
    cout << "---------------------------------------" << endl;
    cout << "\nThank you for using this program!" << endl;
    return 0;
}