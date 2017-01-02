//
//  main.cpp
//  composite
//
//  Created by Cathy on 2016/12/14.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "group.hpp"
#include "single.hpp"
#include "shop.hpp"
//global variable

static long cantidad;

int main()
{
    
    double price;
    // Create the store
    store obj;
    obj.insert_store("cup", 001, 2.5);
    obj.insert_store("cup", 002,2.5);
    obj.insert_store("cup", 003,2.5);
    obj.insert_store("sugar bowl", 004, 5.0);
    obj.insert_store("teapot", 010, 20.0);
    obj.insert_store("spoon", 005, 1.0);
    obj.insert_store("spoon", 006,1.0);
    obj.insert_store("plato", 007, 5.0);
    obj.insert_store("spoon", 006, 1.0);
    
    // Print out the articles stored.
    obj.list_article();
    
    
    // Go shopping
    price=obj.get_price_store(001);
    object *cup=new single(001, "cup", price);
    
    price=obj.get_price_store(002);
    object *cup_2=new single(002, "cup", price);
    
    price=obj.get_price_store(010);
    object *teapot=new single(010, "teapot", price);
    
    group vajilla (004, "vajilla");
    vajilla.Add(cup);
    vajilla.Add(cup_2);
    vajilla.Add(teapot);
    
    cout << "El price total es: " << vajilla.price_total() << endl;
    
    // Send the articles and delete from the store
    obj.delete_store(001);
    obj.delete_store(002);
    obj.delete_store(010);
    obj.list_article();
    
    
    return 0;
}



