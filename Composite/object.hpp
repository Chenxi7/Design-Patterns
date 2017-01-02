
//class object

#ifndef object_H
#define object_H

#include <string>
using namespace std;
class object{
    
protected:
    unsigned long long code;
    string name;
    double price;
    
public:
    
    object(unsigned long long code_s, string name_s, double price_s);
    virtual void set_code (unsigned long long code);
    virtual void set_name (string name);
    virtual void set_price (double price);
    virtual unsigned long long get_code ();
    virtual string get_name();
    virtual double get_price();
    virtual bool Add(object *m) =0;
    virtual bool Remove(object *m)=0;
    virtual ~object(){};
    
    
};

#endif
