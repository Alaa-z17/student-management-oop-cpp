#pragma once
#include<iostream>
#include "clsScreen.h"

class clsShowStudentsStatistics : public clsScreen
{
public:

    static void ShowStatistics(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("Show Students Statistics Screen");
        if (vStudents.empty())
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        cout << "\n";
        cout << string(45, '=') << "\n";
        cout << "         Student Statistics\n";
        cout << string(45, '=') << "\n";
        cout << "Total Students : " << vStudents.size() << "\n";
        cout << "Passed         : " << clsStudent::CountPassed(vStudents) << "\n";
        cout << "Failed         : " << clsStudent::CountFailed(vStudents) << "\n";
        cout << "Average Grade  : " << clsStudent::CalculateAverage(vStudents) << "\n";

        clsStudent* Top = clsStudent::GetTopStudent(vStudents);
        if (Top != nullptr)
            cout << "Top Student    : " << Top->FullName()
            << " (" << Top->GetGrade() << " - "
            << Top->GetGradeLetter() << ")\n";

        cout << string(45, '=') << "\n";
    }
};