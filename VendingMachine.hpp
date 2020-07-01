
//
//  VendingMachine.hpp
//  test_gtest_2
//
//  Created by Kyle Griffin on 6/8/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#ifndef VendingMachine_hpp
#define VendingMachine_hpp
#include <string.h>
#include <stdio.h>
#include "Item.hpp"

#define VALUE = 3

using namespace std;

class ItemAndQuantity {
public:
    ItemAndQuantity(Item item, int quantity);
    ~ItemAndQuantity();
    Item item;
    int quantity;
};

class VendingMachine {
public:
    VendingMachine();  // initialize with empty array of snacks and 0 balance
    ~VendingMachine();
    int countSelections();
    string seeSelections();     // should Return a text list of all available snacks
    string stock(ItemAndQuantity *moreSnacks [], int arraySize);     // should update available snacks
    void deposit(double amount);     // should update balance with amount deposited
    string buy(char *snackName);
      // should update inventory with bought snacks
      // update balance based on snack price
      // should notify customer when a snack is unavailable
      // should notify customer when a snack cost more than available balance
    double getBalance();
    int addOneItemAndQuantity(ItemAndQuantity itemAndQuantity);
      // returns success/failure

private:
    ItemAndQuantity *contents [20]; // array of pointers to item-and-quantities
    double balance;
};

#endif /* VendingMachine_hpp */
