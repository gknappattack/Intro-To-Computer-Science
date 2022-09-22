//
// Created by Gregory Knapp on 3/9/20.
//

#ifndef MAINLAB7_ITEMTOPURCHASE_H
#define MAINLAB7_ITEMTOPURCHASE_H


class ItemToPurchase {
    public:
        //Constructorss
        ItemToPurchase();
        ItemToPurchase(string initName, string initDescription, double initPrice, int initQuantity);

        //Creating & Retrieving item info
        void SetName(string name);
        string GetName() const;
        void SetPrice(double price);
        double GetPrice() const;
        void SetQuantity(int quantity);
        int GetQuantity() const;
        void SetDescription(string description);
        string GetDescription() const;

        //Print Info
        void PrintCost();
        void PrintDescription();
    private:
        string itemName;
        double itemPrice;
        int itemQuantity;
        string itemDescription;
};

#endif //MAINLAB7_ITEMTOPURCHASE_H
