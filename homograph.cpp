/***********************************************************************
* Program:
*   Lab 05, Homographs
*   Brother Helfrich, CS 470
* Authors:
*   Osvaldo Carrillo Lira
*   Aaron Eiche
*   Zach Heiner
*   Collin Steel
*   John Tanner
*   Jordon Thompson
*
* Summary:
*   A program that that takes a user provided filepath and tests it
*   for homograph attacks.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <filesystem>

using namespace std;

string promptUser();
string toLowerCase(string path);
void comparePath(string path);

int main()
{
	// Create a string variable to hold filepath
	string filepath = "";

	// Prompt user for file path
	filepath = promptUser();

	// Transform user input to lowercase
	filepath = toLowerCase(filepath);

	if ( filepath[0] != '/' ) {
		filepath.insert( 0, 1, '/' );
	}

	cout << "File path: " << filepath << "\n";

	// Compare path to forbidden paths
	comparePath(filepath);

	system("pause");
}

/**************************************************
 * PROMPT USER
 * This function will prompt the user for a filepath
 * and return a string
 * ************************************************/
string promptUser()
{
	// Create temporary string variable
	string tempPath = "";

	// Prompt the user for a filepath
	cout << "Enter a filepath: ";

	// Save user input into the variable
	cin >> tempPath;

	// Return user input
	return tempPath;
}

/**************************************************
 * TO LOWER CASE
 * This function will tranform the filepath to a
 * lower case version of the path.
 * ************************************************/
string toLowerCase(string path) {
	transform(path.begin(), path.end(), path.begin(), [](unsigned char letter) {
		return tolower(letter);
		});

	return path;
}

/**************************************************
 * COMPARE PATH
 * This function will compare the user's path with a
 * list of forbidden path homographs. It will then
 * display whether the paths are the same or different.
 * ************************************************/
void comparePath(string path)
{
	// Create a vector to hold list of forbidden paths
	// Replace "pathA..." with forbidden paths
	vector <string> testPaths{ "/home/user/secret/password.txt" };

	// Compare user input with list of paths
	if (find(testPaths.begin(), testPaths.end(), path) != testPaths.end()) {
		cout << "Filepath matches forbidden path. Not allowed.";
	}
	else {
		cout << "Filepath does not match forbidden path. Access Granted.";
	}
}