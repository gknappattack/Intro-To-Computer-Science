//
// Created by Gregory Knapp on 3/9/20.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"
#include "ItemToPurchase.h"

ShoppingCart::ShoppingCart() {
    customerName = "none";
    cartDate = "January 1 2016";
}

ShoppingCart::ShoppingCart(string name, string date) {
    customerName = name;
    cartDate = date;
}

string ShoppingCart::GetCustomer() const{
    return customerName;
}

string ShoppingCart::GetDate() const{
    return cartDate;
}

void ShoppingCart::AddItem(ItemToPurchase item, vector<ItemToPurchase> &cart) {
    bool itemFound = false;
    ItemToPurchase compareItem;

    for (unsigned int i = 0; i < cart.size(); ++i) {
        compareItem = cart.at(i);
        if (item.GetName() == compareItem.GetName()) {
            itemFound = true;
            cout << "Item is already found in the cart. It will not be added." << endl;
        }
    }

    if (itemFound == false) {
        cart.push_back(item);
    }
}

void ShoppingCart::RemoveItem(vector<ItemToPurchase> &cart) {
    ItemToPurchase compareItem;
    bool itemRemovedSuccessfully = false;
    string itemToRemove = "none";

    cout << "Enter name of the item to remove: " << endl;
    getline(cin, itemToRemove);

    for (unsigned int i = 0; i < cart.size(); ++i) {
        compareItem = cart.at(i);

        if (compareItem.GetName() == itemToRemove) {
            cart.erase(cart.begin() + i);
            itemRemovedSuccessfully = true;
            break;
        }
    }
    if (itemRemovedSuccessfully == false){
        cout << "Item not found in cart. It will not be removed." << endl;
    }
}

void ShoppingCart::UpdateQuantity(vector<ItemToPurchase> &cart) {
    ItemToPurchase compareItem;
    string itemName;
    int newQuantity;
    bool itemFound = false;

    cout << "Enter the item name: " << endl;
    getline(cin, itemName);
    cout << "Enter the new quantity: " << endl;
    cin >> newQuantity;

    for (unsigned int i = 0; i < cart.size(); ++i) {
        compareItem = cart.at(i);
        if (compareItem.GetName() == itemName) {
            cart.at(i).SetQuantity(newQuantity);
            itemFound = true;
        }
    }
    if (itemFound == false) {
        cout << "Item not found in cart. It will not be modified." << endl;
    }

}

void ShoppingCart::PrintDescriptions(ShoppingCart thisCart, vector<ItemToPurchase> &cart) {
    ItemToPurchase item;

    cout << thisCart.GetCustomer() << "'s Shopping Cart - " << thisCart.GetDate() << endl;

    if (cart.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Item Descriptions" << endl;

        for (unsigned int i = 0; i < cart.size(); ++i) {
            item = cart.at(i);
            item.PrintDescription();
        }
    }
}

int ShoppingCart::NumberOfItems(vector<ItemToPurchase> &cart) {
    int itemNumber = 0;
    ItemToPurchase item;

    for (unsigned int i = 0; i < cart.size(); ++i) {
        item = cart.at(i);
        itemNumber = itemNumber + item.GetQuantity();
    }
    return itemNumber;
}
double ShoppingCart::TotalCost(vector<ItemToPurchase> &cart){
    ItemToPurchase item;
    double itemPrice = 0.00;
    double totalPrice = 0.00;

    for (unsigned int i = 0; i < cart.size(); ++i) {
        item = cart.at(i);
        itemPrice = item.GetPrice() * item.GetQuantity();
        totalPrice = totalPrice + itemPrice;
    }
    return totalPrice;
}

void ShoppingCart::PrintCart(ShoppingCart thisCart, vector<ItemToPurchase> &cart) {
    ItemToPurchase item;

    cout << thisCart.GetCustomer() << "'s Shopping Cart - " << thisCart.GetDate() << endl;

    if (cart.empty()) {
        cout << "Shopping cart is empty." << endl;
    }
    else {
        cout << "Number of items: " << NumberOfItems(cart) << endl;
        cout << endl;

        for (unsigned int i = 0; i < cart.size(); ++i) {
            item = cart.at(i);
            item.PrintCost();
        }

        cout <<"\nTotal: $" << TotalCost(cart) << endl;
    }
}

