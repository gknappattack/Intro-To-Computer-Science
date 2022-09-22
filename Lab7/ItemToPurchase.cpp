//
// Created by Gregory Knapp on 3/9/20.
//

#include <iostream>
#include <iomanip>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.0;
    itemQuantity = 0;
}
ItemToPurchase::ItemToPurchase(string initName, string initDescription, double initPrice, int initQuantity) {
    itemName = initName;
    itemDescription = initDescription;
    itemPrice = initPrice;
    itemQuantity = initQuantity;
}

void ItemToPurchase::SetName(string name){
    itemName = name;
}
string ItemToPurchase::GetName() const {
    return itemName;
}
void ItemToPurchase::SetPrice(double price) {
    itemPrice = price;
}
double ItemToPurchase::GetPrice() const{
    return itemPrice;
}
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}
int ItemToPurchase::GetQuantity() const {
    return itemQuantity;
}
void ItemToPurchase::SetDescription(string description) {
    itemDescription = description;
}
string ItemToPurchase::GetDescription() const {
    return itemDescription;
}
void ItemToPurchase::PrintCost() {
    cout << fixed << setprecision(2) << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity << endl;
}
void ItemToPurchase::PrintDescription() {
    cout << itemName << ": " << itemDescription << endl;
}