#include <iostream>
using namespace std;

int main() {

// declaration of variable
  double item_price1, item_price2, item_price3;
  int quantity1, quantity2, quantity3;
  const double tax_rate = 0.12;
  const double discount = 0.10;

// user input for item price and quantity
  cout << "Enter price of item 1   : ";
  cin >> item_price1;
  cout << "Enter quantity of item 1: ";
  cin >> quantity1;
  cout << "Enter price of item 2   : ";
  cin >> item_price2;
  cout << "Enter quantity of item 2: ";
  cin >> quantity2;
  cout << "Enter price of item 3   : ";
  cin >> item_price3;
  cout << "Enter quantity of item 3: ";
  cin >> quantity3;
  cout << endl;

  // computation for subtotal price, discount, tax and total price
  double original_subtotal, subtotal, discounted = 0, tax, total;
  original_subtotal = (item_price1 * quantity1) + (item_price2 * quantity2) + (item_price3 * quantity3);
  bool withDiscount = (original_subtotal >= 500);
  if (withDiscount) {
  discounted = original_subtotal * discount;
  subtotal = original_subtotal - discounted;
  } else {
  subtotal = original_subtotal;
  }
  tax = subtotal * tax_rate;
  total = subtotal + tax;


  // output: diplay the subtotal price, discount, tax and total price
  cout << "------ Bill ------" << endl;
  cout << "Subtotal : " << original_subtotal << endl;
  cout << "Discount : " << discounted << endl;
  cout << "Tax (12%): " << tax << endl;
  cout << "Total.   : " << total << endl;
  cout << "---- Thankyou ----" << endl;

    return 0;
}
