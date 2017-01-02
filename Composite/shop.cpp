//Store Class
#include <list>
#include <string>
#include <algorithm>
#include <utility>
#include <iostream>
#include "shop.hpp"

using namespace std;

void store::insert_store(string name, unsigned long long code, double price_s)
{
    mys mystruct;
    mystruct.price=price_s;
    mystruct.name=name;
    mystore.insert (pair<unsigned long long,mys>(code,mystruct));
    this->insert_article (name);
    
}

// Increments the quantity of articles in the list

void store::insert_article(string name)
{
    
    if(f_article(name))
        (*it).second +=1;
    else
        article.push_back( std::make_pair(name,1));
    
    
    
}



void store::delete_store(unsigned long long code){
    
    unordered_map<unsigned long long,mys>::iterator its;
    its = mystore.find(code);
    if (its != mystore.end()){
        send_article(its->second.name);
        mystore.erase(its);
    }
    else
        cout << "No exist in the store" << endl;
    
    
}

void store::send_article (string name)
{
    
    if(f_article(name))
    {
        // If the article is unique delete from the list and the store, on the contrary decrements the article's amount
        if ((*it).second==1)
        {
            string name=(*it).first;
            article.erase(it);
            cout << "Product delete from store: ";
            cout <<  (*it).first<< endl;
        }
        else{
            (*it).second -=1;
            cout << "Product sold: ";
            cout <<  (*it).first<< endl;
            
        }
    }
    else
        cout << "don't exist" << endl;
    
}

long store::get_total(string name)
{
    
    long total=0;
    
    if(f_article(name))
        return total=(*it).second;
    else
        return total=0;
    
    
}

bool store::f_article (string name)
{
    
    // iterator to vector element:
    it = find_if (article.begin(), article.end(), [name](pair<string,long > b){return b.first==name;});
    if (it != article.end())
        return true;
    else
        return false;
}



void store::list_article()
{
    cout << "***** Articles in the store ********" << endl;
    for (list< pair <string,long > >::iterator it=article.begin();it!=article.end();it++)
    {
        
        cout << "- Producto: ";
        cout << (*it).first;
        cout << "- Cantidad: ";
        cout << (*it).second << endl;
        
    }
    
    cout << "***** Articles in the store ********" << endl;
    
}





double store::get_price_store(unsigned long long code){
    
    unordered_map<unsigned long long,mys>::iterator its;
    double price_f;
    its = mystore.find(code);
    if (its != mystore.end()){
        price_f=its->second.price;
        
        
    }
    else 
        cout << "No exist in the store" << endl;
    return price_f;
    
}


