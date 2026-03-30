#include<iostream>
using namespace std;

    /* Simple Menu Ordering System using switch console.
    It is a hand on quiz that I just remake in my mobile phone.
    
    October 13, 2025
    */
int main()
{
    // Declaration of variables 
    int choice = 0;
    int quantity = 0;
    float total = 0.00;
    string order = "";
    // Choice 1 - 3
    string u_select = "You selected "; 
    string ask_quantity = "Enter Quantity: ";
    // Choice 4
    string thank_u = "Thank you for visiting!";
    // Invalid choice
    string invalid = "Invalid choice. Please try again!";
    
    
    // Input: Asking the user to select a food
    cout << "==============================" << endl;
    cout << "   SIMPLE MENU ORDERING SYSTEM" << endl;
    cout << "==============================" << endl;
    cout << "1 - Burger P80" << endl;
    cout << "2 - Fries  P50" << endl;
    cout << "3 - Soda   P30" << endl;
    cout << "4 - Exit" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice; 
    cout << "------------------------------" << endl;
    
    // Process: Assigning value to burger, quantity and total 
    switch (choice) {
    case 1:
    order = "Burger";
    cout << u_select << order << endl;
    cout << ask_quantity;
    cin >> quantity;
    total = quantity * 80;
    break; 
    case 2:
    order = "Fries";
    cout << u_select << order << endl;
    cout << ask_quantity;
    cin >> quantity;
    total = quantity * 50;
    break; 
    case 3:
    order = "Soda";
    cout << u_select << order << endl;
    cout << ask_quantity;
    cin >> quantity;
    total = quantity * 30;
    break; 
    case 4:
    cout << thank_u << endl;
    break; 
    default: 
    cout << invalid << endl;
    }
    
    // Output: Present the order, quantity and total price to pay
    if (choice >= 1 && choice <= 3) {
    cout << "You ordered " << quantity << " " << order << "(s) Total: P" << total << endl;
    }
    
    // End the program
    cout << "==============================" << endl;
    cout << "Program ended successfully." << endl;
    return 0;
}