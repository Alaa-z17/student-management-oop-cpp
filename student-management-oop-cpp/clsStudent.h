#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>

using namespace std;

class clsStudent
{
private:
    string _FirstName = "";
    string _LastName = "";
    short  _Age = 0;
    string _Email = "";
    float  _Grade = 0;
    bool   _MarkDelete = false;

public:
    clsStudent()
    {
        StudentCount++;
    }

    clsStudent(string FirstName, string LastName,
        short Age, string Email, float Grade)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _Age = Age;
        _Email = Email;
        _Grade = Grade;
        StudentCount++;
    }

    ~clsStudent()
    {
        StudentCount--;
    }

    static int StudentCount;

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }
    string GetFirstName()
    {
        return _FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    string GetLastName()
    {
        return _LastName;
    }

    void SetAge(short Age)
    {
        _Age = Age;
    }
    short GetAge()
    {
        return _Age;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }
    string GetEmail()
    {
        return _Email;
    }

    void SetGrade(float Grade)
    {
        _Grade = Grade;
    }
    float GetGrade()
    {
        return _Grade;
    }

    void SetMarkDelete(bool MarkDelete)
    {
        _MarkDelete = MarkDelete;
    }
    bool GetMarkDelete()
    {
        return _MarkDelete;
    }

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    string GetGradeLetter()
    {

        if (_Grade >= 90) return "A+";
        if (_Grade >= 85) return "A";
        if (_Grade >= 80) return "B+";
        if (_Grade >= 75) return "B";
        if (_Grade >= 70) return "C+";
        if (_Grade >= 65) return "C";
        if (_Grade >= 60) return "D+";
        if (_Grade >= 50) return "D";
        return "F";
    }

    string GetGradeStatus()
    {
        if (_Grade >= 50)
            return "Pass";
        else
            return "Fail";
    }

    bool IsPass()
    {
        return _Grade >= 50;
    }

    bool IsFail()
    {
        return _Grade < 50;
    }

    bool IsExcellent()
    {
        return _Grade >= 90;
    }

    static string GetGradeLetterByGrade(float Grade)
    {
        if (Grade >= 90) return "A+";
        if (Grade >= 85) return "A";
        if (Grade >= 80) return "B+";
        if (Grade >= 75) return "B";
        if (Grade >= 70) return "C+";
        if (Grade >= 65) return "C";
        if (Grade >= 60) return "D+";
        if (Grade >= 50) return "D";
        return "F";
    }
    // =====================
    // Static Methods
    // =====================

    static int GetStudentCount()
    {
        return StudentCount;
    }

    static float CalculateAverage(vector<clsStudent>& vStudents)
    {
        if (vStudents.empty())
            return 0;

        float Total = 0;
        for (clsStudent& S : vStudents)
            Total += S.GetGrade();

        return Total / vStudents.size();
    }

    static clsStudent* GetTopStudent(vector<clsStudent>& vStudents)
    {
        if (vStudents.empty())
            return nullptr;

        clsStudent* Top = &vStudents[0];
        for (clsStudent& S : vStudents)
        {
            if (S.GetGrade() > Top->GetGrade())
                Top = &S;
        }
        return Top;
    }

    static int CountPassed(vector<clsStudent>& vStudents)
    {
        int Count = 0;
        for (clsStudent& S : vStudents)
        {
            if (S.IsPass())
                Count++;
        }
        return Count;
    }

    static int CountFailed(vector<clsStudent>& vStudents)
    {
        int Count = 0;
        for (clsStudent& S : vStudents)
        {
            if (S.IsFail())
                Count++;
        }
        return Count;
    }

};

int clsStudent::StudentCount = 0;