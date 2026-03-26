#pragma once
#include<iostream>
#include "clsStudent.h"
using namespace std;

class clsStudentScreen
{
private:

    static void _PrintStudentCard(clsStudent Student)
    {
        cout << "\n-----------------------------------\n";
        cout << left << setw(15) << "Full Name"
            << ": " << Student.FullName() << "\n";
        cout << left << setw(15) << "Age"
            << ": " << Student.GetAge() << "\n";
        cout << left << setw(15) << "Email"
            << ": " << Student.GetEmail() << "\n";
        cout << left << setw(15) << "Grade"
            << ": " << Student.GetGrade() << "\n";
        cout << left << setw(15) << "Letter"
            << ": " << Student.GetGradeLetter() << "\n";
        cout << left << setw(15) << "Status"
            << ": " << Student.GetGradeStatus() << "\n";
        cout << "-----------------------------------\n";
    }

    static void _PrintStudentRecordLine(clsStudent Student, int Index)
    {
        cout << left << setw(5) << Index
            << left << setw(20) << Student.FullName()
            << left << setw(8) << Student.GetAge()
            << left << setw(25) << Student.GetEmail()
            << left << setw(8) << Student.GetGrade()
            << left << setw(5) << Student.GetGradeLetter()
            << left << setw(8) << Student.GetGradeStatus()
            << "\n";
    }
public:
    static void PrintStudentList(vector<clsStudent>& vStudents)
    {
        if (vStudents.empty())
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        cout << "\n";
        cout << left << setw(5) << "No."
            << left << setw(20) << "Name"
            << left << setw(8) << "Age"
            << left << setw(25) << "Email"
            << left << setw(8) << "Grade"
            << left << setw(5) << "Letter"
            << left << setw(8) << "Status"
            << "\n";
        cout << string(79, '-') << "\n";

        for (int i = 0; i < (int)vStudents.size(); i++)
            _PrintStudentRecordLine(vStudents[i], i + 1);

        cout << string(79, '-') << "\n";
        cout << "Total Students : " << vStudents.size() << "\n";
        cout << "Passed         : " << clsStudent::CountPassed(vStudents) << "\n";
        cout << "Failed         : " << clsStudent::CountFailed(vStudents) << "\n";
        cout << "Average Grade  : " << clsStudent::CalculateAverage(vStudents) << "\n";

        clsStudent* Top = clsStudent::GetTopStudent(vStudents);
        if (Top != nullptr)
            cout << "Top Student    : " << Top->FullName()
            << " (" << Top->GetGrade() << ")\n";
    }
};
