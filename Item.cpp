//
//  Item.hpp
//  VendingMachineDemo
//
//  Created by Ash Coca on 6/30/20.
//  Copyright © 2020 Galvanize. All rights reserved.
//

#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include "Item.hpp"

Item::Item(char *name, double price, int code) {
    //handle large names first
    if (strlen(name)<20) {
        strcpy(this->name, name);
    } else {
        //throw exception?
        //Name can't be longer than 20 or the copy doesn't work
    }
    this->price = price;
    this->code = code;
}

Item::Item(const Item &item) {
    strcpy (this->name, item.name);
    this->price = item.price;
    this->code = item.code;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << item.name << " with code " << item.code << " costs $" << item.price;
}
