#pragma once
#include<iostream>
#include "clsScreen.h"


class clsAddStudentScreen : public clsScreen
{
public:
    static void AddStudents(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("Add Student Screen");

        char AddMore = 'Y';
        do
        {
            cout << "\nAdding New Student:\n";
            clsStudent::AddStudent(vStudents, _ReadNewStudent());
            cout << "\nAdd more students? Y/N? ";
            cin >> AddMore;
        } while (toupper(AddMore) == 'Y');
    }

};