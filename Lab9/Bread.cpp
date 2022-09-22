//
// Created by Gregory Knapp on 4/8/20.
//

#include "Bread.h"
using namespace std;

Bread::Bread(string type) {
    breadType = type;
    basePrice = 4.50;
}
string Bread::ToString() {
    string printString;

    printString = breadType + " bread ($" + to_string(basePrice) + ")";
    return printString;
}
double Bread::DiscountedPrice(int quantity) {
    double discountPrice;
    int freeBread = 0;

    freeBread = quantity / 3;
    discountPrice = (basePrice * freeBread);

    return discountPrice;
}
double Bread::GetPrice() {
    return basePrice;
}