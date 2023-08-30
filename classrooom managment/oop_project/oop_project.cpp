// oop_project.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include"Class.h"
#include"Assignment.h"
#include "Submission.h"

using namespace std;

int main()
{
    cout << "\t\t\t\t-------------------Classroom Management System-------------------\t\t\t" << endl << endl;
    cout << "1. Login" << endl;
    cout << "2. Register User" << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string email, password;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Password: ";
        cin >> password;

        // Check if it's a valid student login
        Student student;
        if (student.authenticate_email(email) && student.authenticate_password(password))
        {
            cout << "Student Login Successful!" << endl;
            // Your logic for student menu or actions after login goes here
        }
        else
        {
            // Check if it's a valid teacher login
            Teacher teacher;
            if (teacher.authenticate_email(email) && teacher.authenticate_password(password))
            {
                cout << "Teacher Login Successful!" << endl;
                // Your logic for teacher menu or actions after login goes here
            }
            else
            {
                cout << "Invalid email or password. Login failed." << endl;
            }
        }
        break;
    }

    case 2:
    {
        User user;
        user.register_user();
        cout << "User Registered Successfully!" << endl;
        // Your logic for successful registration, or any other actions after registration goes here
        break;
    }

    default:
        cout << "Invalid choice. Please select either 1 or 2." << endl;
        break;
    }


    
        cout << "\t\t\t\t-------------------Class Management System-------------------\t\t\t" << endl << endl;

       
        Class* currentClass = nullptr;

        while (true)
        {
            cout << "1. Create Class" << endl;
            cout << "2. View Class Details" << endl;
            cout << "3. Update Class Details" << endl;
            cout << "4. Delete Class" << endl;
            cout << "5. Add Student to Roster" << endl;
            cout << "6. Remove Student from Roster" << endl;
            cout << "7. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                if (currentClass != nullptr)
                {
                    cout << "Class already exists. Please delete the existing class before creating a new one.\n";
                }
                else
                {
                    currentClass = new Class();
                    cin.ignore(); // Ignore the newline character from previous input.
                    cin >> *currentClass;
                    currentClass->filehandling_class_writing();
                }
                break;

            case 2:
                if (currentClass == nullptr)
                {
                    cout << "No class exists. Please create a class first.\n";
                }
                else
                {
                    currentClass->filehandling_reading();
                    cout << *currentClass;
                }
                break;

            case 3:
                if (currentClass == nullptr)
                {
                    cout << "No class exists. Please create a class first.\n";
                }
                else
                {
                    currentClass->filehandling_reading();
                    cin.ignore(); // Ignore the newline character from previous input.
                    cin >> *currentClass;
                    currentClass->filehandling_class_writing();
                }
                break;

            case 4:
                if (currentClass == nullptr)
                {
                    cout << "No class exists. Please create a class first.\n";
                }
                else
                {
                    currentClass->filehandling_reading();
                    remove((currentClass->getClassName() + ".txt").c_str());
                    delete currentClass;
                    currentClass = nullptr;
                    cout << "Class deleted successfully.\n";
                }
                break;

            case 5:
                if (currentClass == nullptr)
                {
                    cout << "No class exists. Please create a class first.\n";
                }
                else
                {
                    currentClass->filehandling_reading();
                    string student;
                    cout << "Enter student name to add to roster: ";
                    cin.ignore(); // Ignore the newline character from previous input.
                    getline(cin, student);
                    currentClass->addToRoster(student);
                    currentClass->filehandling_class_writing();
                }
                break;

            case 6:
                if (currentClass == nullptr)
                {
                    cout << "No class exists. Please create a class first.\n";
                }
                else
                {
                    currentClass->filehandling_reading();
                    string student;
                    cout << "Enter student name to remove from roster: ";
                    cin.ignore(); // Ignore the newline character from previous input.
                    getline(cin, student);
                    currentClass->removeFromRoster(student);
                    currentClass->filehandling_class_writing();
                }
                break;

            case 7:
                if (currentClass != nullptr)
                {
                    delete currentClass;
                }
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
                break;
            }
        }




    return 0;

    
}

