#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsListStudentsScreen.h"

class clsDeleteStudentScreen : public clsScreen
{
public:

    static void DeleteStudent(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("Delete Student Screen");




        if (vStudents.empty())
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        clsListStudentsScreen::PrintStudentList(vStudents);

        string FullName = "";
        cout << "\nEnter Student Full Name to Delete: ";
        FullName = clsInputValidate<string>::ReadString();

        int Index = clsStudent::FindStudentIndexByFullName(FullName, vStudents);
        if (Index == -1)
        {
            cout << "\nStudent [" << FullName << "] Not Found!\n";
            return;
        }

        _PrintStudentCard(vStudents[Index]);

        char Confirm = 'N';
        cout << "\nAre you sure you want to delete? Y/N? ";
        cin >> Confirm;

        if (toupper(Confirm) == 'Y')
        {
            vStudents[Index].MarkDelete = true;
            clsStudent::SaveStudentsToFile(vStudents);
            vStudents = clsStudent::LoadStudentsFromFile();
            cout << "\nStudent Deleted Successfully!\n";
        }
    }
};