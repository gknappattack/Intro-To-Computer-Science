//
// Created by Gregory Knapp on 3/8/20.
//

#ifndef PREPLAB7_ITEMTOPURCHASE_H
#define PREPLAB7_ITEMTOPURCHASE_H


class ItemToPurchase {
    public:
        ItemToPurchase();
        void SetName(string name);
        string GetName() const;
        void SetPrice(double price);
        double GetPrice() const;
        void SetQuantity(int quantity);
        int GetQuantity() const;
    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
};


#endif //PREPLAB7_ITEMTOPURCHASE_H
