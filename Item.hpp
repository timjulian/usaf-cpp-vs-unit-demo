//
//  Item.hpp
//  VendingMachineDemo
//
//  Created by Ash Coca on 6/30/20.
//  Copyright © 2020 Galvanize. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp
#include <sstream>
#include <iostream>
#include <stdio.h>

class Item {
public:
    friend std::ostream& operator<<(std::ostream& os, const Item& person);
    Item(char *name, double price, int code);
    Item(const Item &item);
    char name[20];
    double price;
    int code;
};

#endif /* Item_hpp */
