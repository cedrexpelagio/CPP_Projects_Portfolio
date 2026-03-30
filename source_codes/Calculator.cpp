#include <iostream>

using namespace std;

// Operation Template
template<typename T>
T getSum (T elements[], int numElement);
template<typename T>
T getSub (T elements[], int numElement);
template<typename T>
T getMul (T elements[], int numElement);
template<typename T>
T getDiv (T elements[], int numElement);

// Function Prototypes
int validateChoice(int minimum, int maximum);
void menuDataType();
void accessDataType(int dataType, int numElement);

template<typename T>
void enterElement(T arr[], int numElement);
void menuOperation();
template<typename T>
void accessOperation(T elements[], int numElement);

int main()
{
    int dataType = 0;
    int numElement = 0;
    int yes_no = 0;

    do {
    menuDataType(); // 1st Menu
    dataType = validateChoice(1,3);

    cout << "\nEnter number of element: ";
    cin >> numElement;

    accessDataType(dataType, numElement);

    cout << "Try Again?[1 = Yes|2 = No]\n";
    yes_no = validateChoice(1,2);
    } while(yes_no == 1);

    cout << "\nThank you for using the program!";
    return 0;
}

template<typename T>
T getSum (T elements[], int numElement)
{
    T total  = 0;

    for (int i = 0; i < numElement; i++) {
        total += elements[i];
    }

    return total;
}

template<typename T>
T getSub (T elements[], int numElement)
{
    T total  = elements[0];
    for (int i = 0; i < numElement; i++) {
        if (i + 1 == numElement) {
            return total ;
        }
        total -= elements[i+1];
    }
    return total;
}

template<typename T>
T getMul (T elements[], int numElement)
{
    T total  = 1;
    for (int i = 0; i < numElement; i++) {
        total *= elements[i];
    }
    return total;
}

template<typename T>
T getDiv (T elements[], int numElement)
{
    T total  = elements[0];
    for (int i = 0; i < numElement; i++) {
        if (i + 1 == numElement) {
            return total ;
        }
        if (elements[i+1] == 0) {
            cout << "\nError! Division by zero." << endl;
            return 404;
        }

        total /= elements[i+1];
    }
    return total;
}

int validateChoice(int minimum, int maximum)
{
    int choice = 0;
    do {
        cout << "Enter choice: ";
        cin >> choice;
        if (choice < minimum || choice > maximum) {
            cout << "Invalid. Try Again!\n";
        }
    } while (choice < minimum || choice > maximum);
    return choice;
}

void menuDataType()
{
    cout << "\nSelect Data Type:\n";
    cout << "1. Integer\n";
    cout << "2. Float\n";
    cout << "3. Double\n";
}

void accessDataType(int dataType, int numElement)
{
    int intNum[numElement] = {0};
    float floNum[numElement] = {0.00};
    double douNum[numElement] = {0.00};

    switch(dataType) {
    case 1:
        accessOperation(intNum, numElement);
        break;
    case 2:
        accessOperation(floNum, numElement);
        break;
    case 3:
        accessOperation(douNum, numElement);
        break;
    }
}

template<typename T>
void enterElement(T arr[], int numElement)
{
    cout << "Enter elements: ";
    for (int i = 0; i < numElement; i++) {
        cin >> arr[i];
    }
}

void menuOperation()
{
    cout << "\nChoose Operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
}

template<typename T>
void accessOperation(T elements[], int numElement)
{
    T result = 0;
    int operation = 0;

    enterElement(elements, numElement); // User Enter the Elements

    menuOperation(); // 2nd Menu
    operation = validateChoice(1,4);

    switch (operation) {
    case 1:
        result = getSum(elements, numElement);
        break;
    case 2:
        result = getSub(elements, numElement);
        break;
    case 3:
        result = getMul(elements, numElement);
        break;
    case 4:
        result = getDiv(elements, numElement);
        break;
    }

    cout << "\nResult: " << result << endl;

}
