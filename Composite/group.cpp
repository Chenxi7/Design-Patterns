//
//  group.cpp
//  composite
//
//  Created by Cathy on 2016/12/11.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#include "group.hpp"
#include <string>
#include <iostream>

#include <list>
#include <algorithm>


bool group::Add(object *m){
    mylist.push_back(m);
    return 0;
}
bool group::Remove(object *m){
    mylist.remove(m);
    return 0;
}

int group::num_p(){
    return mylist.size();
}

void group::search_f(object *m){
    std::list<object*>::iterator i;
    
    i = std::find_if( mylist.begin(), mylist.end(), [](object *x){return x->get_code()==001;});
    
    if (i!=mylist.end()){
        std::cout << "Encontrado " << std::endl;
        std::cout << "code " << (**i).get_code() << std::endl;
        std::cout << "name " << (**i).get_name() << std::endl;
        std::cout << "price " << (**i).get_price() << std::endl;
    }
    
    else
        std::cout << "no encontrado" << std::endl;
}

double group::price_total(){
    double total=0.0;
    for (std::list<object*>::iterator i=mylist.begin();i!=mylist.end();i++){
        total +=(**i).get_price();
    }
    return total;
    
}

