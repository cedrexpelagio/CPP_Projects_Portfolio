#include<iostream>
using namespace std;

string gradeToRemarks (int grade) {

    if (grade >= 0 && grade <= 100) {
        if (grade >= 96) return "With Highest Honors";
        else if (grade >= 90) return "With High Honors";
        else if (grade >= 85) return "With Honors";
        else if (grade >= 75) return "Passed";
        else return "Failed";
    }

    return "Invalid Grade";
}

string programMessage (int stud_dep) {

    switch (stud_dep) {
    case 1:
        return "Welcome future IT Specialist!";
    case 2:
        return "Welcome future Engineer!";
    case 3:
        return "Welcome future Hotel Manager!";
    default:
        return "Invalid Department";

    }
}

string programDepartment(int stud_dep) {

    switch (stud_dep) {
    case 1:
        return "BSIT";
    case 2:
        return "BSEE";
    case 3:
        return "BSHM";
    default:
        return "Invalid Department";
    }

}

void systemMenu () {

    int stud_dep = 0;
    int stud_year = 0;
    int grade = 0;

    cout << "----------------------" << endl;
    cout << "Enter Department" << endl;
    cout << "(1-BSIT, 2-BSEE, 3-BSHM): ";
    cin >> stud_dep;
    cout << "Enter Year Level [1-4]: ";
    cin >> stud_year;
    cout << "Enter Grade: ";
    cin >> grade;
    cout << "----------------------" << endl;

    cout << "\n--- STUDENT REPORT ---" << endl;
    cout << "Department: " << programDepartment (stud_dep) << endl;
    cout << "Year Level: " << stud_year << endl;
    cout << "Grade: " << grade << endl;
    cout << "Remark: " << gradeToRemarks (grade) << endl;
    cout << "Message: " << programMessage (stud_dep) << endl;
    cout << "----------------------" << endl;

}

int main()
{
    systemMenu ();
    return 0;
}