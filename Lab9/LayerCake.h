//
// Created by Gregory Knapp on 4/8/20.
//

#ifndef LAB_9_LAYERCAKE_H
#define LAB_9_LAYERCAKE_H
#include "Cake.h"

class LayerCake : public Cake {
public:
    LayerCake(int layer, string flavor, string frosting);
    string ToString();
    double DiscountedPrice(int quantity);
    double GetPrice();
private:
    int layerNum;
};

#endif //LAB_9_LAYERCAKE_H
