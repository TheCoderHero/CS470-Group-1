/***********************************************************************
* Program:
*   Lab 05, Homographs
*   Brother Helfrich, CS 470
*
* Authors:
*   Osvaldo Carrillo Lira
*   Aaron Eiche
*   Zach Heiner
*   Collin Steel
*   John Tanner
*   Jordon Thompson
*
* Summary:
*   This program prompts the user for a file path. It then compares the
*	the user input to a list of forbidden files and determines if they
*	are trying to access a forbidden file. Next, the program runs a
*	comparison on the user input against a set of Non-Homograph test
*	cases and a set of Homograph test cases and displays the results
*	of the comparison. Lastly, the program runs the user input into a
*	canonicalization function that proves the Non-Homograph and
*	Homograph test cases.
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

string promptUser();
string toLowerCase( string path );
void comparePath( string path );
void comparePathNonHomographs( string path );
void comparePathHomographs( string path );

int main()
{
	// Create a string variable to hold filepath
	string filepath = "";

	// Prompt user for file path
	filepath = promptUser();

	// Transform user input to lowercase
	filepath = toLowerCase( filepath );

	if ( filepath[0] != '/' ) {
		filepath.insert( 0, 1, '/' );
	}

	cout << "File path entered: " << filepath << "\n";

	// Compare path to forbidden paths
	comparePath( filepath );
	comparePathNonHomographs(filepath);
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
string toLowerCase( string path ) {
	transform( path.begin(), path.end(), path.begin(), []( unsigned char letter ) {
		return tolower( letter );
		} );

	return path;
}

/**************************************************
 * COMPARE PATH
 * This function will compare the user's path with 
 * a list of forbidden paths. It will then display 
 * whether the paths are the same or different.
 * ************************************************/
void comparePath( string path )
{
	// Create a vector to hold list of forbidden paths
	vector <string> testPaths{ "/home/user/secret/password.txt" };

	// Compare user input with list of paths
	if (find( testPaths.begin(), testPaths.end(), path) != testPaths.end() ) {
		cout << "Filepath matches forbidden path. Access Denied.";
	}
	else {
		cout << "Filepath does not match forbidden path. Access Granted.";
	}
}

/**************************************************
 * COMPARE PATH NON HOMOGRAPHS
 * This function will compare the user's path with 
 * a set of Non-Homograph test cases. It will then
 * display whether the paths pass of fail the
 * Non-Homograph comparison.
 * ************************************************/
void comparePathNonHomographs( string path )
{	
string currentDirectory = "/home/user/cse453"; //std::cout << "Current path is " << fs::current_path() << '\n';
string fobiddenFile = "/home/user/secret/password.txt";
string userPathFile = "./../../secret/password.txt";
string pattern = ("./..");
string secondPattern = ("../");
size_t ocurrences = userPathFile.find("./..");


if (ocurrences != string::npos) {
	userPathFile.erase(0, pattern.length());
	std::cout << "EXp: " << userPathFile << '\n';
}

size_t i = userPathFile.find(secondPattern);
while (i != std::string::npos)
{
	userPathFile.erase(i, secondPattern.length());	
	i = userPathFile.find(secondPattern, i);
}	

cout << "\n Final Path" << userPathFile << "\n";
	
	
}

/**************************************************
 * COMPARE PATH HOMOGRAPHS
 * This function will compare the user's path with 
 * a set of Homograph test cases. It will then
 * display whether the paths pass or fail the
 * Homograph comparison.
 * ************************************************/
void comparePathHomographs( string path )
{

}