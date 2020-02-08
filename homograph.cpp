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
*   This program prompts the user for 2 file paths. It then compares the
*   the user's input to determines if the two file paths are Homographs
*   of Non-Homographs. The program also contains a canonize function
*   which transforms the file path into a standard "canonized" file path.
 ************************************************************************/
//#define WINDOWS
#ifdef WINDOWS
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
#include <vector>

using namespace std;

string getWorkingDirectory();
void handleUserInput(string& path);
void promptUser(string& path);
void toLowerCase(string& path);
string canonizePath(vector<string>& set);
void compareFilePaths(string path1, string path2);
void splitString(string path, vector<string>& set, char delim = '/');

int main()
{
   // Variable to hold menu option choice
   int menuOption = 0;

   do {

      // Obtain the working directory of the user
      string workingDIR = getWorkingDirectory();
      //cout << "Current working directory is: " << workingDIR << "\n";

      // Create a string variable to hold filepath
      string filepath1 = "";
      string filepath2 = "";
      string canonicalizedPath1 = "";
      string canonicalizedPath2 = "";
      vector<string> set1;
      vector<string> set2;

      cout << "Please choose from the following menu items:\n";
      cout << "1. Compare File Paths For Homograph Attacks\n";
      cout << "2. Test Canonization Function\n";
      cout << "3. Exit Program\n";
      cout << "Menu Selection: ";
      cin >> menuOption;

      // Menu logic
      if (menuOption == 1) {

         // Prompt user for file paths
         handleUserInput(filepath1);

         if (filepath1[0] != '/')
            filepath1 = getWorkingDirectory() + filepath1;

         //Prompt user for second file path - No edits
         handleUserInput(filepath2);
         if (filepath2[0] != '/')
            filepath2 = getWorkingDirectory() + filepath2;

         // Split the paths and store them as sets
         splitString(filepath1, set1);
         splitString(filepath2, set2);

         // Canonize both sets
         filepath1 = canonizePath(set1);
         filepath2 = canonizePath(set2);
         
         cout << "\nResults of Canonicalization Function:\n";
         cout << "Canon Token1: " << filepath1 << '\n';
         cout << "Canon Token2: " << filepath2 << '\n';
         compareFilePaths(filepath1, filepath2);
      }
      else if (menuOption == 2) {
         // Prompt user for file path
         handleUserInput(filepath1);
      }
      else
         menuOption = 3;
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
   string current_working_dir = GetCurrentDir(NULL, 0);

   //string current_working_dir( buff );
   return current_working_dir.append("/");
}

/**************************************************
 * HANDLE USER INPUT
 *
 * ************************************************/
void handleUserInput(string& path) {
   promptUser(path);
   //toLowerCase( path );
}

/**************************************************
 * PROMPT USER
 * This function will prompt the user for a filepath
 * and return a string
 * ************************************************/
void promptUser(string& path) {
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
void toLowerCase(string& path) {
   // Transform each character in the path to lower case
   transform(path.begin(), path.end(), path.begin(), [](unsigned char letter) {
      return tolower(letter);
      });
}

/**************************************************
 * CANONIZE FILE PATH
 * Takes a file path and canonizes it.
 * ************************************************/
string canonizePath(vector<string>& set) {
   string canonPath = "";



   vector<string> returnSet;
   for (vector<string>::iterator it = set.begin(); it != set.end(); it++)
   {
      /*
      cases:
      / - root
      ~ - user home: /home/{username}
      . - current directory
      .. - previous directory
      */
      if (*it == "~") {
         returnSet.clear();
         returnSet.push_back("/" + set[1]);
         returnSet.push_back(set[2]);

      }
      else if (*it == ".") {
      }
      else if (*it == "..") {
         //removes the previous dir
         returnSet.pop_back();
         //removes the ..
      }
      else {
         //adds the item to the path
         returnSet.push_back(*it);
      }
   }
   for (vector<string>::iterator it = returnSet.begin(); it != returnSet.end(); it++)
   {
      //if (*it == "home")
        // canonPath = "/";
      if (it != returnSet.end()) {
         canonPath.append(*it + "/");
      }
      else {
         canonPath.append(*it);
      }
   }
   return canonPath;
}

/**************************************************
 * COMPARE FILE PATHS
 * Takes 2 file paths and compares them
 * ************************************************/
void compareFilePaths(string path1, string path2) {
   if (path1 == path2) {
      cout << "\n";
      cout << "Paths are Homographs\n";
      cout << "\n";
   }
   else {
      cout << "\n";
      cout << "Paths are Non-Homographs\n";
      cout << "\n";
   }
}

/**************************************************
 * SPLIT STRING
 * takes a string, a string vector, and a delimiter
 * Splits the string into its constituent parts.
 * ************************************************/
void splitString(string path, vector<string>& set, char delim)
{
   //counters
   int current, previous = 0;

   //find the first instance of the delimiter
   current = path.find(delim);


   if (current == 0) {
      //cout << "WE ARE AT ROOT";
   }

   // //while the current position is not the null position of the string
   while (current != std::string::npos) {

      //place the substring from previous to the new position into our set.
      set.push_back(path.substr(previous, current - previous));

      //Set the last position to the current.
      previous = current + 1;

      //call it again.
      current = path.find(delim, previous);
   }

   //Add the substring after the last delimiter.
   set.push_back(path.substr(previous, path.size() - previous));
}