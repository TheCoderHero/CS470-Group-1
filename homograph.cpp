#include <iostream>
#include <string>
using namespace std;

string promptUser();
void comparePath(string path);

int main()
{
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
   string tempPath = "";
   // prompt the user for a filepath
   cout << "Enter a filepath: ";
   cin >> tempPath;
   // return filepath
   return tempPath;
}

/**************************************************
 * COMPARE PATH
 * This function will compare the user's path with a
 * list of forbiden path homographs. It will then
 * display weather the paths are the same or different.
 * ************************************************/
void comparePath(string path)
{
   // compare with list of paths

   // if true display...

   // if false display...
}
