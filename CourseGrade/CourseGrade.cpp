// Filename: Blea_HW32.cpp
// Description: Course Grades
// Author: Marcus Blea
// Date: 11/11/22

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Student
{
    string name;
    int id;
    double *tests;
    double average;
    char grade;
};

int main()
{
    int s, t;
    int numStudents;
    int numTests;

    cout << "How many students? " << endl;
    cin >> numStudents;

    cout << "How many tests per student? " << endl;
    cin >> numTests;
    cin.ignore();
    cout << endl;

    Student *students = new Student[numStudents];

    for (s = 0; s < numStudents; s++)
    {
        cout << "Student name: ";
        getline(cin, students[s].name);
        cout << "Student ID: ";
        cin >> students[s].id;
        cin.ignore();

        students[s].tests = new double[numTests];
        students[s].average = 0;
        for (t = 0; t < numTests; t++)
        {
            cout << "Test # " << t + 1 << ": ";
            cin >> students[s].tests[t];
            while (students[s].tests[t] < 0.0 || students[s].tests[t] > 100.0)
            {
                cout << "Enter 0-100: " << endl;
                cout << "Test # " << t + 1 << ": ";
                cin >> students[s].tests[t];
            }
            students[s].average += students[s].tests[t];
            cin.ignore();
        }
        students[s].average /= numTests;
        if (students[s].average >= 90.0)
            students[s].grade = 'A';

        else if (students[s].average >= 80.0)
            students[s].grade = 'B';

        else if (students[s].average >= 70.0)
            students[s].grade = 'C';

        else if (students[s].average >= 60.0)
            students[s].grade = 'D';

        else if (students[s].average >= 50.0)
            students[s].grade = 'F';
    }

    for (s = 0; s < numStudents; s++)
    {
        cout << "Student name: " << students[s].name << endl;
        cout << "Student ID: " << students[s].id << endl;
        cout << "Average: " << fixed << setprecision(1) << students[s].average << endl;
        cout << "Grade: " << students[s].grade << endl;
        delete[] students[s].tests;
    }
    delete[] students;
}