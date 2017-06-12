#ifndef BASECLASS_H
#define BASECLASS_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class BaseClass
{   
public:
    BaseClass();
    virtual void notifyAll()=0;
    void addSubject(BaseClass *);
    void removeSubject(BaseClass*);

    private:
    vector<string> m_list;
    vector<BaseClass *> m_observers;
};

#endif // BASECLASS_H
