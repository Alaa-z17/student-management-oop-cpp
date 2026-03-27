#pragma once
#include<iostream>
#include"clsInputValidate.h"
#include "clsStudent.h"
#include "Global.h"
#include "clsListStudentsScreen.h"
#include "clsAddStudentScreen.h"
#include "clsUpdateStudentScreen.h"
#include "clsFindStudentScreen.h"
#include "clsShowStudentsStatistics.h"
#include "clsDeleteStudentScreen.h"

using namespace std;

class clsMainScreen : public clsScreen
{
private :
    enum enMainMenuOptions
    {
        eListStudents = 1,
        eAddStudents = 2,
        eDeleteStudent = 3,
        eUpdateStudent = 4,
        eFindStudent = 5,
        eShowStats = 6,
        eExit = 7
    };
   static enMainMenuOptions _ReadMainMenuChoice()
    {
        short Choice = 0;
        _PrintMainMenu();
        cout << "Choose [1-7]: ";
        Choice = clsInputValidate<short>::ReadNumberBetween(1, 7);
        return (enMainMenuOptions)Choice;
    }
  static void _ResetScreen()
   {
       system("cls");
       system("color 0F");
   }
  static void _PrintMainMenu()
  {
      cout << "\n";
      cout << string(45, '=') << "\n";
      _DrawScreenHeader("MainScreen");
      cout << string(45, '=') << "\n";
      cout << "[1] List All Students\n";
      cout << "[2] Add New Student\n";
      cout << "[3] Delete Student\n";
      cout << "[4] Update Student\n";
      cout << "[5] Find Student\n";
      cout << "[6] Show Statistics\n";
      cout << "[7] Exit\n";
      cout << string(45, '=') << "\n";
      cout << "Total Students in System: "
          << clsStudent::GetStudentCount() << "\n";
      cout << string(45, '=') << "\n";
  }
public:
    
    static  void RunStudentSystem()
    {
        vector<clsStudent> vStudents;

        SystemBootForInitailizingStudentsCount(vStudents);


        enMainMenuOptions Choice;
        do
        {
            _ResetScreen();
            Choice = _ReadMainMenuChoice();

            switch (Choice)
            {
            case enMainMenuOptions::eListStudents:
                _ResetScreen();
               clsListStudentsScreen::PrintStudentList(vStudents);
                break;

            case enMainMenuOptions::eAddStudents:
                _ResetScreen();
                clsAddStudentScreen::AddStudents(vStudents);
                break;

            case enMainMenuOptions::eDeleteStudent:
                _ResetScreen();
                clsDeleteStudentScreen::DeleteStudent(vStudents);
                break;

            case enMainMenuOptions::eUpdateStudent:
                clsUpdateStudentScreen::UpdateStudent(vStudents);
                break;

            case enMainMenuOptions::eFindStudent:
                _ResetScreen();
                clsFindStudentScreen::FindAndPrintStudent(vStudents);
                break;

            case enMainMenuOptions::eShowStats:
                _ResetScreen();
                clsShowStudentsStatistics::ShowStatistics(vStudents);
                break;

            case enMainMenuOptions::eExit:
                _ResetScreen();
                cout << "\nGoodbye!\n";
                break;
            }

            if (Choice != enMainMenuOptions::eExit)
            {
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
            }

        } while (Choice != enMainMenuOptions::eExit);
    }
};