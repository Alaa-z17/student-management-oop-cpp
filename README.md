# Student Management System (OOP C++)

A console-based student management application built with Object-Oriented Programming principles in C++. This system allows users to perform CRUD operations on student records, track academic performance, and manage student data persistently using file storage.

## 🎥 Video Tutorial

[![Student Management System C++ Tutorial](https://img.youtube.com/vi/ACTUAL_VIDEO_ID/0.jpg)](https://youtu.be/ACTUAL_VIDEO_ID)

*Click the image above to watch a complete walkthrough of the Student Management System!*

## 📌 Features

- **Student Management**
  - Add new students with details (Name, Age, Email, Grade)
  - List all students with formatted output
  - Find students by full name
  - Update student information (Email, Grade)
  - Delete students (soft delete with file persistence)
  
- **Statistics & Analytics**
  - Total student count
  - Number of passed/failed students
  - Average grade calculation
  - Top student identification
  - Letter grade conversion (A+, A, B+, etc.)

- **Data Persistence**
  - Automatic saving to `Students.txt`
  - Load students from file on startup
  - Soft delete system (marks deletion without immediate removal)

- **Validation & Utilities**
  - Input validation with range checking
  - Email format validation using regex
  - Phone number format validation
  - Comprehensive date handling class
  - String manipulation utilities

## 🛠️ Technologies Used

- **Language**: C++17
- **Paradigm**: Object-Oriented Programming
- **File I/O**: Standard fstream library
- **Data Structure**: STL Vector
- **Validation**: Regular Expressions (regex)

## 📁 Project Structure

student-management-oop-cpp/
│
├── 📄 student-management-oop-cpp.cpp # Main entry point
│
├── 🎯 Screens/
│ ├── clsMainScreen.h # Main menu and navigation
│ ├── clsScreen.h # Base screen class
│ ├── clsAddStudentScreen.h # Add student interface
│ ├── clsListStudentsScreen.h # Display all students
│ ├── clsFindStudentScreen.h # Search functionality
│ ├── clsUpdateStudentScreen.h # Update student records
│ ├── clsDeleteStudentScreen.h # Delete student records
│ └── clsShowStudentsStatistics.h # Statistics display
│
├── 📦 Models/
│ ├── clsStudent.h # Student class (core model)
│ ├── clsDate.h # Comprehensive date utilities
│ └── clsString.h # String manipulation utilities
│
├── 🛡️ Utilities/
│ ├── clsInputValidate.h # Input validation template
│ └── Global.h # Global initialization
│
└── 💾 Data/
└── Students.txt # Persistent storage file (auto-generated)

text

## 🚀 Getting Started

### Prerequisites

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- Make/CMake (optional, for build automation)

### Compilation

**Using g++:**
bash g++ -std=c++17 student-management-oop-cpp.cpp -o StudentManagementSystem
Using Visual Studio:

Create a new Console Application project

Add all header files to the project

Build and run

Running the Application
bash
./StudentManagementSystem   # Linux/Mac
StudentManagementSystem.exe # Windows
📖 Usage Guide
Main Menu Options
List All Students - Display all students with formatted table showing:

Name, Age, Email, Grade, Letter Grade, Status (Pass/Fail)

Statistics (Total, Passed, Failed, Average, Top Student)

Add New Student - Input student details with validation:

First Name & Last Name

Age (4-120 years)

Email (valid format required)

Grade (0-100)

Delete Student - Soft delete by full name:

Shows student card for confirmation

Marks as deleted (removes from file)

Update Student - Modify existing student:

Update email and grade only

Maintains original name and age

Find Student - Search by full name:

Displays detailed student information

Show Statistics - Overview of:

Total students

Pass/fail counts

Average grade

Top performer

Exit - Close the application

Data Storage Format
Student records are stored in Students.txt with the format:

text
FirstName#//#LastName#//#Age#//#Email#//#Grade
Example:

text
[John#//#Doe#//#20#//#john.doe@example.com#//#85.5]
🎯 Key Classes Overview
clsStudent
Core student model with:

Properties: FirstName, LastName, Age, Email, Grade

Methods: Grade letter conversion, pass/fail checking

Static methods: File I/O operations, statistics calculations

clsDate
Comprehensive date handling with:

Date validation, comparison, and arithmetic

Calendar generation (monthly/yearly)

Business day calculations

Age calculation utilities

clsInputValidate<T>
Template-based validation:

Range checking for numeric types

Date validation

Email and phone number format validation

Secure string input handling

clsScreen & Derivatives
Screen management hierarchy:

Base screen with common UI elements

Specialized screens for each operation

Consistent formatting and user experience

🔧 Customization
Adding New Fields
Add property to clsStudent class

Update ConvertStudentToLine() and ConvertLineToStudent()

Modify screen classes to handle new field

Update file format if necessary

Changing File Format
Modify Separator parameter in:

clsStudent::ConvertStudentToLine()

clsStudent::ConvertLineToStudent()

Modifying Grade Scale
Update GetGradeLetter() and GetGradeLetterByGrade() in clsStudent

Click the thumbnail above to watch a complete walkthrough of the Student Management System!

👨‍💻 Author
Alaa Zidan

GitHub: @Alaa-z17

📄 License
This project is open source and available under the MIT License.

🤝 Contributing
Contributions are welcome! Feel free to:

Report bugs

Suggest new features

Submit pull requests

⚠️ Notes
The application uses soft delete (students are marked as deleted but not physically removed from the file)

Student count updates automatically when adding/deleting students

Email validation uses regex pattern: (\w+)(\.?\w+)*@(\w+)(\.(\w+))+

Age validation: 4-120 years

Grade validation: 0-100

🐛 Known Issues
None currently. Please report any issues you encounter!

⭐ Star this repository if you find it helpful!