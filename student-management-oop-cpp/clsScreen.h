#pragma once
#include "clsStudent.h"
#include <iostream>
#include "clsInputValidate.h"

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        cout << "______________________________________";
        cout << "\n\n\t      " << Title;
        if (SubTitle != "")
        {
            cout << "\n  " << SubTitle;
        }
        cout << "\n______________________________________\n\n";
        cout << "\nDate: " << clsDate::GetSystemDateTimeString() << "\n\n";
    }

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

    static clsStudent _ReadNewStudent()
    {
        clsStudent student;

        cout << "Enter First Name : ";
        student.FirstName = clsInputValidate<string>::ReadString();

        cout << "Enter Last Name  : ";
        student.LastName = clsInputValidate<string>::ReadString();

        cout << "Enter Age        : ";
        student.Age = clsInputValidate<short>::ReadNumberBetween(4, 120);

        // cout << "Enter Email      : ";
        student.Email = clsInputValidate<string>::ReadEmail();

        cout << "Enter Grade (0-100): ";
        student.Grade = clsInputValidate<short>::ReadNumberBetween(0, 100);

        return student;
    }
};