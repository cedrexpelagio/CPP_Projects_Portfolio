#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>

using namespace std;
const int MAX_TYPE_EXPENSES = 10; // Maximum number of expense categories

// FUNCTION PROTOTYPES
void pressToContinue();
void displayHeader(string title);
void displayMenu();
int inputTypeOfExpenses(string typeOfExpense[]);
// Function Template
template <typename T1, typename T2, typename T3>
void bubbleSorting(T1 arr1[], T2 arr2[], T3 target_arr[], int numberOfLoop);
// Function Overloading
void organizeBudget(string typesOfExpense[], double suggestExpenses[], double& weeklyBudget, int& numExpenses);
double organizeBudget(string typesOfExpense[], double suggestExpenses[], int& numExpenses);
void displayDailyBudget(string typesOfExpense[], double suggestExpenses[], int numExpenses, double weeklyBudget, int& day);
void inputDailyExpense(string typesOfExpense[], double suggestExpenses[], int numExpenses, int& day);
int accessFeatures(int choice, bool& organized, double suggestExpenses[], string typesOfExpense[], double& weeklyBudget, int& numExpenses, int& day);

int main()
{
    int exit = 0;
    int day = 7;
    // Arrays to store expense categories and suggested amounts
    double suggestExpenses[MAX_TYPE_EXPENSES] = {0};
    string typesOfExpense[MAX_TYPE_EXPENSES];
    double weeklyBudget = 0;
    int numExpenses = 0;
    bool organized = false; // Tracks if budget is already organized

    // Keep showing menu until user exits
    do {
        int choice = 0;
        system("CLS");
        displayMenu();
        do {
            cout << "Enter Choice: ";
            cin >> choice;
            if (choice < 1 || choice > 5) {
                cout << "[!] Invalid Choice, [1-5] Only\n";
            }
        } while (choice < 1 || choice > 5);
        pressToContinue();
        exit = accessFeatures(choice, organized, suggestExpenses, typesOfExpense, weeklyBudget, numExpenses, day);
    } while (exit == 0);

    return 0;
}
void pressToContinue()
{
    cout << "\nPress Enter to Continue...";
    cin.ignore();
    cin.get();
    system("CLS");
}
// Displays a centered title with border
void displayHeader(string title)
{
    int borderWidth = 33;                        // Total width of the border
    int titleLength = title.length();            // Length of the title text
    int spaces = (borderWidth - titleLength) / 2; // Spaces needed to center title

    cout << string(borderWidth, '=') << "\n";
    cout << string(spaces, ' ') << title << "\n";
    cout << string(borderWidth, '=') << "\n";
}
// Displays the main menu options
void displayMenu()
{
    cout << "\n";
    displayHeader("SmartSpend");
    cout << "1. Organize by Percentage\n";
    cout << "2. Organize by Amount\n";
    cout << "3. Display Estimated Daily Budget\n";
    cout << "4. Input Expenses for the Day\n";
    cout << "5. Exit\n";
    cout << "---------------------------------\n";
}

// Asks user to enter expense category names, returns count
int inputTypeOfExpenses(string typesOfExpense[])
{
    int numExpenses = 0;
    do {
        cout << "How many weekly expenses? [1-" << MAX_TYPE_EXPENSES << "]: ";
        cin >> numExpenses;
        if (numExpenses < 1 || numExpenses > MAX_TYPE_EXPENSES) {
            cout << "[!] Invalid Input, [1-" << MAX_TYPE_EXPENSES << "] Only\n";
        }
    } while (numExpenses < 1 || numExpenses > MAX_TYPE_EXPENSES);

    cout << "Weekly Expense:\nCapital First(e.g., Food)\n";
    cin.ignore();
    for (int i = 0; i < numExpenses; i++) {
        cout << i + 1 << ". ";
        getline(cin, typesOfExpense[i]);
    }
    return numExpenses;
}

// Sorts arr[] based on target_arr[] order (descending)
// T1 and T2 follows the sort, T2 drives the sort
template <typename T1, typename T2, typename T3>
void bubbleSorting(T1 arr1[], T2 arr2[], T3 target_arr[], int numberOfLoop)
{
    for (int i = 0; i < numberOfLoop - 1; i++) {
        for (int j = 0; j < numberOfLoop - 1 - i; j++) {
            if (target_arr[j] < target_arr[j + 1]) {
                swap(target_arr[j], target_arr[j+1]);
                swap(arr1[j], arr1[j+1]);
                swap(arr2[j], arr2[j+1]);
            }
        }
    }
}
// Case 1: Organizes budget by letting user assign percentages per expense
void organizeBudget(string typesOfExpense[], double suggestExpenses[], double& weeklyBudget, int& numExpenses)
{
    double maxPercent = 100;
    double percentage[MAX_TYPE_EXPENSES] = {0};
    cout << "Budget for the Week: ";
    cin >> weeklyBudget;
    numExpenses = inputTypeOfExpenses(typesOfExpense);

    // Handle single expense edge case
    if (numExpenses == 1) {
        pressToContinue();
        displayHeader("ORGANIZE BY PERCENTAGE");
        cout << typesOfExpense[0] << " [0%-100%]: 100\n";
        percentage[0] = 100;
        suggestExpenses[0] = weeklyBudget;
    } else {
        pressToContinue();
        displayHeader("ORGANIZE BY PERCENTAGE");
    }
         for (int i = 0; i < numExpenses - 1; i++) {
        // Keep asking until valid percentage is entered
        do {
            cout << typesOfExpense[i] << " [0%-" << maxPercent << "%]: ";
            cin >> percentage[i];

            if (percentage[i] < 0 || percentage[i] > maxPercent) {
                cout << "[!] Invalid Input, [0%-" << maxPercent << "%] Only\n";
            } else if (percentage[i] == maxPercent) {
                cout << "[!] Save some percentage\nfor remaining expenses!\n";
            }

        } while (percentage[i] >= maxPercent || percentage[i] < 0);

        maxPercent -= percentage[i]; // Reduce remaining percentage
        suggestExpenses[i] = (percentage[i]/100) * weeklyBudget;

        if (i == numExpenses - 2) {  // Auto-fill last expense with remaining percentage
            cout << typesOfExpense[i + 1] << " [0%-" << maxPercent << "%]: " << maxPercent << endl;
            percentage[i+1] = maxPercent;
            suggestExpenses[i+1] = (percentage[i+1]/100) * weeklyBudget;
        }
    }
    pressToContinue();
    displayHeader("ORGANIZE BY PERCENTAGE");
    // Sort by highest amount before displaying
    bubbleSorting(percentage, typesOfExpense, suggestExpenses, numExpenses);
    cout << "\n=== Suggested Weekly Expenses ===\n";
    for (int i = 0; i < numExpenses; i++) {
        cout << typesOfExpense[i] << " [" << percentage[i] << "%]: " << suggestExpenses[i] << endl;
    }
}

// Case 2: Organizes budget by letting user enter actual amounts
// Returns computed total as weekly budget
double organizeBudget(string typesOfExpense[], double suggestExpenses[], int& numExpenses)
{
    double weeklyBudget = 0;
    double percentage[MAX_TYPE_EXPENSES] = {0};
    double amount[MAX_TYPE_EXPENSES] = {0};
    numExpenses = inputTypeOfExpenses(typesOfExpense);

    pressToContinue();
    displayHeader("ORGANIZE BY AMOUNT");
    for (int i = 0; i < numExpenses; i++) {
        cout << typesOfExpense[i] << ": ";
        cin >> amount[i];
        suggestExpenses[i] = amount[i];
        weeklyBudget += amount[i]; // Accumulate total budget
    }
    pressToContinue();
    displayHeader("ORGANIZE BY AMOUNT");
    // Sort by highest amount before displaying
    bubbleSorting(percentage, typesOfExpense, suggestExpenses, numExpenses);
    cout << "\n=== Weekly Expenses Plan ===\n";
    cout << "Budget for the Week: " << weeklyBudget << endl;
    cout << fixed << setprecision(2);
    for (int i = 0; i < numExpenses; i++) {
        percentage[i] = (suggestExpenses[i] / weeklyBudget) * 100;
        cout << typesOfExpense[i] << " [" << percentage[i] << "%]: " << suggestExpenses[i] << endl;

    }
    return weeklyBudget;
}
// Case 3: Displays estimated daily budget per expense (weekly / 7)
void displayDailyBudget(string typesOfExpense[], double suggestExpenses[], int numExpenses, double weeklyBudget, int& day)
{
    displayHeader("ESTIMATED DAILY EXPENSE");
    cout << "Remaining Day: " << day << endl;
    if (day == 0) {
    cout << "[!] No remaining days this week.\n";
    return;
    }
    double percentage[MAX_TYPE_EXPENSES] = {0};
    cout << fixed << setprecision(2);
    for (int i = 0; i < numExpenses; i++) {
        percentage[i] = (suggestExpenses[i]/weeklyBudget) * 100;
        cout << typesOfExpense[i] << " [" << percentage[i] << "%]: " << suggestExpenses[i]/day << endl;
    }
}

// Case 4: Records actual daily spending and shows remaining weekly budget
void inputDailyExpense(string typesOfExpense[], double suggestExpenses[], int numExpenses, int& day)
{
    double dailyExpense[MAX_TYPE_EXPENSES] = {0};
    double remainingBudget[MAX_TYPE_EXPENSES] = {0};
    displayHeader("INPUT EXPENSES FOR THE DAY");
    cout << "Remaining Day: " << day << endl;
    if (day == 0) {
    cout << "[!] No remaining days this week.\n";
    return;
    }
    cout << fixed << setprecision(2);

    for (int i = 0; i < numExpenses; i++) {
        double dailyLimit = suggestExpenses[i] / day; // Compute daily limit per category

        cout << typesOfExpense[i] << " (Daily Limit: " << dailyLimit << "): ";
        cin >> dailyExpense[i];

        remainingBudget[i] = suggestExpenses[i] - dailyExpense[i];
        suggestExpenses[i] = remainingBudget[i];
        // Warn user if they exceeded their daily limit
        if (dailyExpense[i] > dailyLimit) {
            cout << "[!] Warning: Exceeded daily limit by " << dailyExpense[i] - dailyLimit << "!\n";
        }
    }
    bubbleSorting(typesOfExpense, suggestExpenses, remainingBudget, numExpenses);
    pressToContinue();
    displayHeader("INPUT EXPENSES FOR THE DAY");
    cout << "\n=== Remaining Weekly Budget ===\n";
    for (int i = 0; i < numExpenses; i++) {
        if (remainingBudget[i] < 0) {
            // Negative means over budget
            cout << typesOfExpense[i] << ": " << remainingBudget[i] << " [!] Over Budget!\n";
        } else {
            cout << typesOfExpense[i] << ": " << remainingBudget[i] << " remaining\n";
        }
    }
    day--;
}
// Routes menu choice to the correct feature
int accessFeatures(int choice, bool& organized, double suggestExpenses[], string typesOfExpense[], double& weeklyBudget, int& numExpenses, int& day)
{
    switch(choice) {
    case 1:
        displayHeader("ORGANIZE BY PERCENTAGE");
        if (organized) {
            cout << "\n[!] Already Organized\n";
        } else {
            organizeBudget(typesOfExpense, suggestExpenses, weeklyBudget, numExpenses);
            organized = true;
        }
        pressToContinue();
        break;
    case 2:
        displayHeader("ORGANIZE BY AMOUNT");
        if (organized) {
            cout << "\n[!] Already Organized\n";
        } else {
            weeklyBudget = organizeBudget(typesOfExpense, suggestExpenses, numExpenses);
            organized = true;
        }
        pressToContinue();
        break;
    case 3:
        if (!organized) {
            cout << "\n[!] Please organize your budget first.\n";
        } else {
            displayDailyBudget(typesOfExpense, suggestExpenses, numExpenses, weeklyBudget,day);
        }
        pressToContinue();
        break;
    case 4:
        if (!organized) {
            cout << "\n[!] Please organize your budget first.\n";
        } else {
            inputDailyExpense(typesOfExpense, suggestExpenses, numExpenses, day);
        }
        pressToContinue();
        break;
    case 5:
        displayHeader("SmartSpend");
        cout << "\nThank your for using SmartSpend!\n";
        return 5; // Signal main loop to exit
        break;
    }
    return 0; // Signal main loop to continue
}
