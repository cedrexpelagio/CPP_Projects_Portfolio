#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;
// Max Input
const int MAXSTUD = 100; // Max Student
const int MAXSUB = 100; // Max Subject

// Declaration of Function
void line();
void header();
bool validation(int maxx, int choice);
void inputGrades(double studGrades[][MAXSUB], int numStud, int numSub);
void display(double studGrades[][MAXSUB], int numStud, int numSub);

int main()
{
    // Two Dimensional Array for Student Grades
    double studGrades[MAXSTUD][MAXSUB] = {0};
    int numStud = 0;
    int numSub = 0;
    char loop;
    bool valid = false;

    do {
        header();// Ask the user to input
        do {
            cout << "Enter Number of Students: ";
            cin >> numStud;
            valid = validation(MAXSTUD,numStud);
        } while (valid);

        do {
            cout << "Enter Number of Subjects: ";
            cin >> numSub;
            valid = validation(MAXSUB,numSub);
        } while(valid);

        // User Input Grades for Each Subject
        inputGrades(studGrades, numStud, numSub);
        // Program Display the Student, Grades and Average
        display(studGrades, numStud, numSub);

        do { // Ask the user if they want to try again
            cout << "\nDo you want to try again?(Y/N): ";
            cin >> loop;
            if (loop != 'Y' && loop != 'y' && loop != 'N' && loop != 'n') {
                cout << "Invalid Input, Try Again\n";
                valid = true; // Invalid
            } else {
                valid = false; // Valid
            }
        } while (valid);
    } while (loop == 'Y' || loop == 'y'); // Loop If Y/n

    header();
    cout << "Thank you for using the program!\n";
    return 0;
}

// Initialization of Function
void line()
{
    cout << string(40,'-') << endl;
}

void header()
{
    system("CLS");
    line();
    cout << "   STUDENT GRADE AVERAGE CALCULATOR\n";
    line();
    cout << endl;
}

bool validation(int maxx, int choice)
{

    int mini = 1;

    if (choice > maxx || choice < mini) {
        cout << "Invalid Input [" << mini << "-" << maxx << "] Only!\n";
        return true; // Return if Invalid
    } else {
        return false; // Return if Valid
    }
}

void inputGrades(double studGrades[][MAXSUB], int numStud, int numSub)
{
    bool valid = false;

    for (int rows = 0; rows < numStud; rows++) {
        header(); // User enter grades per student
        cout << "ENTER GRADES FOR STUDENT " << rows + 1 << "\n";
        line();
        for (int cols = 0; cols < numSub; cols++) {
            do {
                cout << "Subject " << cols + 1 << ": ";
                cin >> studGrades[rows][cols];
                if (studGrades[rows][cols] < 0 || studGrades[rows][cols] > 100) {
                    cout << "Invalid grade! Enter 0-100 only.\n";
                    valid = true;
                } else {
                    valid = false;
                }
            } while (valid);

        }
        line();
        cout << "\nPress Enter to Continue...";
        cin.ignore(10000, '\n');
        cin.get();
    }
}

void display(double studGrades[][MAXSUB], int numStud, int numSub)
{
    double total = 0;
    double average = 0;
    cout << fixed << setprecision(2); // Two Decimal Grades

    header(); // Display the table header
    cout << setw(8) << left << "STUDENT";
    for (int cols = 0; cols < numSub; cols++) {
        cout << setw(7) << left << "SUB " + to_string(cols+1);
    }
    cout << "AVERAGE\n\n";

    // Display the grades per student
    for (int rows = 0; rows < numStud; rows++) {
        cout << setw(8) << left << to_string(rows+1);
        for (int cols = 0; cols < numSub; cols++) {
            cout << setw(7) << left << (studGrades[rows][cols]);
            total += studGrades[rows][cols];
        }
        // Compute and Display the Average
        average = total/numSub;
        cout << average << "\n";
        total = 0; // Reset the total
    }
}
