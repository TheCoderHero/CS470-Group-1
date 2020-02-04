#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string promptUser();
void comparePath(string path);

int main()
{
   // Create a string variable to hold filepath
   string filepath = "";

   // Prompt user for file path
   filepath = promptUser();

   // Compare path to forbidden path
   comparePath(filepath);
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
 * COMPARE PATH
 * This function will compare the user's path with a
 * list of forbiden path homographs. It will then
 * display whether the paths are the same or different.
 * ************************************************/
void comparePath(string path)
{
   // Create a vector to hold list of forbiden paths
   // Replace "pathA..." with forbiden paths
   vector <string> testPaths {"pathA...", "pathB...", "pathC..."};

   // Compare user input with list of paths
   if ( find(testPaths.begin(), testPaths.end(), path) != testPaths.end() ) {
      //Do something if true
   }
   else {
      // Do something if false
   }

}