#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <time.h>
using namespace std;
class Student
{
private:
    string name;
    string lastname;
    int rollno; // The id of each student
    float score;
    static int count;        // uses for number of student
    static int *rollno_list; // list of rollno(s)
    static float sum;        // uses for Average

public:
    Student(string a, string b, float x); // Constructor

    void setStudent(string a, string b, float x);
    static int getCount();
    int rollno_generate();
    bool checkRollno(int id);
    void setName(string a);
    string getName() const;
    void setLastname(string b);
    string getLastname() const;
    void setScore(float x);
    int getScore() const;
    int getRollno() const;
    static float getAverage();

    ~Student(); // Destructor
};
#endif