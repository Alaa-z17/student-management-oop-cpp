#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include "clsString.h"

using namespace std;


string StudentsFileName = "Students.txt";

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
	_declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;
    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }
    string GetLastName()
    {
        return _LastName;
    }
    _declspec(property(get = GetLastName, put = SetLastName)) string LastName;
    void SetAge(short Age)
    {
        if (Age < 4 || Age > 120)
            return;
        _Age = Age;
    }
    short GetAge()
    {
        return _Age;
    }
    _declspec(property(get = GetAge, put = SetAge)) string Age;
    void SetEmail(string Email)
    {
        _Email = Email;
    }
    string GetEmail()
    {
        return _Email;
    }
    _declspec(property(get = GetEmail, put = SetEmail)) string Email;
    void SetGrade(float Grade)
    {
        if (Grade < 0 || Grade >100)
            return;
        _Grade = Grade;
    }
    float GetGrade()
    {
        return _Grade;
    }
    _declspec(property(get = GetGrade, put = SetGrade)) string Grade;
    void SetMarkDelete(bool MarkDelete)
    {
        _MarkDelete = MarkDelete;
    }
    bool GetMarkDelete()
    {
        return _MarkDelete;
    }
    _declspec(property(get = GetMarkDelete, put = SetMarkDelete)) string MarkDelete;
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

   static clsStudent ConvertLineToStudent(string Line, string Separator = "#//#")
    {
        vector<string> vData = clsString::Split(Line, Separator);

        return clsStudent( vData[0],vData[1],stoi(vData[2]), vData[3],stof(vData[4]));
    }

    static string ConvertStudentToLine(clsStudent Student,string Separator = "#//#")
    {
        string Line = "";
        Line += Student.GetFirstName() + Separator;
        Line += Student.GetLastName() + Separator;
        Line += to_string(Student.GetAge()) + Separator;
        Line += Student.GetEmail() + Separator;
        Line += to_string(Student.GetGrade());
        return Line;
    }

   static vector<clsStudent> LoadStudentsFromFile()
    {
        vector<clsStudent> vStudents;
        fstream MyFile;
        MyFile.open(StudentsFileName, ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                if (Line != "")
                    vStudents.push_back(ConvertLineToStudent(Line));
            }
            MyFile.close();
        }
        return vStudents;
    }

    static  void SaveStudentsToFile(vector<clsStudent>& vStudents)
    {
        fstream MyFile;
        MyFile.open(StudentsFileName, ios::out);

        if (MyFile.is_open())
        {
            for (clsStudent& S : vStudents)
            {
                if (!S.GetMarkDelete())
                    MyFile << ConvertStudentToLine(S) << endl;
            }
            MyFile.close();
        }
    }
  static void AddStudent(vector<clsStudent>& vStudents,clsStudent s)
    {
        vStudents.push_back(s);
        SaveStudentsToFile(vStudents);
        cout << "\nStudent Added Successfully!\n";
    }
 static int FindStudentIndexByFullName(string FullName,vector<clsStudent>& vStudents)
  {
      for (int i = 0; i < (int)vStudents.size(); i++)
      {
          if (vStudents[i].FullName() == FullName)
              return i;
      }
      return -1;
  }

};
int clsStudent::StudentCount = 0;