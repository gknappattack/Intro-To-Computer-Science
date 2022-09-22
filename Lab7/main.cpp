#include <iostream>
#include <string>
#include <utility>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

ItemToPurchase CreateItem() {
    string itemName;
    string itemDescription;
    double itemPrice;
    int itemQuantity;
    cout << "Enter the item name: " << endl;
    getline(cin, itemName);
    cout << "Enter the item description: " << endl;
    getline(cin, itemDescription);
    cout <<  "Enter the item price: " << endl;
    cin >> itemPrice;
    cout << "Enter the item quantity: " << endl;
    cin >> itemQuantity;

    cin.ignore(80, '\n');

    ItemToPurchase newItem(itemName, itemDescription, itemPrice, itemQuantity);
    return newItem;
}

void AddMenuOption(vector<ItemToPurchase>& cart) {
    ItemToPurchase itemToAdd = CreateItem();
    ShoppingCart().AddItem(itemToAdd, cart);
}

void RemoveMenuOption(vector<ItemToPurchase>& cart) {
    ShoppingCart().RemoveItem(cart);
}

void ChangeMenuOption(vector<ItemToPurchase>& cart) {
    ShoppingCart().UpdateQuantity(cart);
    cin.ignore(80,'\n');
}

void DescriptionsMenuOption(ShoppingCart thisCart, vector<ItemToPurchase> &cart) {
    ShoppingCart().PrintDescriptions(std::move(thisCart), cart);
}

void CartMenuOption(ShoppingCart thisCart, vector<ItemToPurchase> &cart) {
    ShoppingCart().PrintCart(std::move(thisCart), cart);
}

void QuitMenuOption() {
    cout << "Goodbye." << std::endl;
}

int main() {
    vector<ItemToPurchase> currentCart;
    string customerName;
    string todayDate;

    cout << "Enter Customer's Name: " << endl;
    getline(cin, customerName);
    cout << "Enter Today's Date: " << endl;
    getline(cin, todayDate);

    ShoppingCart userCart(customerName, todayDate);

    string userMenuChoice = "none";
    bool continueMenuLoop = true;


    while (continueMenuLoop) {
        cout << "Enter Option: " << endl;
        getline(cin, userMenuChoice);

        if (userMenuChoice == "add") {
            AddMenuOption(currentCart);
        }
        else if (userMenuChoice == "remove") {
            RemoveMenuOption(currentCart);
        }
        else if (userMenuChoice == "change") {
            ChangeMenuOption(currentCart);
        }
        else if (userMenuChoice == "descriptions") {
            DescriptionsMenuOption(userCart, currentCart);
        }
        else if (userMenuChoice == "cart") {
            CartMenuOption(userCart, currentCart);
        }
        else if (userMenuChoice == "options") {
            cout << "MENU" << endl;
            cout << "add - Add item to cart" << endl;
            cout << "remove - Remove item from cart" << endl;
            cout << "change - Change item quantity" << endl;
            cout << "descriptions - Print the items' descriptions" << endl;
            cout << "cart - Print the shopping cart" << endl;
            cout << "options - Print the options menu" << endl;
            cout << "quit - Quit" << endl;
            cout << endl;
        }
        else if (userMenuChoice == "quit") {
            QuitMenuOption();
            continueMenuLoop = false;
        }
        else {
            cout << "MENU" << endl;
            cout << "add - Add item to cart" << endl;
            cout << "remove - Remove item from cart" << endl;
            cout << "change - Change item quantity" << endl;
            cout << "descriptions - Print the items' descriptions" << endl;
            cout << "cart - Print the shopping cart" << endl;
            cout << "options - Print the options menu" << endl;
            cout << "quit - Quit" << endl;
            cout << endl;
        }
        cin.clear();
    }


    return 0;
}