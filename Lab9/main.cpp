#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
#include "LayerCake.h"
#include "CupCake.h"
#include "Bread.h"

using namespace std;

int main() {
    string userString = "none";
    int foodQuantity = 0;
    bool orderValue = true;
    int totalCount = 0;
    double totalCost = 0.00;
    vector<BakedGood*> orderList;
    vector<BakedGood*> tempList;

    Bread* breadPtr = nullptr;
    CupCake* cupPtr = nullptr;
    LayerCake* layerPtr = nullptr;

    cout << "** Bread and Cakes Bakery **" << endl;
    cout << "\nEnter sub-order (enter \"done\" to finish)" << endl;

    while (orderValue) {
        cout << "Sub-order: " << endl;
        cin >> userString;

        if (userString == "Bread") {
            string breadType;

            cin >> breadType;
            cin >> foodQuantity;

            for (int i = 0; i < foodQuantity; ++i) {
                breadPtr = new Bread(breadType);
                orderList.push_back(breadPtr);
            }


            bool itemFound = false;

            for (unsigned int i = 0; i < tempList.size(); ++i) {
                if (tempList.at(i)->ToString() == breadPtr->ToString()) {
                    itemFound = true;
                }
            }

            if (itemFound == false) {
                tempList.push_back(breadPtr);
            }

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (userString == "Cupcake"){
            string cupFlavor;
            string cupFrosting;
            string cupColor;

            cin >> cupFlavor;
            cin >> cupFrosting;
            cin >> cupColor;
            cin >> foodQuantity;

            for (int i = 0; i < foodQuantity; ++i) {
                cupPtr = new CupCake(cupColor, cupFlavor, cupFrosting);
                orderList.push_back(cupPtr);
            }

            bool itemFound = false;

            for (unsigned int i = 0; i < tempList.size(); ++i) {
                if (tempList.at(i)->ToString() == cupPtr->ToString()) {
                    itemFound = true;
                }
            }

            if (itemFound == false) {
                tempList.push_back(cupPtr);
            }

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (userString == "Layer-cake") {
            string layerFlavor = "none";
            string layerFrosting = "none";
            int layerCount = 0;

            cin >> layerFlavor;
            cin >> layerFrosting;
            cin >> layerCount;
            cin >> foodQuantity;


            for (int i = 0; i < foodQuantity; ++i) {
                layerPtr = new LayerCake(layerCount, layerFlavor, layerFrosting);
                orderList.push_back(layerPtr);
            }

            bool itemFound = false;

            for (unsigned int i = 0; i < tempList.size(); ++i) {
                if (tempList.at(i)->ToString() == layerPtr->ToString()) {
                    itemFound = true;
                }
            }

            if (itemFound == false) {
                tempList.push_back(layerPtr);
            }

            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if (userString == "done") {
            orderValue = false;
        }
    }

    cout << "\nOrder Confirmations:" << endl;

    for (unsigned int i = 0; i < orderList.size(); ++i) {
        cout << orderList.at(i)->ToString() << endl;
    }

    cout << "\nInvoice:" << endl;
    cout << left << setw(75) << "Baked Good" << right << setw(9) << "Quantity" << setw(9) << "Total" << endl;

    for (unsigned int i = 0; i <tempList.size(); ++i) {
        int goodCount = 0;
        double goodPrice = 0.00;


        for (unsigned int j = 0; j < orderList.size(); ++j) {
            if (tempList.at(i)->ToString() == orderList.at(j)->ToString()) {
                goodCount = goodCount + 1;
                goodPrice = goodPrice + (orderList.at(j)->GetPrice());
            }
        }
        goodPrice = goodPrice - (tempList.at(i)->DiscountedPrice(goodCount));

        totalCount = totalCount + goodCount;
        totalCost = totalCost + goodPrice;

        cout << left << setw(75) << tempList.at(i)->ToString() << right << setw(9) << goodCount << setw(9);
        cout << fixed << setprecision(2) << goodPrice << endl;
    }

    cout << left << setw(75) << "Totals" << right << setw(9) << totalCount << setw(9);
    cout << fixed << setprecision(2) << totalCost << endl;

    cout << "Good Bye" << endl;
    
    return 0;
}
