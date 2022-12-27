/*
* Kurt Kangas
* CIS 1202 C++ Programming II
* Week 2 Project
* Console Price Lookup
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void Load_Arrays(string[], float[], int&);
void Show_Arrays(string[], float[], int);
void Look_Up_Price(string[], float[], int);
void Sort_Prices(string[], float[], int);
void Highest_Price(string[], float[], int);


int Show_Menu(int&);

int main()
{
	const int SIZE = 15;
	string consoles[SIZE];
	float price[SIZE];
	int refCounter = 0;

	int choice = 0;

	Load_Arrays(consoles, price, refCounter);

	Show_Menu(choice);

	while (choice != 5)
	{
		switch (choice)
		{
		case 1:
			//Load_Arrays(consoles, price, refCounter);
			Show_Arrays(consoles, price, refCounter);
			Show_Menu(choice);
			break;
		case 2:
			Look_Up_Price(consoles, price, refCounter);
			Show_Menu(choice);
			break;
		case 3:
			Sort_Prices(consoles, price, refCounter);
			Show_Menu(choice);
			break;
		case 4:
			Highest_Price(consoles, price, refCounter);
			Show_Menu(choice);
			break;
		case 5:
			exit(0);
			break;
		default:
			cout << "\n INVALID SELECTION \n";
			Show_Menu(choice);
		}
	}
	system("pause");
	return 0;
}

int Show_Menu(int& input)
{
	// Display Menu
	cout << "\nConsole Pricing - Main Menu";
	cout << "\n1. Display all the console prices";
	cout << "\n2. Look up the price of a particular console";
	cout << "\n3. Sort prices in descending order";
	cout << "\n4. Display the console with the highest price";
	cout << "\n5. Exit the program";
	cout << endl << endl;
	cin >> input;
	if (input > 0 && input < 6)
	{
		return input;
	}
}

void Load_Arrays(string tName[], float tPrice[], int& counter)
{
	const int SIZE = 15;
	//counter = 0;

	fstream text;
	text.open("prices.txt", ios::in);
	while (!text.eof())
	{
		getline(text, tName[counter]);
		text >> tPrice[counter];
		counter++;
		text.ignore();
	}
	text.close();
}

void Show_Arrays(string tName[], float tPrice[], int counter)
{
	cout << setprecision(2) << fixed;

	cout << "Console \t\t\t" << "Price" << endl;
	for (int a = 0; a < counter; a++)
	{
		cout << left
			<< setw(32) << tName[a]
			<< setw(32) << tPrice[a];
		cout << endl;
	}
}


void Look_Up_Price(string name[], float price[], int counter)
{
	cout << setprecision(2) << fixed;

	float tempPrice;
	string tempName;



	for (int o = 0; o < counter - 1; o++)
	{

		for (int i = o + 1; i < counter; i++)
		{
			if (name[i] < name[o])
			{
				tempPrice = price[i];
				price[i] = price[o];
				price[o] = tempPrice;

				tempName = name[i];
				name[i] = name[o];
				name[o] = tempName;

			}
		}
	}
	string nm;
	int foundPos = -1;

	cout << "\nConsole name?\t";
	cin.ignore();
	getline(cin, nm);


	int end = counter - 1;
	int beg = 0;
	int mid = (beg + end) / 2;

	for (; beg <= end && foundPos == -1; )
	{
		if (nm == name[mid])
		{
			foundPos = mid;
		}
		else if (nm > name[mid])
		{
			beg = mid + 1;
			mid = (beg + end) / 2;

		}
		else
		{
			end = mid - 1;
			mid = (beg + end) / 2;
		}
	}

	if (foundPos == -1)
	{
		cout << "Console not found." << endl;
	}
	else
	{
		cout << "The current price for " << nm << " is\ $" << price[foundPos] << "." << endl;
	}

}

void Sort_Prices(string name[], float price[], int counter)
{
	double tempPrice;
	string tempName;

	bool swap = true;

	for (int l = 0; l < counter && swap; l++)
	{
		swap = false;
		for (int i = 0; i < counter - 1; i++)
		{
			if (price[i + 1] > price[i])
			{
				swap = true;
				tempPrice = price[i];
				price[i] = price[i + 1];
				price[i + 1] = tempPrice;

				tempName = name[i];
				name[i] = name[i + 1];
				name[i + 1] = tempName;
			}
		}
	}
}
void Highest_Price(string name[], float price[], int counter)
{
	int num = 0;
	int largest = 0;
	for (int p = 0; p < counter; p++)
	{
		if (num < price[p]) {
			num = price[p];
			largest = p;
		}
	}
	cout << "The " << name[largest] << " has the highest price of $" << price[largest] << endl;

}
