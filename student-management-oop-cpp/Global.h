#pragma once
#include "clsStudent.h"
#include <iostream>

void SystemBootForInitailizingStudentsCount(vector <clsStudent> &vStudents)
{
	 vStudents = clsStudent::LoadStudentsFromFile();
	 clsStudent::StudentCount = (int)vStudents.size();
}