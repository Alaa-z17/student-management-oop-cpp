#pragma once
#include<iostream>
#include "clsScreen.h"


class clsListStudentsScreen : public clsScreen
{
public:
    static void PrintStudentList(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("List Student Screen");

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