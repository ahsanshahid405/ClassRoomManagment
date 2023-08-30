#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Class
{
private:
    string className;
    string subject;
    string teacher;
    string description;
    string* roster;
    int rosterSize;

public:
    Class();
    Class(const string& name, const string& sub, const string& t, const string& desc);
    ~Class();

    // Setters
    void setClassName(const string& name);
    void setSubject(const string& sub);
    void setTeacher(const string& t);
    void setDescription(const string& desc);
    void addToRoster(const string& student);
    void removeFromRoster(const string& student);

    // Getters
    string getClassName() const;
    string getSubject() const;
    string getTeacher() const;
    string getDescription() const;
    string* getRoster() const;
    int getRosterSize() const;

    // Utility functions
    void filehandling_class_writing();
    void filehandling_reading();

    // Stream insertion and extraction operators
    friend ostream& operator<<(ostream& os, const Class& classObj);
    friend istream& operator>>(istream& is, Class& classObj);
};

Class::Class()
{
    className = "";
    subject = "";
    teacher = "";
    description = "";
    roster = nullptr;
    rosterSize = 0;
}

Class::Class(const string& name, const string& sub, const string& t, const string& desc)
{
    className = name;
    subject = sub;
    teacher = t;
    description = desc;
    roster = nullptr;
    rosterSize = 0;
}

Class::~Class()
{
    delete[] roster;
}

void Class::setClassName(const string& name)
{
    className = name;
}

void Class::setSubject(const string& sub)
{
    subject = sub;
}

void Class::setTeacher(const string& t)
{
    teacher = t;
}

void Class::setDescription(const string& desc)
{
    description = desc;
}

void Class::addToRoster(const string& student)
{
    string* tempRoster = new string[rosterSize + 1];
    for (int i = 0; i < rosterSize; i++)
    {
        tempRoster[i] = roster[i];
    }
    tempRoster[rosterSize] = student;

    // Deallocate the previous roster memory before reassigning the pointer.
    delete[] roster;
    roster = tempRoster;
    rosterSize++;
}

void Class::removeFromRoster(const string& student)
{
    int indexToRemove = -1;
    for (int i = 0; i < rosterSize; i++)
    {
        if (roster[i] == student)
        {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove != -1)
    {
        string* tempRoster = new string[rosterSize - 1];
        for (int i = 0, j = 0; i < rosterSize; i++)
        {
            if (i != indexToRemove)
            {
                tempRoster[j++] = roster[i];
            }
        }
        delete[] roster;
        roster = tempRoster;
        rosterSize--;
    }
}

string Class::getClassName() const
{
    return className;
}

string Class::getSubject() const
{
    return subject;
}

string Class::getTeacher() const
{
    return teacher;
}

string Class::getDescription() const
{
    return description;
}

string* Class::getRoster() const
{
    return roster;
}

int Class::getRosterSize() const
{
    return rosterSize;
}

void Class::filehandling_class_writing()
{
    ofstream classFile(className + ".txt");
    if (classFile.is_open())
    {
        classFile << className << endl;
        classFile << subject << endl;
        classFile << teacher << endl;
        classFile << description << endl;
        for (int i = 0; i < rosterSize; i++)
        {
            classFile << roster[i] << endl;
        }
        classFile.close();
    }
    else
    {
        cout << "Error: Unable to save class data to file\n";
    }
}

void Class::filehandling_reading()
{
    ifstream classFile(className + ".txt");
    if (classFile.is_open())
    {
        getline(classFile, className);
        getline(classFile, subject);
        getline(classFile, teacher);
        getline(classFile, description);

        delete[] roster;
        roster = nullptr;
        rosterSize = 0;

        string student;
        while (getline(classFile, student))
        {
            addToRoster(student);
        }

        classFile.close();
    }
    else
    {
        cout << "Error: Unable to load class data from file\n";
    }
}

ostream& operator<<(ostream& os, const Class& classObj)
{
    os << "Class Name: " << classObj.className << endl;
    os << "Subject: " << classObj.subject << endl;
    os << "Teacher: " << classObj.teacher << endl;
    os << "Description: " << classObj.description << endl;
    os << "Roster:" << endl;
    for (int i = 0; i < classObj.rosterSize; i++)
    {
        os << "- " << classObj.roster[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Class& classObj)
{
    cout << "Enter Class Name: ";
    getline(is, classObj.className);

    cout << "Enter Subject: ";
    getline(is, classObj.subject);

    cout << "Enter Teacher: ";
    getline(is, classObj.teacher);

    cout << "Enter Description: ";
    getline(is, classObj.description);

    cout << "Enter Roster (Enter 'done' to finish adding students):\n";
    string student;
    classObj.roster = new string[1];
    classObj.rosterSize = 0;
    while (true)
    {
        getline(is, student);
        if (student == "done")
            break;
        classObj.addToRoster(student);
    }

    return is;
}

