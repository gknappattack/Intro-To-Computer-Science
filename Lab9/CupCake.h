//
// Created by Gregory Knapp on 4/8/20.
//

#ifndef LAB_9_CUPCAKE_H
#define LAB_9_CUPCAKE_H
#include "Cake.h"
#include <string>

class CupCake : public Cake {
public:
    CupCake(string color, string flavor, string frosting);
    string ToString();
    double DiscountedPrice(int quantity);
    double GetPrice();
private:
    string sprinkleColor;
};

#endif //LAB_9_CUPCAKE_H
