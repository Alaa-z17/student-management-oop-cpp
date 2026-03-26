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
};

// Initialize static member
int clsStudent::StudentCount = 0;