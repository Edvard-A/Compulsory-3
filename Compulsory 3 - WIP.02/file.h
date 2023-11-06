#pragma once
#include <iostream>
using namespace std;

class File {
private:
	string name;
	int size = rand() % 100 + 1;
	int date;

public:
	/// <summary>
	/// default constructor of class File, creates an empty file with no name, size, or date
	/// </summary>
	File() {
		name = "";
		size = 0; 
		date = 0;
	}

	/// <summary>
	/// constructor for writing a file with a name and a date. (size is random and does not need to be included)
	/// </summary>
	/// <param name="newName">name of the new file</param>
	/// <param name="newDate">date of creation of new file</param>
	File(string newName, int newDate) {
		name = newName;
		date = newDate;
	}

	/// <summary>
	/// functions to access private variables of our objects 
	/// </summary>
	/// <returns>name, size, and date of files respectively</returns>
	string getName() { return name; }
	int getSize() { return size; }
	int getDate() { return date; }

	/// <summary>
	/// outputs the information of a file
	/// </summary>
	void printInfo() {
		cout << "File: " << name << ", Size: " << size << "Mb, Created on: " << date << endl;
	}

	/// <summary>
	/// changes the name of a given file
	/// </summary>
	void changeName() {
		string newFileName;
		cout << "new name?: ";
		cin >> newFileName;

		name = newFileName;
	}
	
};
