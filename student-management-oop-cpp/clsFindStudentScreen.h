#pragma once
#include<iostream>
#include "clsScreen.h"


class clsFindStudentScreen : public clsScreen
{
public:
  
    static void FindAndPrintStudent(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("Find Student Screen");
        if (vStudents.empty())
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        string FullName = "";
        cout << "\nEnter Student Full Name: ";
        FullName = clsInputValidate<string>::ReadString();

        int Index = clsStudent::FindStudentIndexByFullName(FullName, vStudents);
        if (Index == -1)
            cout << "\nStudent [" << FullName << "] Not Found!\n";
        else
            _PrintStudentCard(vStudents[Index]);
    }
};