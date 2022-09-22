//
// Created by Gregory Knapp on 4/8/20.
//

#ifndef LAB_9_BREAD_H
#define LAB_9_BREAD_H
#include "BakedGood.h"
#include <string>

class Bread : public BakedGood {
public:
    Bread(string type);
    string ToString();
    double DiscountedPrice(int quantity);
    double GetPrice();
protected:
    string breadType;
};

#endif //LAB_9_BREAD_H
