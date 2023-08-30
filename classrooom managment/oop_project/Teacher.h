#pragma once
#include<iostream>
#include"User.h"
using namespace std;

class Teacher : public User
{
private:
    int id;
    //string subject;
public:
    // Constructors
    Teacher();
    Teacher(const string& n, const string& e, const string& p, const string& r, const string& c, int teacher_id);  //, const string& sub);
;   //Teacher(int teacher_id, const string& sub);

    // Setters
    void set_id(int std_id);
    //void set_sub(string sub);

    // Getters
    int get_id();
    //string get_sub();

    // Authentication
    bool authenticate_email(const string& email) const;
    bool authenticate_password(const string& enteredPassword)const;
};

// Constructors
Teacher::Teacher() : User()
{
    id = 0;
    //3subject = "";
}

Teacher::Teacher(const string& n, const string& e, const string& p, const string& r, const string& c, int teacher_id)//, const string& sub)
    : User(n, e, p, r, c)
{
    id = teacher_id;
    //subject = sub;
}
//Teacher::Teacher(int teacher_id, const string& sub)
//{
//    id = teacher_id;
//    subject = sub;
//}

// Setters
void Teacher::set_id(int teacher_id)
{
    id = teacher_id;
}
//void Teacher::set_sub(string sub)
//{
//    subject = sub;
//}

// Getters
int Teacher::get_id()
{
    return id;
}
//string Teacher::get_sub()
//{
//    return subject;
//}

// Authentication
bool Teacher::authenticate_email(const string& email) const
{
    ifstream teach_mail("teacher_email.txt");
    if (!teach_mail.is_open())
    {
        return false;
    }

    string temp;
    while (getline(teach_mail, temp))
    {
        if (temp == email)
        {
            return true;
        }
    }
    return false;
    teach_mail.close();
}

bool Teacher::authenticate_password(const string& enteredPassword) const
{
    ifstream teach_passcode("teacher_password.txt");
    if (!teach_passcode.is_open())
    {
        return false;
    }

    string temp;
    while (getline(teach_passcode, temp))
    {
        if (temp == enteredPassword)
        {
            return true;
        }
    }
    return false;
    teach_passcode.close();
}