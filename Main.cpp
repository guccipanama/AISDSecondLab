#include "TClass.h"
#include <windows.h>
#include <conio.h>



int main()
{
	system("color 0A");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Line<char> Line1("Dad", 3);
	cout << Line1 << endl;

	int a[3] = { -1, 2, -3 };
	Line<int> Line2(a, 3);
	cout << Line2 << endl;

	double b[4] = { 1.4, 66, 15.77, 0 };
	Line<double> Line3(b, 4);
	cout << Line3 << endl;

	Line3 = Line3.Substring(1);
	Line3 = Line3.Substring(0, 2);
	cout << Line3 << endl;

	/*String Name1 = "Вася";
	String Name2 = "Василий";
	Name1 = Name2;
	try
	{
		Name1[0] = 'С';
		cout << Name1[6] << endl;
	}
	catch(const char* ex)
	{
		std::cout << ex << endl;
	}
	String Name3 = Name1 + Name2;
	const String Name4 = Name3 * 3;
	Name1 = Name4.Substring(7, 8);
	try
	{
		cout << Name1[2] << endl;
	}
	catch (const char* ex)
	{
		std::cout << ex << endl;
	}
	const String Name5 = Name1 * 3;
	cout << Name5;
	return 0;*/

	/*try
	{
		Line<char> A;
		char Str1[32];
		cout << "Enter the string" << endl;
		cin >> Str1;
		cout << endl;
		A = Str1;
		int Change = 0;
		while (Change == 0)
		{
			system("cls");
			cout << "Your string: " << A << endl;
			cout << endl;
			cout << "Select an option: " << endl;
			cout << "1 - enter the string" << endl;
			cout << "2 - operator for reading / writing a character by its index" << endl;
			cout << "3 - addition operator for string concatenation" << endl;
			cout << "4 - multiplication operator by a number to duplicate a string the specified number of times" << endl;
			cout << "5 - the possibility of obtaining a substring by the specified index of the beginning of the substring and its length" << endl;
			cout << "6 - Exit" << endl;

			int Option = 0;
			cin >> Option;
			cout << endl;
			switch (Option)
			{
			case 1:
			{
				system("cls");
				char Str1[32];
				cout << "Enter the string" << endl;
				cin >> Str1;
				cout << endl;
				A = Str1;
				break;
			}
			case 2:
			{
				system("cls");
				int Index = 0;
				int Choice = 0;
				cout << "Do you want to write by index? Or read it? 1 - write / 2 - read" << endl;
				cin >> Choice;
				cout << endl;
				cout << "Enter the index" << endl;
				cin >> Index;
				cout << endl;
				switch (Choice)
				{
				case 1:
				{
					system("cls");
					cout << A;
					cout << "Element " << Index << " is " << A[Index] << endl;
					cout << "Replace with:  ";
					char s;
					cin >> s;
					A[Index] = s;
					cout << endl;
					cout << A;
				}
				case 2:
				{
					system("cls");
					cout << "Element " << Index << " is " << A[Index] << endl;
					int a = _getch();
				}
				}
				break;
			}
			case 3:
			{
				system("cls");
				char Str2[32];
				cout << "Enter the string" << endl;
				cin >> Str2;
				cout << endl;
				Line<char> B(Str2);
				Line<char> Sum = A + B;
				cout << Sum << endl;
				int a = _getch();
				break;
			}
			case 4:
			{
				system("cls");
				int Multiplier = 1;
				cout << "Enter the multiplier" << endl;
				cin >> Multiplier;
				cout << endl;
				Line<char> Mul = A * Multiplier;
				cout << Mul << endl;
				int a = _getch();
				break;
			}
			case 5:
			{
				system("cls");
				int Index = 0;
				int Length = 0;
				cout << "Enter the index" << endl;
				cin >> Index;
				cout << "Enter the length" << endl;
				cin >> Length;
				Line<char> Sub = A.Substring(Index, Length);
				cout << Sub << endl;
				int a = _getch();
				break;
			}
			case 6:
			{
				return 0;
			}
			}
		}
	}
	catch (const char* Err)
	{
		cerr << "Error: " << Err << endl;
	}
	return 0;*/
 	return 0;
}