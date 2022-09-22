//
// Created by Gregory Knapp on 4/8/20.
//

#include "Cake.h"
#include "LayerCake.h"
using namespace std;

LayerCake::LayerCake(int layer, string flavor, string frosting) {
    layerNum = layer;
    cakeFlavor = flavor;
    cakeFrosting = frosting;

    if (layerNum > 1) {
        if (frosting == "cream-cheese") {
            basePrice = 9.00 + (layer * 1.00) + ((layer - 1) * 3.00);
        }
        else {
            basePrice = 9.00 + ((layer - 1) * 3.00);
        }
    }
    else {
        if (frosting == "cream-cheese") {
            basePrice = 9.00 + (layer * 1.00);
        }
        else {
            basePrice = 9.00;
        }
    }
}
string LayerCake::ToString() {
    string printString;
    printString = to_string(layerNum) + "-layer " + cakeFlavor + " cake with " + cakeFrosting + " frosting ($" + to_string(basePrice) + ")";
    return printString;
}

double LayerCake::DiscountedPrice(int quantity) {
    double discountPrice;

    if (quantity >= 3) {
        discountPrice = 2.00 * quantity;
    }
    else {
        discountPrice = 0.00;
    }

    return discountPrice;
}
double LayerCake::GetPrice() {
    return basePrice;
}
