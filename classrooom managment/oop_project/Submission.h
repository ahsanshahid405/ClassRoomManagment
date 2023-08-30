#include <iostream>
# include <vector>
#include<ctime>

using namespace std;

class Submission {
private:
    time_t timestamp;
    vector<string> attachedFiles;
    bool graded;
    string feedback;
public:
    Submission();
    Submission(time_t timestamp, vector<string> attachedFiles, bool graded, string feedback);
    ~Submission();
    time_t getTimestamp();
    vector<string> getAttachedFiles();
    bool isGraded();
    string getFeedback();

    void setTimestamp(time_t timestamp);
    void addAttachedFile(string attachedFile);
    void removeAttachedFile(string attachedFile);
    void setGraded(bool graded);
    void setFeedback(string feedback);
    bool isLate(time_t deadline);
    void printSubmission();

};

Submission::Submission()
{
}

Submission::Submission(time_t timestamp, vector<string> attachedFiles, bool graded, string feedback)
{
    this->timestamp = timestamp;
    this->attachedFiles = attachedFiles;
    this->graded = graded;
    this->feedback = feedback;
}

Submission::~Submission()
{
}

time_t Submission::getTimestamp()
{
    return this->timestamp;
}

vector<string> Submission::getAttachedFiles()
{
    return this->attachedFiles;
}

bool Submission::isGraded()
{
    return this->graded;
}

string Submission::getFeedback()
{
    return this->feedback;
}

void Submission::setTimestamp(time_t timestamp)
{
    this->timestamp = timestamp;
}

void Submission::addAttachedFile(string attachedFile)
{
    this->attachedFiles.push_back(attachedFile);
}

void Submission::removeAttachedFile(string attachedFile)
{
    for (int i = 0; i < this->attachedFiles.size(); i++) {
        if (this->attachedFiles[i] == attachedFile) {
            this->attachedFiles.erase(this->attachedFiles.begin() + i);
        }
    }
}

void Submission::setGraded(bool graded)
{
    this->graded = graded;
}

void Submission::setFeedback(string feedback)
{
    this->feedback = feedback;
}

bool Submission::isLate(time_t deadline)
{
    return this->timestamp > deadline;
}

void Submission::printSubmission()
{
    cout << "Timestamp: " << this->timestamp << endl;
    cout << "Attached Files: " << endl;
    for (int i = 0; i < this->attachedFiles.size(); i++) {
        cout << this->attachedFiles[i] << endl;
    }
    cout << "Graded: " << this->graded << endl;
    cout << "Feedback: " << this->feedback << endl;
}

