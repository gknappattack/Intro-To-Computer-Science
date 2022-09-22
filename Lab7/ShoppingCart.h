//
// Created by Gregory Knapp on 3/9/20.
//

#ifndef MAINLAB7_SHOPPINGCART_H
#define MAINLAB7_SHOPPINGCART_H

#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart{
    public:
        //Constructors
        ShoppingCart();
        ShoppingCart(string name, string date);

        //GetInput
        string GetCustomer() const;
        string GetDate() const;

        //CartFunctions
        void AddItem(ItemToPurchase item, vector<ItemToPurchase> &cart);
        void RemoveItem(vector<ItemToPurchase> &cart);
        void UpdateQuantity(vector<ItemToPurchase> &cart);
        int NumberOfItems(vector<ItemToPurchase> &cart);
        double TotalCost(vector<ItemToPurchase> &cart);
        void PrintDescriptions(ShoppingCart thisCart, vector<ItemToPurchase> &cart);
        void PrintCart(ShoppingCart thisCart, vector<ItemToPurchase> &cart);

    private:
        string customerName;
        string cartDate;
        vector<ItemToPurchase> cartObjects;


};


#endif //MAINLAB7_SHOPPINGCART_H
