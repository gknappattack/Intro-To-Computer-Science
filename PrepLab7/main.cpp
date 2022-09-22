#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

int main() {
    ItemToPurchase Item1;
    ItemToPurchase Item2;
    string productName;
    double productPrice = 0.0;
    double productPrice2 = 0.0;
    int productQuantity = 0;
    int productQuantity2 = 0;

    cout << "Item 1" << endl;

    cout << "Enter the item name: " << endl;
    getline(cin, productName);
    cout << "Enter the item price: " << endl;
    cin >> fixed >> setprecision(2) >> productPrice;
    cout << "Enter the item quantity: " << endl;
    cin >> productQuantity;

    Item1.SetName(productName);
    Item1.SetPrice(productPrice);
    Item1.SetQuantity(productQuantity);

    cin.ignore();

    cout << "Item 2" << endl;


    cout << "Enter the item name: " << endl;
    getline(cin, productName);
    cout << "Enter the item price: " << endl;
    cin >> fixed >> setprecision(2) >> productPrice2;
    cout << "Enter the item quantity: " << endl;
    cin >> productQuantity2;

    Item2.SetName(productName);
    Item2.SetPrice(productPrice2);
    Item2.SetQuantity(productQuantity2);

    cout << "TOTAL COST" << endl;
    cout << Item1.GetName();
    cout << " ";
    cout << Item1.GetQuantity();
    cout << " @ $";
    cout << fixed << setprecision(2) << Item1.GetPrice();
    cout << " = $";
    cout << fixed << setprecision(2) << productPrice * productQuantity;
    cout << endl;

    cout << Item2.GetName();
    cout << " ";
    cout << Item2.GetQuantity();
    cout << " @ $";
    cout << fixed << setprecision(2) << Item2.GetPrice();
    cout << " = $";
    cout << fixed << setprecision(2) << productPrice2 * productQuantity2;
    cout << endl;

    cout << "\nTotal: $" << fixed << setprecision(2) <<  (productPrice * productQuantity) + (productPrice2 * productQuantity2) << endl;


    return 0;
}
