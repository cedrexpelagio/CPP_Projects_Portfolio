#include <iostream>
using namespace std;

//Apply most of my learning so far
//Mini project: Improved Simple Calculator
// Nested if

int main () {

    int n1, n2;
    char op;

    cout << "Enter the first number: ";
    cin >> n1;

    cout << "Choose the operation (+,-,/ or *): ";
    cin >> op;

    cout << "Enter the second number: ";
    cin >> n2;

    //Operations

    int sum = n1 + n2;
    int sub = n1 - n2;
    int div = n1 / n2;
    int mul = n1 * n2;
    int mod = n1%n2;

    if (op == '+') {
        cout << "The answer is " << sum << endl;
        } else if (op == '-') {
        cout << "The answer is " << sub << endl;
        } else if (op == '/') {
        cout << "The answer is " << div << endl;
        cout << "Remainder: " << mod << endl;
        } else if (op == '*') {
        cout << "The answer is " << mul << endl;
        } else {
            cout << "sorry, the operation that you chose is not available in the given choices. " << endl;
            }
// Summary

    if (op == '+') {
        cout << "Summary: " << n1 << op << n2 << "=" << sum;
        }
    if (op == '-') {
        cout << "Summary: " << n1 << op << n2 << "=" << sub;
        }
    if (op == '/') {
        cout << "Summary: " << n1 << op << n2 << "=" << div << " Remainder: " << mod;
        }
    if (op == '*') {
        cout << "Summary: " << n1 << op << n2 << "=" << mul;
        }
    return 0;
    }
