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
   // prompt the user for a filepath

   // return filepath
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
