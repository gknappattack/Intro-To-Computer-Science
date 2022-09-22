//
// Created by Gregory Knapp on 4/8/20.
//

#ifndef LAB_9_CAKE_H
#define LAB_9_CAKE_H
#include "BakedGood.h"
#include <string>

class Cake : public BakedGood {
public:
    virtual string ToString() = 0;
    virtual double DiscountedPrice(int quantity) = 0;
    virtual double GetPrice() = 0;
protected:
    string cakeFlavor;
    string cakeFrosting;
};

#endif //LAB_9_CAKE_H
