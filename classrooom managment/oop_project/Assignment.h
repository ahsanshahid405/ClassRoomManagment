
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Assignment {
private:
    string title;
    string description;
    time_t deadline;
    vector<string> attachedFiles;
    int pointValue;
public:
    Assignment();
    Assignment(string title, string description, time_t deadline, vector<string> attachedFiles, int pointValue);
    ~Assignment();
    string getTitle();
    string getDescription();
    time_t getDeadline();
    vector<string> getAttachedFiles();
    int getPointValue();

    void setTitle(string title);
    void setDescription(string description);
    void setDeadline(time_t deadline);
    void addAttachedFile(string attachedFile);
    void removeAttachedFile(string attachedFile);
    void setPointValue(int pointValue);
    bool isPastDeadline();

    
   
};

Assignment::Assignment()
{
}

Assignment::Assignment(string title, string description, time_t deadline, vector<string> attachedFiles, int pointValue)
{
    this->title = title;
    this->description = description;
    this->deadline = deadline;
    this->attachedFiles = attachedFiles;
    this->pointValue = pointValue;
}

Assignment::~Assignment()
{
}

string Assignment::getTitle()
{
    return this->title;
}

string Assignment::getDescription()
{
    return this->description;
}

time_t Assignment::getDeadline()
{
    return this->deadline;
}

vector<string> Assignment::getAttachedFiles()
{
    return this->attachedFiles;
}

int Assignment::getPointValue()
{
    return this->pointValue;
}

void Assignment::setTitle(string title)
{
    this->title = title;
}

void Assignment::setDescription(string description)
{
    this->description = description;
}

void Assignment::setDeadline(time_t deadline)
{
    this->deadline = deadline;
}

void Assignment::addAttachedFile(string attachedFile)
{
    this->attachedFiles.push_back(attachedFile);
}

void Assignment::removeAttachedFile(string attachedFile)
{
    for (int i = 0; i < this->attachedFiles.size(); i++)
    {
        if (this->attachedFiles[i] == attachedFile)
        {
            this->attachedFiles.erase(this->attachedFiles.begin() + i);
        }
    }
}


void Assignment::setPointValue(int pointValue)
{
    this->pointValue = pointValue;
}

bool Assignment::isPastDeadline()
{
    time_t now = time(0);
    return now > this->deadline;
}


