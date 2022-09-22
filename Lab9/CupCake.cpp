//
// Created by Gregory Knapp on 4/8/20.
//

#include "Cake.h"
#include "CupCake.h"
using namespace std;

CupCake::CupCake(string color, string flavor, string frosting) {
    sprinkleColor = color;
    cakeFlavor = flavor;
    cakeFrosting = frosting;

    if (frosting == "cream-cheese") {
        basePrice = 1.95 + .20;
    }
    else {
        basePrice = 1.95;
    }

}
string CupCake::ToString() {
    string printString;
    printString = cakeFlavor + " cupcake with " + cakeFrosting + " frosting and " + sprinkleColor + " sprinkles ($" + to_string(basePrice) + ")";

    return printString;
}

double CupCake::DiscountedPrice(int quantity) {
    double discountPrice;

    if (quantity < 4 && quantity > 1) {
        discountPrice = .30 * quantity;
    }
    else if (quantity >= 4) {
        discountPrice = .40 * quantity;
    }
    else {
        discountPrice = 0.00;
    }

    return discountPrice;
}
double CupCake::GetPrice() {
    return basePrice;
}