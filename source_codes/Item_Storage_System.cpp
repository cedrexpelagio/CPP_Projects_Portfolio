#include <iostream>
#include<string>
#include<cstdlib>
#include<iomanip>

using namespace std;

/*
==================================================
PROJECT: Storage System with 2D Array and Structs
DATE: February 17, 2026
AUTHOR: Ced
DESCRIPTION: Inventory management system that tracks
            items across 4 weeks and 7 days using
            2D arrays and nested structs.
==================================================
*/

// ========== CONSTANTS ==========
const int week = 4;          // Total weeks in calendar
const int dayInWeek = 7;     // Days per week
const int days = 28;         // Total days (4×7)
const int items = 100;       // Max items per day

// ========== FUNCTION PROTOTYPES ==========
void lines();                 // Draw separator line
void header();                // Display program header
void toContinue();            // Pause until Enter key
void printMenu();             // Show menu options
int validation(int maximum, string toPrint);  // Get and validate input
void menu();                  // Main menu loop

// ========== STRUCT: ItemNames ==========
// Purpose: Stores names of items for a specific day
struct ItemNames {
    string names[items];      // Array to store item names

    // Input item names from user
    void input (int itemQuantity)
    {
        cout << "NAME OF ITEMS:\n";
        for (int i = 0; i < itemQuantity; i++) {
            cout << "Item " << i + 1 << ": ";
            getline(cin, names[i]);
        }
        lines();
        toContinue();
    }

    // Display stored item names
    void display (int quantity)
    {
        if (quantity == 0) {
            cout << "NO ITEM\n";
        } else {
            cout << "ITEM STORED:\n";
            for (int i = 0; i < quantity; i++) {
                cout << "Item " << i + 1 << ": " << names[i] << endl;
            }
        }
    }
};

// ========== STRUCT: Item ==========
// Purpose: Main inventory structure with calendar and item storage
struct Item {
    // 2D Array: [week][day] stores quantities
    int itemQuantity [week][dayInWeek] = {0};

    int dayIndex;                     // Linear index (0-27) for accessing itemN
    ItemNames itemN[days];            // Array of ItemNames for each day (28 days)

    // Calculate linear index from week and day
    // Formula: (week-1)*7 + (day-1)
    int getDayIndex (int weekI, int dayI)
    {
        if (weekI > 1) {
            dayIndex = ((weekI - 1) * 7) + (dayI - 1);
        } else {
            dayIndex = dayI - 1;
        }
        return dayIndex;
    }

    // Display the 4×7 calendar with quantities
    void calendar ()
    {
        cout << "CALENDAR\n";
        lines();

        // Display day headers
        cout << setw(8) << left << "Weeks:";
        for (int i = 0; i < 7; i++) {
            cout << setw(5) << left << "Day" + to_string(i + 1);
        }
        cout << ":" << endl;
        lines();

        // Display each week row
        for (int i = 0; i < 4; i++) {
            cout << setw(8) << left << "Week" + to_string(i + 1) + ":";

            // Display each day's quantity or "-" if empty
            for (int j = 0; j < 7; j++) {
                cout << setw(5) << left;
                if (itemQuantity[i][j] == 0) {
                    cout << "-";
                } else {
                    cout << itemQuantity[i][j];
                }
            }
            cout << ":" << endl;
        }
        lines();
    }

    // Add new items to a specific day
    void input ()
    {
        int weekI= 0;
        int dayI = 0;
        int quantity = 0;

        cout << "\nSTORE ITEMS\n";
        lines();
        cout << "Enter Item Information:\n";

        // Get validated inputs
        weekI = validation(week,"Week");
        dayI = validation(dayInWeek,"Day");
        itemQuantity[weekI - 1][dayI - 1] = validation(items,"Quantity");
        lines();
        toContinue();

        // Store quantity and get day index for names
        quantity = itemQuantity[weekI - 1][dayI - 1];
        dayIndex = getDayIndex(weekI, dayI);

        // Input item names for this day
        header();
        itemN[dayIndex].input(quantity);

        // Show updated calendar
        header();
        cout << "\nUPDATED ";
        calendar();
    }

    // Display details for a specific day
    void inputToDisplay()
    {
        int dayI = 0;
        int weekI = 0;

        cout << "\nCHECK INVENTORY\n";
        lines();
        cout << "Enter Item Information\n";

        // Get validated inputs
        weekI = validation(week, "Week");
        dayI = validation(dayInWeek, "Day");
        lines();
        toContinue();

        // Display day details
        display(dayI - 1, weekI - 1);
        lines();
    }

    // Display detailed information for a specific day
    void display (int dayI, int weekI)
    {
        int quantity = 0;
        header();

        cout << "\nDAY DETAILS\n";
        lines();
        cout << "Day      : " << dayI + 1 << endl;
        cout << "Week     : " << weekI + 1 << endl;
        cout << "Day Index: " << dayIndex + 1 << endl;
        cout << "Quantity : " << itemQuantity[weekI][dayI] << endl;
        lines();

        // Display item names for this day
        quantity = itemQuantity[weekI][dayI];
        itemN[dayIndex].display(quantity);
    }

    // Clear items from a specific day
    void clearItems ()
    {
        int dayI = 0;
        int weekI = 0;

        cout << "CLEAR ITEMS\n";
        cout << "Enter Item Information:\n";

        // Get validated inputs
        weekI = validation(week,"Week");
        dayI = validation(dayInWeek,"Day");

        // Calculate index and reset quantity to 0
        dayIndex = getDayIndex(weekI, dayI);
        itemQuantity[weekI - 1][dayI - 1] = 0;
        lines();
        toContinue();

        // Show updated calendar
        header();
        cout << "\nUPDATED ";
        calendar();
    }
};

// ========== MAIN FUNCTION ==========
int main()
{
    menu();  // Start the menu system
    return 0;
}

// ========== UI FUNCTIONS ==========

// Draw a horizontal line separator
void lines()
{
    cout << string(44, '-') << endl;
}

// Display program header with title
void header()
{
    system("CLS");
    lines();
    cout << setw(30) << right <<"STORAGE SYSTEM\n";
    cout << setw(35) << right << "USING 2D ARRAY AND STRUCT\n";
    lines();
}

// Pause program and wait for Enter key
void toContinue()
{
    cout << "Press Enter to Continue...";
    cin.ignore();
    cin.get();
}

// Display menu options
void printMenu()
{
    cout << "MENU\n";
    cout << "1. View Calendar\n";
    cout << "2. Add Items\n";
    cout << "3. Check Inventory\n";
    cout << "4. Clear Items\n";
    cout << "5. Exit\n";
}

// ========== VALIDATION FUNCTION ==========
// Purpose: Get and validate user input within range
// Parameters: maximum - max allowed value
//             toPrint - prompt message
// Returns: Validated input value
int validation(int maximum, string toPrint)
{
    const int minimum = 1;
    int choice = 0;

    do {
        cout << toPrint << ": ";
        cin >> choice;

        if (choice > maximum || choice < minimum) {
            cout << "Invalid Try Again!\n" << toPrint << " [" << minimum << "-" << maximum << "].\n";
        } else {
            return choice;  // Return valid input
        }
    } while (choice > maximum || choice < minimum);
    return choice;  // Never reached, but keeps compiler happy
}

// ========== MENU FUNCTION ==========
// Purpose: Main menu loop handling user choices
void menu()
{
    int choice = 0;
    bool yes = true;
    Item item;  // Create inventory system

    do {
        header();           // Clear and show header
        printMenu();        // Show menu options

        // Get validated menu choice (1-5)
        choice = validation(5,"Choice");
        header();           // Clear screen for next display

        // Show calendar for options 1-4
        if (choice <= 4 && choice >= 1) {
            item.calendar();
        }

        // Handle menu choices
        switch (choice) {
        case 2:
            item.input();           // Add items
            break;
        case 3:
            item.inputToDisplay();  // Check inventory
            break;
        case 4:
            item.clearItems();      // Clear items
            break;
        case 5:
            yes = false;            // Exit program
            break;
            // Case 1 just shows calendar (already displayed)
        }

        toContinue();  // Pause before returning to menu
        cout << endl;

    } while (yes);

    // Exit message
    header();
    cout << "\nThank you for using this program!\n";
}
