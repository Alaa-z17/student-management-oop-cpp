
#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
#include <regex>

template <class T> class clsInputValidate
{

public:

	static bool IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;

	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}
		return Number;
	}

	static T ReadPositiveNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number = 0;
		Number = ReadNumber();
		while (Number <= 0)
		{
			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static bool IsValideDate(clsDate Date)
	{
		return	clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}
	static char ReadChar(string ErrorMessage = "InValid Input ,Enter Again : ")
	{
		string S1 = "";
		cin >> S1;
		while (S1.length() != 1)
		{
			cout << ErrorMessage;
			cin >> S1;
		}
		return S1[0];
	}
	static char ReadWanted2Chars(string ErrorMessage = "InValid Input ,Enter Again : ", char Wanted1Char = 'Y', char Wanted2Char = 'N')
	{
		string S1 = "";
		cin >> S1;
		while (S1.length() != 1 || ((toupper(S1[0]) != Wanted1Char) && (toupper(S1[0]) != Wanted2Char)))
		{
			cout << ErrorMessage;
			cin >> S1;
		}
		return  toupper(S1[0]);
	}

	static string ReadEmail()
	{
		string email;

		while (true)
		{
			cout << "Enter Email Address: ";
			cin >> email;

			// Basic email pattern: something@something.something
			regex emailPattern(R"((\w+)(\.?\w+)*@(\w+)(\.(\w+))+)");

			if (regex_match(email, emailPattern))
				break;
			else
				cout << "Invalid Email! Please try again.\n";
		}

		return email;
	}

	// ✅ Read and validate Phone Number
	static string ReadPhone()
	{
		string phone;

		while (true)
		{
			cout << "Enter Phone Number: ";
			cin >> phone;

			// Accepts formats: 1234567890 / +1234567890 / 123-456-7890 / (123)456-7890
			regex phonePattern(R"((\+?[0-9]{1,3})?[-. ]?\(?[0-9]{3}\)?[-. ]?[0-9]{3}[-. ]?[0-9]{4})");

			if (regex_match(phone, phonePattern))
				break;
			else
				cout << "Invalid Phone Number! Please try again.\n";
		}

		return phone;
	}

};


