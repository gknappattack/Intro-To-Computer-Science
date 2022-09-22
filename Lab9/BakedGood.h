//
// Created by Gregory Knapp on 4/8/20.
//

#ifndef LAB_9_BAKEDGOOD_H
#define LAB_9_BAKEDGOOD_H
#include <iostream>
#include <string>

using namespace std;

class BakedGood {
public:
    virtual string ToString() = 0;
    virtual double DiscountedPrice(int quantity) = 0;
    virtual double GetPrice() = 0;
protected:
    double basePrice;
};

#endif //LAB_9_BAKEDGOOD_H
