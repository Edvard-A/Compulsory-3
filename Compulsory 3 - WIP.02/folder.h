#pragma once
#include <iostream>
#include "file.h"
using namespace std;

const int maxFiles = 10;
const int maxFolders = 5;

class Folder {
private:
	string name;
	int size = rand() % 100 + 1;
	int date;

	int numberOfFiles;
	int numberOfFolders;

	File files[maxFiles];
	Folder* folders;

public:

	/// <summary>
	/// default constructor for class Folder, creates empty folder with no name, size, or date. As well as no number of files or folders inside
	/// </summary>
	Folder() {
		name = "";
		size = 0;
		date = 0;

		numberOfFiles = 0;
		numberOfFolders = 0;

		folders = NULL; //creates an empty array of folders
	}

	/// <summary>
	/// constructor for writing new folder with name and date, sets number of files and folders to zero because we always create an empty folder
	/// </summary>
	/// <param name="newName">name of new folder</param>
	/// <param name="newDate">date of creation of folder</param>
	Folder(string newName, int newDate) {
		name = newName;
		date = newDate;

		numberOfFiles = 0;
		numberOfFolders = 0;

		folders = new Folder[maxFolders]; //creates new (empty) array of folders within the folder
	}

	/// <summary>
	/// functions to access private variables of our objects 
	/// </summary>
	/// <returns>name, size, and date of files respectively</returns>
	string getName() { return name; }
	int getSize() { return size; }
	int getDate() { return date; }

	/// <summary>
	/// outputs the information of a given folder
	/// </summary>
	void printInfo() {
		cout << "Folder: " << name << ", Size: " << size << "Mb, Created on: " << date << endl;
	}

	/// <summary>
	/// outputs all folders within a folder
	/// </summary>
	void printFolders() {
		for (int i = 0; i < numberOfFolders; i++) {
			folders[i].printInfo();
		}
	}

	/// <summary>
	/// outputs all files within a folder
	/// </summary>
	void printFiles() {
		for (int i = 0; i < numberOfFiles; i++) {
			files[i].printInfo();
		}
	}

	/// <summary>
	/// outputs all files and folders in a given folder
	/// </summary>
	void printContent() {
		for (int i = 0; i < numberOfFiles; i++) {
			files[i].printInfo();
		}
		for (int i = 0; i < numberOfFolders; i++) {
			folders[i].printInfo();
		}
	}

	/// <summary>
	/// adds a new file into the array of files within a folder
	/// </summary>
	/// <param name="newName">name of the new file</param>
	/// <param name="newDate">date of creation of the new file</param>
	void addFile(string newName, int newDate) {
		if (numberOfFiles < maxFiles) { //checks if number of files has exceded maximum number of files(10)
			files[numberOfFiles] = File(newName, newDate); //adds the new file into the array of files in the position of numberOfFiles
			//here, numberOfFiles is used as the index because it will be 1 more than the index of the previously added file 
			//if we have three files, we will have files in index 0, 1, and 2 in the array, and numberOfFiles will be 3
			//meaning we will write in a new file into the next empty space in the array each time because we increment numberOfFiles
			numberOfFiles++;
		}
		else {
			cout << "ERROR: maximum amount of files within this folder has already been reached :/ " << endl;
		}
	}

	/// <summary>
	/// adds a new folder into the array of folders within a folder
	/// </summary>
	/// <param name="newName">name of new the folder</param>
	/// <param name="newDate">date of creation of the new folder</param>
	void addFolder(string newName, int newDate) {
		if (numberOfFolders < maxFolders) {
			folders[numberOfFolders] = Folder(newName, newDate);
			numberOfFolders++; // worth noting that the number of folders/files variable is exclusive to each object, and that's why we can use them like this
		}
		else {
			cout << "ERROR: maximum amount of folders within this folder has already been reached :/ " << endl;
		}
	}

	/// <summary>
	/// fetches the memory address of a given folder
	/// </summary>
	/// <param name="nameOfFolder">name of the folder we want to fetch</param>
	/// <returns>memory address of our folder</returns>
	Folder* getFolder(string nameOfFolder) { //fetches name of the folder we want to use
		for (int i = 0; i < numberOfFolders; i++)  //runs through all folders in the folder
		{
			if (folders[i].getName() == nameOfFolder) { //if name of a folder in the array of folders matches the name we input
				return &folders[i]; //return memory address of folder in that position (function type is a pointer)
			}
		}
	}

	/// <summary>
	/// finds the largest file within a given folder and outputs the information of that file
	/// </summary>
	void findLargest() {
		int largestFile = 0;
		for (int i = 0; i < numberOfFiles; i++) { //runs through all the files in the folder
			if (largestFile < files[i].getSize()) { 
				largestFile = files[i].getSize(); //if "largestFile" is lesser than the size of the next element in the array, "largestFile" gets set to that size
			}
		}
		for (int j = 0; j < numberOfFiles; j++) {
			if (largestFile == files[j].getSize()) { //finds the file with the matching size of our largest size value
				files[j].printInfo(); //outputs the information of the file with matching size of the largest filse size
			}
		}
	}

	/// <summary>
	/// fetches the file we wish to change name of, and runs it through "changeName()" from "file.h"
	/// </summary>
	void changeFileName() { //finds the position of the file we want to change the name of, so we can "isolate" it
		string nameOfFile;
		cin >> nameOfFile;

		for (int i = 0; i < numberOfFiles; i++) {
			if (nameOfFile == files[i].getName()) {
				files[i].changeName(); //calls the function "changeName" from "file.h" to change name of the specific file we fetched
			}
		}
	}

	/// <summary>
	/// fetches the folder we want to change name of, then changes the name through user input
	/// </summary>
	void changeFolderName() {
		string nameOfFolder;
		string newName; 
		cout << "which folder would you like to change name of?: ";
		cin >> nameOfFolder;
		cout << "new name?: ";
		cin >> newName;
		for (int i = 0; i < numberOfFolders; i++) {
			if (nameOfFolder == folders[i].name) {
				folders[i].name = newName;
			}
		}
	}
};