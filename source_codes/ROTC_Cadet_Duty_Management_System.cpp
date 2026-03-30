// ============================================================
// MODIFIED ROTC CADET DUTY MONITORING SYSTEM
// PELAGIO CEDREX Q
// ============================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
// GLOBAL CONSTANTS
const int MAX_CADETS = 50;
const int REQUIRED_HRS = 6;

// FUNCTION PROTOTYPES (declarations so functions can be called)
void inputCadets(string rank[], string name[], int dutyHours[], int &count);
void displayCadets(string rank[], string name[], int dutyHours[], int count);
template<typename T1, typename T2, typename T3>
void bubbleSorting(T1 array_1[], T2 array_2[], T3 array_3[], int count);
void smartSearchRange(string rank[], string name[], int dutyHours[], int count);
void lowDutyReport(string rank[], string name[], int dutyHours[], int count);
void displayMenu();

// MAIN FUNCTION
int main() {
    // Declare 1D arrays to store cadet information
    string rank[MAX_CADETS];      // Stores cadet rank (e.g., C/1LT)
    string name[MAX_CADETS];      // Stores cadet name
    int dutyHours[MAX_CADETS];    // Stores duty hours per cadet

    int count = 0;   // Tracks how many cadets have been entered
    int choice = 0;  // Stores the user's menu selection

    // MAIN MENU LOOP
    do {
        displayMenu();  // Show the menu options
        cout << "Select option: ";
        cin >> choice;
        cin.ignore();   // Clears leftover newline from input buffer

        // Process the user's menu choice
        switch (choice) {
            case 1:
                // Option 1: Input cadet officer duty information
                inputCadets(rank, name, dutyHours, count);
                break;
            case 2:
                // Option 2: Sort and display cadets by duty hours (highest to lowest)
                if (count == 0) {
                    cout << "\n  [!] No cadets entered yet. Please input cadets first.\n";
                } else {
                    bubbleSorting(rank, name, dutyHours, count);
                    displayCadets(rank, name, dutyHours, count);
                }
                break;
            case 3:
                // Option 3: Search cadets within a duty hour range
                if (count == 0) {
                    cout << "\n  [!] No cadets entered yet. Please input cadets first.\n";
                } else {
                    smartSearchRange(rank, name, dutyHours, count);
                }
                break;
            case 4:
                // Option 4: Show cadets with duty hours below the required minimum
                if (count == 0) {
                    cout << "\n  [!] No cadets entered yet. Please input cadets first.\n";
                } else {
                    lowDutyReport(rank, name, dutyHours, count);
                }
                break;
            case 5:
                // Option 5: Exit the program
                cout << "\n  Exiting ROTC Duty Monitoring System. Dismissed!\n";
                cout << "  ================================================\n\n";
                break;
            default:
                // Handle invalid menu input
                cout << "\n  [!] Invalid option. Please enter a number from 1 to 5.\n";
        }
    } while (choice != 5);  // Keep looping until user chooses to exit
    return 0;
}
// FUNCTION: displayMenu()
// Prints the main menu to the screen.
void displayMenu() {
    cout << "\n";
    cout << "  =================================\n";
    cout << "  ROTC CADET DUTY MONITORING SYSTEM\n";
    cout << "  =================================\n";
    cout << "  1. Input Cadet Officer Duty\n";
    cout << "  2. Display Duty Ranking\n";
    cout << "  3. Smart Search (Duty Hour Range)\n";
    cout << "  4. Exercise Penalty Report\n";
    cout << "  5. Exit\n";
    cout << "  ---------------------------------\n";
}
// FUNCTION: inputCadets()
// Asks the user how many cadets to enter, then
// collects the rank, name, and duty hours for each.
void inputCadets(string rank[], string name[], int dutyHours[], int &count) {

    int numToAdd = 0;  // How many new cadets the user wants to add

    cout << "\n  ===== INPUT CADET OFFICER DUTY =====\n";
    cout << "  Current cadets in system: " << count << "\n";
    cout << "  How many cadets do you want to add? ";
    cin >> numToAdd;
    cin.ignore();  // Clear newline from buffer before reading strings

    // Check if adding this many would exceed the array limit
    if (count + numToAdd > MAX_CADETS) {
        cout << "  [!] Cannot add " << numToAdd << " cadets. ";
        cout << "Only " << (MAX_CADETS - count) << " slot(s) remaining.\n";
        numToAdd = MAX_CADETS - count;  // Limit to available slots
    }
    // INPUT LOOP
    // Loop through and collect data for each new cadet.
    // 'count' keeps track of the current position in the arrays.
    for (int i = 0; i < numToAdd; i++) {

        cout << "\n  --- Cadet #" << (count + 1) << " ---\n";

        cout << "  Enter Rank (e.g., C/1LT, C/SSG): ";
        getline(cin, rank[count]);   // getline allows spaces in rank

        cout << "  Enter Name: ";
        getline(cin, name[count]);   // getline allows spaces in name

        cout << "  Enter Duty Hours: ";
        cin >> dutyHours[count];
        cin.ignore();  // Clear newline after reading integer

        count++;  // Move to the next slot in the arrays
    }

    cout << "\n  [/] " << numToAdd << " cadet(s) successfully added.\n";
    cout << "  Total cadets in system: " << count << "\n";
}
// FUNCTION: displayCadets()
// Displays all cadet data in a ranked list format.
// This function is called after sorting.
void displayCadets(string rank[], string name[], int dutyHours[], int count) {

    cout << "\n  ===== DUTY RANKING =====\n";
    // Loop through all cadets and display their information
    for (int i = 0; i < count; i++) {
        // Display: position, rank, name, and duty hours
        cout << "  " << (i + 1) << ". "
             << rank[i] << " " << name[i]
             << " - " << dutyHours[i] << " Hours\n";
    }
    cout << "  ========================\n";
}
// FUNCTION: sortDutyRanking()
// Sorts cadets from HIGHEST to LOWEST duty hours
// using the Bubble Sort algorithm.
template<typename T1, typename T2, typename T3>
void bubbleSorting(T1 array_1[], T2 array_2[], T3 array_3[], int count){
    // After each pass, the smallest value is pushed to the end
    for (int i = 0; i < count - 1; i++) {
        // Inner loop: compares adjacent pairs in the unsorted portion
        for (int j = 0; j < count - 1 - i; j++) {
            // If current cadet has FEWER hours than the next, swap them
            // This ensures higher duty hours come first (descending order)
            if (array_3[j] < array_3[j + 1]) {
                // Swap the 3rd array
                swap(array_3[j],array_3[j + 1]);
                // Swap ranks
                swap(array_2[j],array_2[j + 1]);
                // Swap names
                swap(array_1[j],array_1[j + 1]);
            }
        }
    }
    // After sorting, the arrays are arranged from highest to lowest duty hours
}
// FUNCTION: smartSearchRange()
// Searches for cadets whose duty hours fall within
// a user-specified minimum and maximum range
void smartSearchRange(string rank[], string name[], int dutyHours[], int count) {

    int minHours = 0;  // Lower bound of the search range
    int maxHours = 0;  // Upper bound of the search range
    int found = 0;     // Counter for how many cadets match

    cout << "\n  ===== SMART SEARCH (DUTY HOUR RANGE) =====\n";
    cout << "  Enter MINIMUM duty hours: ";
    cin >> minHours;

    cout << "  Enter MAXIMUM duty hours: ";
    cin >> maxHours;

    // Validate: minimum should not be greater than maximum
    if (minHours > maxHours) {
        cout << "\n  [!] Invalid range. Minimum cannot be greater than maximum.\n";
        return;  // Exit the function early
    }

    cout << "\n  Cadets with duty hours between "
         << minHours << " and " << maxHours << ":\n";
    cout << "  ------------------------------------------\n";
    // SEQUENTIAL SEARCH LOOP
    // Go through each cadet one at a time and check if their
    // duty hours fall within the specified range [minHours, maxHours].
    for (int i = 0; i < count; i++) {
        // Check if this cadet's duty hours are within the range
        if (dutyHours[i] >= minHours && dutyHours[i] <= maxHours) {
            // This cadet matches - display their information
            cout << "  " << rank[i] << " " << name[i]
                 << " - " << dutyHours[i] << " Hours\n";
            found++;  // Count this match
        }
        // If not in range, skip and move to the next cadet
    }
    cout << "  ------------------------------------------\n";
    // Report how many cadets were found in the range
    if (found == 0) {
        cout << "  [!] No cadets found within that duty hour range.\n";
    } else {
        cout << "  Total cadets found: " << found << "\n";
    }
}
// FUNCTION: lowDutyReport()
// Identifies cadets whose duty hours are BELOW the
// required minimum (6 hours) and computes their
// penalty in weeks of exercise.
void lowDutyReport(string rank[], string name[], int dutyHours[], int count) {

    int penaltyCount = 0;    // Tracks how many cadets have penalties
    int weeksExercise = 0;   // Stores computed penalty for each cadet

    cout << "\n  ===== EXERCISE PENALTY REPORT =====\n";
    cout << "  Required Duty Hours: " << REQUIRED_HRS << " Hours\n";
    cout << "  -----------------------------------\n";
    // SEQUENTIAL SEARCH LOOP
    // Check each cadet one by one to see if their duty hours
    // are below the required minimum of 6 hours.
    for (int i = 0; i < count; i++) {
        // Condition: cadet's hours are less than the required 6 hours
        if (dutyHours[i] < REQUIRED_HRS) {
            // Calculate how many weeks of exercise are needed as penalty
            weeksExercise = REQUIRED_HRS - dutyHours[i];
            // Display the cadet's name, hours, and penalty
            cout << "  Cadet " << name[i]
                 << " - " << dutyHours[i] << " Hours\n"
                 << "|  Penalty: " << weeksExercise << " Week";
            // Proper grammar: "Week" vs "Weeks"
            if (weeksExercise > 1) {
                cout << "s";
            }
            cout << " Exercise\n";
            penaltyCount++;  // Count this cadet
        }
    }
    cout << "  -----------------------------------\n";
    // Summary at the end of the report
    if (penaltyCount == 0) {
        cout << "  [/] All cadets have met the required duty hours. No penalties.\n";
    } else {
        cout << "  Total cadets with penalty: " << penaltyCount << "\n";
    }
}
// END OF PROGRAM

