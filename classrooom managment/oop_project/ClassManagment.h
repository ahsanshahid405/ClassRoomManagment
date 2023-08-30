#pragma once
#include<iostream>
#include <vector>
#include"Class.h"

using namespace std;

class ClassManagment{
private:
    vector<Class*> classes;
public:
    ClassManagment();
    ~ClassManagment();
    vector<Class*> getClasses();
    Class* getClass(string classname);
    void addClass(Class *class_);
    void removeClass(Class *class_);
    void printClasses();
};

ClassManagment::ClassManagment()
{
}

ClassManagment::~ClassManagment()
{
}

vector<Class*> ClassManagment::getClasses()
{
    return this->classes;
}

Class* ClassManagment::getClass(string classname)
{
    for (int i = 0; i < this->classes.size(); i++)
    {
        if (this->classes[i]->getClassname() == classname)
        {
            return this->classes[i];
        }
    }
    return NULL;
}

void ClassManagment::addClass(Class *class_)
{
    this->classes.push_back(class_);
}

void ClassManagment::removeClass(Class *class_)
{
    for (int i = 0; i < this->classes.size(); i++)
    {
        if (this->classes[i] == class_)
        {
            this->classes.erase(this->classes.begin() + i);
        }
    }
}

void ClassManagment::printClasses()
{
    for (int i = 0; i < this->classes.size(); i++)
    {
        cout << this->classes[i]->getClassname() << endl;
    }
}

