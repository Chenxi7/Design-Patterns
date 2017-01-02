
#include <string>
#include "object.hpp"

class single: public object{
    
    
public:
    single(unsigned long long code_s, string name_s, double price_s):object(code_s, name_s,price_s){
        
    };
    
    virtual bool Add(object *m);
    virtual bool Remove(object *m);
    //virtual ~single(){};
    
    
};


