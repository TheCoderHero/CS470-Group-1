/**********************************************************************
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

#define WINDOWS
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string getWorkingDirectory();
string handleUserInput(string path);
string promptUser(string path);
string toLowerCase(string path);
string canonizePath(string workingDIR, string path);

int main()
{
    // Variable to hold menu option choice
    int menuOption = 0;

    do {

        // Obtain the working directory of the user
        string workingDIR = getWorkingDirectory();
        cout << "Current working directory is: " << workingDIR << "\n";

        // Create a string variable to hold filepath
        string filepath1 = "";
        string filepath2 = "";

        cout << "Please choose from the following menu items:\n";
        cout << "1. Compare File Paths For Homograph Attacks\n";
        cout << "2. Test Canonization Function\n";
        cout << "3. Exit Program\n";
        cout << "Menu Selection: ";
        cin >> menuOption;

        // Menu option logic
        if (menuOption == 1) {
            // Prompt user for file paths
            filepath1 = handleUserInput( filepath1);
            filepath2 = handleUserInput( filepath2);
        }
        else if (menuOption == 2) {
            // Prompt user for file path
            filepath1 = handleUserInput(filepath1);
        }

    } while (menuOption != 3);

    return 0;
}

/**************************************************
 * GET WORKING DIRECTORY
 * This function returns the working directory
 * of the user.
 * ************************************************/
string getWorkingDirectory() {
    char buff[FILENAME_MAX];
    GetCurrentDir(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

/**************************************************
 * HANDLE USER INPUT
 *
 * ************************************************/
string handleUserInput(string path) {
    promptUser(path);
    toLowerCase(path);
    return path;
}

/**************************************************
 * PROMPT USER
 * This function will prompt the user for a filepath
 * and return a string
 * ************************************************/
string promptUser(string path) {
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
  * CANONIZE PATH
  * This function will convert the path into an
  * absolute path so it can be compared.
  * ************************************************/
string canonizePath(string workingDIR, string path) {
    for (size_t i = 0; i < path.length(); i++) {
        if (path[i] == '.') {
            if (path[i + 1] == '.') {
                if (path[i + 1] == '/') {
                    //charPath
                }
            }
            else if (path[i + 1] == '/')
                return workingDIR.append(path);
        }
    }
}