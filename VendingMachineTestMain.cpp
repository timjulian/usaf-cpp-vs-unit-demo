//
//  main.cpp
//  VendingMachineDemo
//
//  Created by Ash Coca on 6/30/20.
//  Copyright © 2020 Galvanize. All rights reserved.
//

#include <gtest/gtest.h>
#include "VendingMachine.hpp"


TEST(VendingMachineSuite, ConfirmEmptyAtConstructor) {
    VendingMachine vm;
    EXPECT_EQ(0,vm.countSelections() );
    EXPECT_EQ("", vm.seeSelections());
    EXPECT_EQ(0, vm.getBalance());
}

TEST(VendingMachineSuite, StockWithEmptyListAndConfirmStillEmpty) {
    VendingMachine vm;
    ItemAndQuantity *iq [1] = {};
    vm.stock(iq,0);
    EXPECT_EQ(0,vm.countSelections() );
    EXPECT_EQ("", vm.seeSelections());
}

TEST(VendingMachineSuite, DepositWorks) {
    VendingMachine vm;
    vm.deposit(1.00);
    EXPECT_EQ(1, vm.getBalance());
}

TEST(VendingMachineSuite, addOneItemAndQuantityAndConfirmMethodResponse) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    int countAdded = vm.addOneItemAndQuantity(iq1);
    EXPECT_EQ(1, countAdded);
}


TEST(VendingMachineSuite, addOneItemAndQuantityAndConfirmCountandSelection) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    vm.addOneItemAndQuantity(iq1);
    EXPECT_EQ(1, vm.countSelections());
    EXPECT_EQ("stuff", vm.seeSelections());
}



TEST(VendingMachineSuite, addOneItemAndQuantityTwiceAndConfirmAddedCount) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    char name2[] = "more";
    Item item2(name2, 0.99, 234);
    ItemAndQuantity iq1(item,3);
    int countAdded = vm.addOneItemAndQuantity(iq1);
    EXPECT_EQ(1, countAdded);
    ItemAndQuantity iq2(item2,2);
    countAdded = vm.addOneItemAndQuantity(iq2);
    EXPECT_EQ(1, countAdded);
}


TEST(VendingMachineSuite, addOneItemAndQuantityTwiceAndConfirmAdded) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    char name2[] = "more";
    Item item2(name2, 0.99, 234);
    ItemAndQuantity iq1(item,3);
    int countAdded = vm.addOneItemAndQuantity(iq1);
    ItemAndQuantity iq2(item2,2);
    countAdded = vm.addOneItemAndQuantity(iq2);
    EXPECT_EQ(2, vm.countSelections());
    EXPECT_EQ("stuff:more", vm.seeSelections());
}


TEST(VendingMachineSuite, addOneItemAndQuantityTwiceWithSameItemCodeAndConfirmAdded) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    Item item2(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    int countAdded = vm.addOneItemAndQuantity(iq1);
    ItemAndQuantity iq2(item2,2);
    countAdded = vm.addOneItemAndQuantity(iq2);
    EXPECT_EQ(1, vm.countSelections());
    EXPECT_EQ("stuff", vm.seeSelections());
}


TEST(VendingMachineSuite, StockOneItemAndConfirmAddedMessage) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    ItemAndQuantity *list [1] = { &iq1 };
    string resultMessage = vm.stock(list, 1);
    EXPECT_EQ("stocked", resultMessage);
}


TEST(VendingMachineSuite, StockOneItemAndConfirmAdded) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    ItemAndQuantity *list [1] = { &iq1 };
    vm.stock(list, 1);
    EXPECT_EQ(1, vm.countSelections());
    EXPECT_EQ("stuff", vm.seeSelections());
}

TEST(VendingMachineSuite, StockOneItemAndConfirmBuyWrongItemFails) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    ItemAndQuantity *list [1] = { &iq1 };
    vm.stock(list, 1);
    char badData[] = "abc";
    string message = vm.buy(badData);
    string expected = "We don't have that snack";
    EXPECT_EQ(message, expected);
}

TEST(VendingMachineSuite, StockOneItemAndConfirmBuyTooExpensiveFails) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    ItemAndQuantity *list [1] = { &iq1 };
    vm.stock(list, 1);
    string message = vm.buy(name);
    string expected = "Insufficient funds";
    EXPECT_EQ(message, expected);
}

TEST(VendingMachineSuite, StockOneItemAndConfirmBuySuceeds) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,3);
    ItemAndQuantity *list [1] = { &iq1 };
    vm.stock(list, 1);
    vm.deposit(1.00);
    string message = vm.buy(name);
    string expected = "Enjoy";
    EXPECT_EQ(message, expected);
    EXPECT_NEAR(0.01, vm.getBalance(),0.001);

}

TEST(VendingMachineSuite, StockOneItemThenBuyAndMachineIsEmpty) {
    VendingMachine vm;
    char name[] = "stuff";
    Item item(name, 0.99, 123);
    ItemAndQuantity iq1(item,1);
    ItemAndQuantity *list [1] = { &iq1 };
    vm.stock(list, 1);
    vm.deposit(1.00);
    string message = vm.buy(name);
    EXPECT_EQ(0,vm.countSelections() );
    EXPECT_EQ("", vm.seeSelections());
}

TEST(VendingMachineSuite, StockTwoItemsAndConfirmAdded) {
    VendingMachine vm;
    char name1[] = "stuff";
    char name2[] = "more";
    Item item1(name1, 0.99, 123);
    Item item2(name2, 1.99, 234);
    ItemAndQuantity iq1(item1,3);
    ItemAndQuantity iq2(item2,4);
    ItemAndQuantity *list[2] = {&iq1, &iq2};
    vm.stock(list,2);
    EXPECT_EQ(2, vm.countSelections());
    EXPECT_EQ("stuff:more", vm.seeSelections());
}




int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
