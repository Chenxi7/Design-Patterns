#include <algorithm>
#include <utility>
#include <iostream>
#include <unordered_map>
#include "global.h"

using namespace std;


class store{
    
private:
    
    // Containers
    /* Stores the name and the total quantity per article */
    list< pair <string,long > > article;
    
    list< pair <string,long > >::iterator it;
    
    /* Stores the code (map's key) and the mys struct. This struct contains both its name and its price */
    unordered_map<unsigned long long,mys> mystore;
    
public:
    
    
    void insert_store(string name, unsigned long long code,double price_s);
    
    
    void insert_article(string name);
    
    
    void delete_store(unsigned long long code);
    
    
    void send_article (string name);
    
    
    double get_price_store(unsigned long long code);
    
    
    long get_total(string name);
    
    
    bool f_article (string name);
    
    
    void list_article();
    
    
};




