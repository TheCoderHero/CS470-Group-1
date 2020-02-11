/***********************************************************************
 * Program:
 *    Lab 06, Sanitization
 *    Brother Helfrich, CS 470
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
 *    Please include a detailed description of:
 *    1. What this program is designed to do
 *    2. How this program will go about solving the problem
 *    3. What assumptions about input (file or user) is made
 *    4. Citations if the algorithm was borrowed or inspired from any source
 ************************************************************************/
#include <iostream>
#include <string>
using namespace std;

void prompForSQLQuery(string prompt, string &query);
string queryGeneration(string username, string password);
void testVulnerabilities(string results);
void weakMitigation(string tuatology);
void strongMitigation(string cmdInjection);

int main() {

   // Create 2 string variables to hold user input
   string username = "";
   string password = "";

   // Prompt user for SQL Queries
   promptForSQLQuery("Please enter your username: ", username);
   promptForSQLQuery("Please enter your password: ", password);

   // Create variable to hold SQL string
   string sqlString = queryGeneration(username, password);

   // Test SQL string for vulnerabilities
   testVulnerabilities(sqlString);

   // Run SQL string through weak mitigation test
   weakMitigation(sqlString);

   // Run SQL string through strong mitigation test
   strongMitigation(sqlString);

   return 0;
}

/**********************************************************
 * PROMPT FOR SQL QUERY
 * This function displays a prompt on the screen asking 
 * the user for a username and password. The user provided 
 * input is stored in the "pass-by-reference" string argument.
 * *******************************************************/
void promptForSQLQuery(string prompt, string &query){
   cout << prompt;
   cin >> query;
}

/*****************************************************
 * QUERY GENERATION
 * This function takes the user provided input and
 * transforms it into a single SQL string. This SQL
 * string is then returned to the main function. 
 * **************************************************/
string queryGeneration(string username, string password){

}

/*****************************************************
 * TEST VULNERABILIES
 * 
 * **************************************************/
void testVulnerabilities(string sqlString){
s
}

/*****************************************************
 * WEAK MITIGATION
 * 
 * **************************************************/
void weakMitigation(string tuatology){

}

/*****************************************************
 * STRONG MITIGATION
 * 
 * **************************************************/
void strongMitigation(string cmdInjection){

}
