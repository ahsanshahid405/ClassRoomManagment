#pragma once
#include<iostream>
#include <string>
#include<fstream>
using namespace std;

class User
{
private:
    string name;
    string email;
    string password;
    string role;
    string contact;

public:
    User();
    User(const string& n, const string& e, const string& p, const string& r, const string& c);

    // Setters
    void SetName(const string& n);
    void SetEmail(const string& e);
    void SetPassword(const string& p);
    void SetRole(const string& r);

    // Getters
    string GetName() const;
    string GetEmail() const;
    string GetPassword() const;
    string GetRole() const;
    string GetContact() const;

    // Virtual functions for authentication
    virtual bool authenticate_email(const string& email) const;
    virtual bool authenticate_password(const string& enteredPassword) const;
    void register_user();
        void store_std();
        void store_teacher();
    

};


User::User()
{
    name = "";
    email = "";
    password = "";
    role = "";
    contact = "";
}

User::User(const string& n, const string& e, const string& p, const string& r, const string& c)
{
    name = n;
    email = e;
    password = p;
    role = r;
    contact = c;
}

void User::SetName(const string& n)
{
    name = n;
}

void User::SetEmail(const string& e)
{
    email = e;
}

void User::SetPassword(const string& p)
{
    password = p;
}

void User::SetRole(const string& r)
{
    role = r;
}

string User::GetName() const
{
    return name;
}

string User::GetEmail() const
{
    return email;
}

string User::GetPassword() const
{
    return password;
}

string User::GetRole() const
{
    return role;
}

string User::GetContact() const
{
    return contact;
}

bool User::authenticate_email(const string& email) const
{
    return false;
}

bool User::authenticate_password(const string& enteredPassword) const
{
    return false;
}

void User::register_user()
{
    cout << "Enter the name: ";
    cin >> name;
    cout << endl;

    cout << "Enter e-mail: ";
    cin >> email;
    cout << endl;

    cout << "Enter Password: ";
    cin >> password;
    cout << endl;

    int n = 0;
    cout << "Select role of the user " << endl;
    cout << "1.Teacher\n2.Student\n";
    cin >> n;

    switch (n)
    {
    case 1:
        role = "Teacher";
        break;
    case 2:
        role = "Student";
        break;
    default:
        cout << "Invalid role " << endl;
        break;
    }

    cout << "Enter the contact info of the user: ";
    cin >> contact;

    if (role == "Student")
    {
        User::store_std();
    }
    else
    {
        User::store_teacher();
    }
}

// Function to store student information
void User::store_std()
{
    string e = User::GetEmail();
    string p = User::GetPassword();

    // Store the student password in 'std_password.txt'
    ofstream passwordFile("std_password.txt", ios::app);
    if (passwordFile.is_open()) {
        passwordFile << p << endl;
        passwordFile.close();
    }
    else {
        cout << "Error: Unable to open password file\n";
    }

    // Store the student email in 'std_email.txt'
    ofstream mail_file("std_email.txt", ios::app);
    if (mail_file.is_open()) {
        mail_file << e << endl;
        mail_file.close();
    }
    else {
        cout << "Error: Unable to open mail file\n";
    }
}
//temporary close for the teacher  class
void User::store_teacher()
{
    string e = User::GetEmail();
    string p = User::GetPassword();

    // Store the student password in 'std_password.txt'
    ofstream passwordFile("teacher_password.txt", ios::app);
    if (passwordFile.is_open()) {
        passwordFile << p << endl;
        passwordFile.close();
    }
    else {
        cout << "Error: Unable to open password file\n";
    }

    // Store the student email in 'std_email.txt'
    ofstream mail_file("teacher_email.txt", ios::app);
    if (mail_file.is_open()) {
        mail_file << e << endl;
        mail_file.close();
    }
    else {
        cout << "Error: Unable to open mail file\n";
    }
}    