


#include <string>
#include "object.hpp"
#include <list>

class group: public object{
    
private:
    list <object *>mylist;
    
public:
    group(unsigned long long code_s, string name_s, double price_s=0.0):object(code_s, name_s,price_s){
        
    };
    
    virtual bool Add(object *m);
    virtual bool Remove(object *m);
    int num_p();
    void search_f(object *m);
    /* Calculate the total price of all articles contented in the group object*/
    double price_total();
    
};


