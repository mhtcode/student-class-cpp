#include <iostream>
#include "student.h"
using namespace std;
Student::Student(string a = "masih", string b = "tanoursaz", float x = 0) // Constructor
{
    name = a;
    lastname = b;
    score = x;
    sum += score;
    while (1)
    {
        int id = rollno_generate();
        if (!checkRollno(id)) // check the rollno to not duplicate
        {
            rollno_list[count] = id;
            break;
        }
    }
    count++;
}

int Student::count{0};
float Student::sum{0}; // set static sum to 0 for get Average later
int *Student::rollno_list = new int[1000];
// set all
void Student::setStudent(string a, string b, float x)
{
    name = a;
    lastname = b;
    score = x;
    sum += score;
}
// set & get name
void Student::setName(string input) { name = input; };
string Student::getName() const { return name; }
// set & get first name
void Student::setLastname(string input) { lastname = input; }
string Student::getLastname() const { return lastname; }
// set & get score

void Student::setScore(float x)
{
    score = x;
    sum += score;
}
int Student::getScore() const { return score; }
// others
int Student::getCount() { return count; }
int Student::getRollno() const { return rollno; }
int Student::rollno_generate() // generate specefic rollno with "400" + 3 didgits + "3"
{
    srand(time(0));
    string rollno1 = "400";
    string rollno2 = to_string(rand() % 1000);
    while (1)
    {
        if (rollno2.length() == 3) // set roll no to 3 digits
            break;
        rollno2 = to_string(rand() % 1000);
    }
    string rollno_final = rollno1 + rollno2 + "3";
    rollno = stoi(rollno_final); // cast int to string
    return rollno;
}
bool Student::checkRollno(int id)
{
    for (int i = 0; i <= count; i++)
    {
        if (rollno_list[i] == id)
            return true;
    }
    return false;
}
float Student::getAverage()
{

    return (sum / count);
}

Student::~Student(){}; // Destructor

int main()
{
    // TEST1

    // Student s1("masih", "tanoursaz", 10), s2, s3;
    // s2.setStudent("ali", "mohammadi", 15);
    // s3.setName("mohammadi");
    // s3.setLastname("gholami");
    // s3.setScore(18);
    // cout << "student 1 rollno : " << s1.getRollno() << "\t";
    // cout << "student 1 firstname : " << s1.getName() << "   ";
    // cout << "student 1 lastname : " << s1.getLastname() << "   ";
    // cout << "student 1 score : " << s1.getScore() << endl;
    // cout << "Number of students : " << Student::getCount() << endl;
    // cout << "Average of students : " << Student::getAverage() << endl;

    // TEST2

    int number = 0;
    float score = 0;
    string fname, lname;
    cout << "Enter the number of studentes : " << endl;
    cin >> number;
    Student s[number];
    for (int i = 0; i < number; i++)
    {
        cout << "Enter the student " << i + 1 << " firstname :" << endl;
        cin >> fname;

        cout << "Enter the student " << i + 1 << " lastname :" << endl;
        cin >> lname;

        cout << "Enter the student " << i + 1 << " score :" << endl;
        cin >> score;
        s[i].setStudent(fname, lname, score);
    }
    cout << "student 1 rollno : " << s[0].getRollno() << "\t";
    cout << "student 1 firstname : " << s[0].getName() << "   ";
    cout << "student 1 lastname : " << s[0].getLastname() << "   ";
    cout << "student 1 score : " << s[0].getScore() << endl;
    cout << "Number of students : " << Student::getCount() << endl;
    cout << "Average of students : " << Student::getAverage();
    return 0;
}