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
*   This program prompts the user for 2 file patha. It then compares the
*	the user's input to determines if the two file paths are Homographs
*   of Non-Homographs. The program also contains a canonize function
*   which transforms the file path into a standard "canonized" file path.
 ************************************************************************/

#ifdef _WIN32
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string getWorkingDirectory();
void handleUserInput( string &path );
void promptUser( string &path );
void toLowerCase( string &path );
void cleanFileNameOne( string workingDIR, string &path );
void canonizeFilePath( string &path );
void compareFilePaths( string path1, string path2 );

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
            handleUserInput( filepath1 );
            cleanFileNameOne( workingDIR, filepath1 );
            cout << "First filename input: " << filepath1 << "\n";
            handleUserInput( filepath2 );
            canonizeFilePath( filepath2 );
            compareFilePaths( filepath1, filepath2 );
        }
        else if (menuOption == 2) {
            // Prompt user for file path
            handleUserInput( filepath1 );
            canonizeFilePath( filepath1 );
        }

    } while ( menuOption != 3 );

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
    return current_working_dir.append("/");
}

/**************************************************
 * HANDLE USER INPUT
 *
 * ************************************************/
void handleUserInput(string &path) {
    promptUser( path );
    toLowerCase( path );
}

/**************************************************
 * PROMPT USER
 * This function will prompt the user for a filepath
 * and return a string
 * ************************************************/
void promptUser(string &path) {
    // Prompt the user for a filepath
    cout << "Enter a filepath: ";

    // Save user input into the variable
    cin >> path;
}


/**************************************************
 * TO LOWER CASE
 * This function will tranform the filepath to a
 * lower case version of the path.
 * ************************************************/
void toLowerCase(string &path) {
    // Transform each character in the path to lower case
    transform(path.begin(), path.end(), path.begin(), [](unsigned char letter) {
        return tolower(letter);
        });
}

/**************************************************
 * CLEAN FILE NAME ONE
 * Removes unecessary prepend symbols to filename.
 * ************************************************/
void cleanFileNameOne( string workingDIR, string &path ) {
    while (path[0] == '.' || path[0] == '/') {
        path.erase(path.begin());
    }
    path = workingDIR + path;
}

/**************************************************
 * CANONIZE FILE PATH
 * Takes a file path and canonizes it.
 * ************************************************/
void canonizeFilePath( string &path ) {

}

/**************************************************
 * COMPARE FILE PATHS
 * Takes 2 file paths and compares them
 * ************************************************/
void compareFilePaths( string path1, string path2 ) {

}