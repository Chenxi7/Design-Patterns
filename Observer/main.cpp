//
//  main.cpp
//  observer
//
//  Created by Cathy on 2016/12/11.
//  Copyright © 2016年 Cathy. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Observer
{
public:
    Observer(){}
    virtual ~Observer(){}
    virtual void Update(){};
};

class Blog
{
public:
    Blog(){}
    virtual ~Blog(){}
    
    void Attach(Observer* observer)
    {
        vec_observer.push_back(observer);
    }
    
    void Romve(Observer* observer)
    {
        vector<Observer*>::iterator iter;
        for (iter = vec_observer.begin(); iter != vec_observer.end(); ++iter)
        {
            if ((*iter) == observer)
                vec_observer.erase(iter);
        }
    }
    
    void Notify()
    {
        vector<Observer*>::iterator iter;
        for (iter = vec_observer.begin(); iter != vec_observer.end(); ++iter)
        {
            (*iter)->Update();
        }
    }
    
    virtual void SetStatus(string sts){}
    virtual string GetStatus() { return m_status; };
    
private:
    vector<Observer*> vec_observer;
protected:
    string m_status;
};

class ConcreteBlog :public Blog
{
public:
    ConcreteBlog(string name):m_blog_name(name){}
    ~ConcreteBlog(){}
    
    void SetStatus(string sts)
    {
        m_status = "博客通知： " + m_blog_name + sts;
    }
    
    string GetStatus()
    {
        return m_status;
    }
    
private:
    string m_blog_name;
};

class ConcreteObserver :public Observer
{
private:
    string m_observer_name;
    Blog *m_blog;
public:
    ConcreteObserver(string name, Blog* blog) :m_observer_name(name), m_blog(blog){}
    ~ConcreteObserver(){}
    
    void Update()
    {
        string status = m_blog->GetStatus();
        cout << m_observer_name << "-----------" << status << endl;
    }
};

int main()
{
    Blog *blog = new ConcreteBlog("李东");
    Observer *ob1 = new ConcreteObserver("王楠", blog);
    Observer *ob2 = new ConcreteObserver("张浩", blog);
    blog->Attach(ob1);
    blog->Attach(ob2);
    blog->SetStatus("发表了新博客");
    blog->Notify();
    
    delete blog;
    delete ob1;
    delete ob2;
    
    return 0;
}
