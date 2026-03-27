#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsListStudentsScreen.h"

class clsUpdateStudentScreen : public clsScreen
{
public:

    static void UpdateStudent(vector<clsStudent>& vStudents)
    {
        _DrawScreenHeader("Update Student Screen");

        if (vStudents.empty())
        {
            cout << "\nNo Students Found!\n";
            return;
        }

        clsListStudentsScreen::PrintStudentList(vStudents);

        string FullName = "";
        cout << "\nEnter Student Full Name to Update: ";
        FullName = clsInputValidate<string>::ReadString();

        int Index = clsStudent::FindStudentIndexByFullName(FullName, vStudents);
        if (Index == -1)
        {
            cout << "\nStudent [" << FullName << "] Not Found!\n";
            return;
        }

        _PrintStudentCard(vStudents[Index]);

        char Confirm = 'N';
        cout << "\nAre you sure you want to update? Y/N? ";
        cin >> Confirm;

        if (toupper(Confirm) == 'Y')
        {
            cout << "\nEnter New Details:\n";
            float NewGrade = 0;
            string NewEmail = "";

            // cout << "Enter New Email : ";
            NewEmail = clsInputValidate<string>::ReadEmail();
            cout << "Enter New Grade (0-100): ";
            NewGrade = clsInputValidate<short>::ReadNumberBetween(0, 100);


            vStudents[Index].Email = NewEmail;
            vStudents[Index].Grade = NewGrade;
            clsStudent::SaveStudentsToFile(vStudents);
            cout << "\nStudent Updated Successfully!\n";
        }
    }
};