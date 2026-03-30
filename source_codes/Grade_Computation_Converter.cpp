#include<iostream>
using namespace std;


int main()
{
    char ans;
    do {
        //  Input
        string f_n, l_n, remark;
        int grades[8], grade;
        string subjects [8] {"Filipino ", "English", "Math", "Science", "Araling Panlipunan", "T.L.E", "E.S.P", "MAPEH"};
        cout << "STUDENT GRADE" << endl;
        cout << "-----------------------------" << endl;
        cout << "First name : ";
        cin >> f_n;
        cout << "Last name  : ";
        cin >> l_n;
        cout << "-----------------------------" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "Enter grade in " << subjects [i] << ": ";
            cin >> grades[i];
        }
        cout << "Grades Entered: ";
        for (int i = 0; i < 8; i++) {
            cout << grades[i] << " ";
        }
        // Grade computation of avarage
        grade = grades [0] + grades [1] + grades [2] + grades [3] + grades [4] + grades [5] + grades [6] + grades [7];
        grade /= 8;
        char letter;

        // decision making - remarks
        if (grade >= 96 && grade <=100) {
            remark = "With Highest Honors";
        } else if (grade >= 90) {
            remark = "With High Honors";
        } else if (grade >= 85) {
            remark = "With Honors";
        } else if (grade >= 75) {
            remark = "Passed";
        } else if (grade >= 0) {
            remark = "Failed";
        } else {
            remark = "Invalid";
            letter = '-';
        }

        // decision making - letter
        int pre_letter = grade/10;
        switch (pre_letter) {
        case 10:
        case 9:
            letter = 'A';
            break;
        case 8:
            letter = 'B';
            break;
        case 7:
            letter = 'C';
            break;
        case 6:
            letter = 'D';
            break;
        default:
            letter = 'F';
        }

        // output
        cout << "\nSTUDENT FINAL GRADE REPORT" << endl;
        cout << "-----------------------------" << endl;
        cout << "Name    : " << f_n << " " << l_n << endl;
        cout << "Grade   : " << grade << endl;
        cout << "Remark  : " << remark << endl;
        cout << "Letter  : " << letter << endl;

        // do while
        do {
            cout << "\nDo you want to enter another student? (Y/N): ";
            cin >> ans;
            if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n') {
                cout << "Invalid input. Please enter only Y or N.\n";
            }
        } while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');

    } while (ans == 'Y' || ans == 'y');

    cout << "\nExiting... Thank you for using the Grade Checker!";

    return 0;
}
