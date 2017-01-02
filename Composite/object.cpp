//
//  object.cpp
//  composite
//
//  Created by Cathy on 2016/12/11.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#include "object.hpp"
#include <iostream>
#include <string>



using namespace std;

object::object(unsigned long long code_s, string name_s, double price_s=0.0){
    code = code_s;
    name = name_s;
    price = price_s;
}
void object::set_code (unsigned long long code_s){
    this->code = code_s;
}
void object::set_name (string name_s){
    this->name=name_s;
}
void object::set_price (double price_s){
    this->price = price_s ;
}
unsigned long long object::get_code (){
    return code;
}
string object::get_name(){
    return name;
}
double object::get_price(){
    return price;
    
}
