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
#include <vector>
using namespace std;


struct userpass {
    string username;
    string password;
};

void promptForSQLQuery(string prompt, string& query);
string queryGeneration(string username, string password);
void testValidCases();
void testVulnerabilities(string results, vector <userpass> testVector);
void weakMitigation(string checkString, vector<userpass> testVector);
void strongMitigation(string attacks[], vector<userpass> testVector);

vector <userpass>validCases{
   {"Jimmy","_P34Gu_234"},
   {"culigan","Password_1234"},
   {"Franky","1234_password"},
   {"Franky_445","12_pass_34_Word"},
   {"Arnold_2003","pass_34_12_worD"},
   {"2005_Kerry","5678_pword_1234"},
   {"3_3_Jake","p_1234567"},
   {"Alf_1980","Hairy_alien_80s"},
   {"Kade_Emily_2005","_Got_Married_2_2"},
   {"username","password"},
   {"My_House","House_My"},
   {"Home_1234","1234_Home"}
};

vector <userpass>tautologyAttacks{
   {"Jimmy","password' OR '1'='1"},
   {"Jimmy","true OR 'x'='x"}
};

vector <userpass>unionQueryAttacks{
   {"Jimmy", "password' UNION SELECT authenticate FROM passList"},
   {"Jimmy", "password' UNION SELECT name FROM passList"}
};

vector <userpass>additionalStatementAttacks{
   {"Jimmy", "password' INSERT INTO users(name, id) VALUES 'bob', '9"},
   {"Jimmy", "password' INSERT INTO users(userName, password) VALUES 'jimbob', 'Gotcha_right_now"}
};

vector <userpass>commentAttacks{
   {"Jimmy'; --", "password"},
   {"Jimmy", "password'; --"}
};

vector <userpass>allCases{
    // Normal Test Cases
    {"Jimmy","_P34Gu_234"},
    {"culigan","Password_1234"},
    {"Franky","1234_password"},
    {"Franky_445","12_pass_34_Word"},
    {"Arnold_2003","pass_34_12_worD"},
    {"2005_Kerry","5678_pword_1234"},
    {"3_3_Jake","p_1234567"},
    {"Alf_1980","Hairy_alien_80s"},
    {"Kade_Emily_2005","_Got_Married_2_2"},
    {"username","password"},
    {"My_House","House_My"},
    {"Home_1234","1234_Home"},
    // Tautology attacks
    {"Jimmy","password' OR '1'='1"},
    {"Jimmy","true OR 'x'='x"},
    // Union Query attacks
    {"Jimmy", "password' UNION SELECT authenticate FROM passList"},
    {"Jimmy", "password' UNION SELECT name FROM passList"},
    // Additional Statement Attacks
    {"Jimmy", "password'; INSERT INTO users(name, id) VALUES 'bob', '9"},
    {"Jimmy", "password'; INSERT INTO users(userName, password) VALUES 'jimbob', 'Gotcha_right_now"},
    // Comment Attacks
    {"Jimmy'; --", "password"},
    {"Jimmy", "password'; --"}
};


int main() {

    cout << "SANITIZATION PROGRAM: LAB 6\n";

    // Variable to hold menu option choice
    int menuOption = 0;

    do {

        // Print menu options
        cout << "\nPlease choose from the following menu items:\n\n";
        cout << "1. Run vulnerability test and mitigation on custom SQL Query\n";
        cout << "2. Show output for Test Cases containing Valid Inputs\n";
        cout << "3. Show output for Test Cases containing Tautology Attacks\n";
        cout << "4. Show output for Test Cases containing Union Query Attacks\n";
        cout << "5. Show output for Test Cases containing Additional Statement Attacks\n";
        cout << "6. Show output for Test Cases containing Comment Attacks\n";
        cout << "7. Run vulnerability test and mitigation on all Test Cases\n";
        cout << "8. Exit Program\n\n";
        cout << "Menu Selection: ";

        // Get user menu selection
        cin >> menuOption;

        // Handle menu selection error
        if (cin.fail())
        {
            menuOption = 0;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore();
        cout << "\n";

        switch (menuOption) {
            case 1:
            {
                // Create 2 string variables to hold user input
                string username = "";
                string password = "";

                // Prompt user for SQL Queries
                promptForSQLQuery("Please enter your username: ", username);
                promptForSQLQuery("Please enter your password: ", password);

                // Create vector to hold customized SQL String
                vector<userpass> customSQLString{ {username, password} };

                cout << "\nOutput for custom SQL String vulnerabilities:\n";
                testVulnerabilities("", customSQLString);

                // Run SQL string through weak mitigation test
                cout << "\nWeak Mitigation for Tautology Atacks:\n";
                weakMitigation(" OR ", customSQLString);
                cout << "Weak Mitigation for Union Query Atacks:\n";
                weakMitigation("UNION", customSQLString);
                cout << "Weak Mitigation for Additional Statement Atacks:\n";
                weakMitigation(";", customSQLString);
                cout << "Weak Mitigation for Comment Atacks:\n";
                weakMitigation("--", customSQLString);

                // Run SQL string through strong mitigation test
                cout << "Strong Mitigation for all Attacks:\n";
                string Attacks[5] = { ";", "'", "UNION", "--", "OR" };
                strongMitigation(Attacks, customSQLString);
                break;
            }
            case 2:
                cout << "Output for valid test cases: \n";
                testValidCases();
                break;
            case 3:
                // Test SQL string for vulnerabilities
                cout << "Output for Tautology attacks:\n";
                testVulnerabilities("", tautologyAttacks);
                break;
            case 4:
                // Test SQL string for vulnerabilities
                cout << "Output for Union Query attacks:\n";
                testVulnerabilities("", unionQueryAttacks);
                break;
            case 5:
                // Test SQL string for vulnerabilities
                cout << "Output for Additional Statement attacks:\n";
                testVulnerabilities("", additionalStatementAttacks);
                break;
            case 6:
                // Test SQL string for vulnerabilities
                cout << "Output for Comment attacks:\n";
                testVulnerabilities("", commentAttacks);
                break;
            case 7:
            {
                // Run SQL string through weak mitigation test
                cout << "Weak Mitigation for Tautology Atacks:\n";
                weakMitigation(" OR ", allCases);
                cout << "Weak Mitigation for Union Query Atacks:\n";
                weakMitigation("UNION", allCases);
                cout << "Weak Mitigation for Additional Statement Atacks:\n";
                weakMitigation(";", allCases);
                cout << "Weak Mitigation for Tautology Atacks:\n";
                weakMitigation("--", allCases);

                // Run SQL string through strong mitigation test
                cout << "Strong Mitigation for all Attacks:\n";
                string Attacks[5] = { ";", "'", "UNION", "--", "OR" };
                strongMitigation(Attacks, allCases);
                cout << "\n";
                break;
            }
        }

    } while (menuOption != 8);

    return 0;
}

/**********************************************************
 * PROMPT FOR SQL QUERY
 * This function displays a prompt on the screen asking
 * the user for a username and password. The user provided
 * input is stored in the "pass-by-reference" string argument.
 * *******************************************************/
void promptForSQLQuery(string prompt, string& query) {
    cout << prompt;
    getline(cin, query);
}

/*****************************************************
 * QUERY GENERATION
 * This function takes the user provided input and
 * transforms it into a single SQL string. This SQL
 * string is then returned to the main function.
 * **************************************************/
string queryGeneration(string username, string password) {
    return "SELECT authenticate FROM passwordList WHERE name='" + username + "' and password='" + password + "';";
}

/*****************************************************
 * TEST VALID CASES
 * This function takes the test cases for valid input
 * and generates the SQL queries for each of the inputs;
 * It outputs directly to the screen.
 * **************************************************/
void testValidCases() {
    for (vector<userpass>::iterator it = validCases.begin(); it != validCases.end(); it++) {
        cout << queryGeneration((*it).username, (*it).password) << "\n";
    }
}


/*****************************************************
 * TEST VULNERABILIES
 *
 * **************************************************/
void testVulnerabilities(string sqlString, vector<userpass> testVector) {

    for (vector<userpass>::iterator it = testVector.begin(); it != testVector.end(); it++) {
        cout << queryGeneration((*it).username, (*it).password) << "\n";
    }

}

/*****************************************************
 * WEAK MITIGATION
 * This function takes a string
 * **************************************************/
void weakMitigation(string checkString, vector<userpass> testVector) {
    int countPassed = 0;
    for (vector<userpass>::iterator it = testVector.begin(); it != testVector.end(); it++) {

        // Check username and password for testcase.
        string originalPass = (*it).password;
        size_t posPassword = string::npos;
        do
        {
            posPassword = (*it).password.find(checkString);
            if (posPassword != string::npos) {
                (*it).password.erase(posPassword, checkString.length());
            }
        } while (posPassword != string::npos);

        string originalUser = (*it).username;
        size_t posUser = string::npos;
        do
        {
            posUser = (*it).username.find(checkString);
            if (posUser != string::npos) {
                (*it).username.erase(posUser, checkString.length());
            }
        } while (posUser != string::npos);

        if (originalPass == (*it).password && originalUser == (*it).username) {
            countPassed++;
        }
        else {
            cout << "Original:  " << queryGeneration(originalUser, originalPass) << "\n";
            cout << "Mitigated: " << queryGeneration((*it).username, (*it).password) << "\n";
        }
    }
    cout << countPassed << " test cases were unchanged.\n\n";
}

/*****************************************************
 * STRONG MITIGATION
 *
 * **************************************************/
void strongMitigation(string attacks[], vector<userpass> testVector)
{
    int countPassed = 0;

    for (vector<userpass>::iterator it = testVector.begin(); it != testVector.end(); it++) {

        // Check username and password for testcase.
        string originalPass = (*it).password;
        size_t posPassword = string::npos;
        string originalUser = (*it).username;
        size_t posUser = string::npos;
        for (size_t i = 0; i < attacks->length(); i++)
        {
            string checkString = attacks[i];
            posPassword = string::npos;
            do
            {
                posPassword = (*it).password.find(checkString);
                if (posPassword != string::npos) {
                    (*it).password.erase(posPassword, checkString.length());
                }
            } while (posPassword != string::npos);

            posUser = string::npos;
            do
            {
                posUser = (*it).username.find(checkString);
                if (posUser != string::npos) {
                    (*it).username.erase(posUser, checkString.length());
                }
            } while (posUser != string::npos);
        }

        if (originalPass == (*it).password && originalUser == (*it).username) {
            countPassed++;
        }
        else {
            cout << "Original:  " << queryGeneration(originalUser, originalPass) << "\n";
            cout << "Mitigated: " << queryGeneration((*it).username, (*it).password) << "\n";
        }
    }
    cout << countPassed << " test cases were unchanged.\n";
}
