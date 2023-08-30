#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include"User.h"
using namespace std;



class Student : public User
{
private:
    int id;
public:
    //constructors
    Student();
    Student(const string& n, const string& e, const string& p, const string& r, const string& c, int std_id);
    Student(int std_id);
    //Setters
    void set_id(int std_id);

    //Getters
    int get_id();

    //authentication
    bool authenticate_email(const string& email) const;
    bool authenticate_password(const string& enteredPassword) const;
};

// Constructors
Student::Student() : User()
{
    id = 0;
}

Student::Student(const string& n, const string& e, const string& p, const string& r, const string& c, int std_id)
    : User(n, e, p, r, c)
{
    id = std_id;
}

Student::Student(int std_id)
{
    id = std_id;
}

// Setters
void Student::set_id(int std_id)
{
    id = std_id;
}

// Getters
int Student::get_id()
{
    return id;
}

// Authentication
bool Student::authenticate_email(const string& email) const
{
    ifstream std_mail("std_email.txt");
    if (!std_mail.is_open())
    {
        return false;
    }

    string temp;
    while (getline(std_mail, temp))
    {
        if (temp == email)
        {
            return true;
        }
    }
    return false;
    std_mail.close();
}

bool Student::authenticate_password(const string& enteredPassword) const
{
    ifstream std_passcode("std_password.txt");
    if (!std_passcode.is_open())
    {
        return false;
    }

    string temp;
    while (getline(std_passcode, temp))
    {
        if (temp == enteredPassword)
        {
            return true;
        }
    }
    return false;
    std_passcode.close();
}