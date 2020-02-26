#include <iostream>
#include <string>
#include <sstream> //for std::stringstream

using namespace std;

void arrayVulnerability(int param);
void arrayWorking();
void arrayExploit();
void arcVulnerability();
void arcWorking();
void arcExploit();
void vtableWorking();
void vtableExploit();
void stackVulnerability();
void stackWorking();
void stackExploit();
void heapVulnerability();
void heapWorking();
void heapExploit();
void intVulnerability(int input);
void integerWorking();
void intExploit();
void ansiVulnerability();
void ansiWorking();
void ansiExploit();

// Utilities
void safe();
void dangerous();
int convert(char num[]);

/*************************************
* Class  Vulnerability
* This class is vulnerable to vtable smashing attack
*************************************/
class Vulnerability
{
public:
    void firstMethod()
    {
        cout << "First Method\n";
    }

    void secondMethod()
    {
        cout << "Second Method\n";
    }
};

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
    cout << "LAB 08: VULNERABILITIES AND EXPLOITS\n\n";

    int menuOption = 0;

    do {
        // prompt
        cout << "\nPlease choose from the following menu items:\n\n";
        cout << "  1.  Array Index Attack\n";
        cout << "  2.  ARC Injection\n";
        cout << "  3.  VTable Spraying\n";
        cout << "  4.  Stack Smashing\n";
        cout << "  5.  Heap Spraying\n";
        cout << "  6.  Integer Overflow\n";
        cout << "  7.  ANSI-Unicode Conversion\n";
        cout << "  8.  EXIT PROGRAM\n\n";
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

        switch (menuOption)
        {
        case 1:
            arrayWorking();
            arrayExploit();
            break;
        case 2:
            arcWorking();
            arcExploit();
            break;
        case 3:
            vtableWorking();
            vtableExploit();
            break;
        case 4:
            stackWorking();
            stackExploit();
            break;
        case 5:
            heapWorking();
            heapExploit();
            break;
        case 6:
            integerWorking();
            intExploit();
            break;
        case 7:
            ansiWorking();
            ansiExploit();
            break;
        default:
            cout << "Unkown option\n";
            return 1;
        }
    } while( menuOption != 8 );

    return 0;
}

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ************************************/
void arrayVulnerability(int param)
{

    /****NOTE: This solution might work on some compilers and fail on others. The parameter assign to
    this is '-3'****/
    int array[4];
    bool authen = true;

    cout << "The Boolean 'authen' variable before being assign to the array: " << authen << endl;

    array[param] = false; // If param == 4 or > 4, then it creates a problem.
    cout << "The Boolean 'authen' variable after being assign to the array: " << authen << endl;
}

/*************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 ************************************/
void arrayWorking()
{

    cout << "Array Working as expected\n";
    arrayVulnerability(2);
}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
    cout << "Array with vulnerability\n";
    arrayVulnerability(-3);
}

/*************************************
* ARC VULNERABILITY
* This function is vulnerable to the ARC injection attack.
* There must be a function pointer used in the code.
* Through some vulnerability, there must be a way for user input to
* overwrite the function pointer.
* After the memory is overwritten, the function pointer must be
* dereferenced.
*************************************/
void arcVulnerability(int param)
{

    long buffer[1];
    void (*pointerFunction)() = safe;
    cout << "Input: " << param << endl;

    // We don't want to overwrite the original function
    // This is for demonstration purposes.
    if (param > 100)
    {
        buffer[-3] = param;
    }

    pointerFunction();
}

void safe()
{
    cout << "This is a safe function" << endl;
}

void dangerous()
{

    cout << "This is a dangerous function" << endl;
}

//convert hexadecimal to decimal
int convert(char num[])
{
    int len = strlen(num);
    int base = 1;
    int temp = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] >= '0' && num[i] <= '9')
        {
            temp += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F')
        {
            temp += (num[i] - 55) * base;
            base = base * 16;
        }
    }
    return temp;
}

/*************************************
 * ARC WORKING
 * This calls the arc vulnerability function.
 * This do not exploit the vulnerability, but rather
 * demonstrates the arc vulnerability function executes
 * normally under non-malicious input.
 ************************************/
void arcWorking()
{

    /* NO WORKING YET*/
    cout << "ARC Vulnerability working" << endl;
    arcVulnerability(1);
}

/**************************************
 * ARC EXPLOIT
 * This calls the the arc vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void arcExploit()
{

    void *pDangerous = dangerous;
    stringstream addressToString;
    addressToString << pDangerous;
    string address = addressToString.str();

    // Get the hexadeciaml to int
    unsigned int x;
    stringstream ss;
    ss << std::hex << address;
    ss >> x;
    cout << "ARC Vulnerability exploit" << endl;
    arcVulnerability(x);
}

/*************************************
 * VTABLE WORKING
 * This instances the vulnerability object and calls
 * the vulnerable method.
 * This do not exploit the vulnerability, but rather
 * demonstrates the arc vulnerability function executes
 * normally under non-malicious input.
 ************************************/
void vtableWorking()
{
    Vulnerability instance;
    instance.firstMethod();
}

/**************************************
 * VTABLE EXPLOIT
 * This demonstrade the vtable sprying
 *************************************/
void vtableExploit()
{
}

/*************************************
* STACK VULNERABILITY
* This function contains a stack smashing vulnerability
*************************************/
void stackVulnerability()
{
}

/*************************************
 * STACK WORKING
 * This calls the stack vulnerability function.
 * This do not exploit the vulnerability, but rather
 * demonstrates the arc vulnerability function executes
 * normally under non-malicious input.
 ************************************/
void stackWorking()
{
}

/**************************************
 * STACK EXPLOIT
 * This calls the the stack vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void stackExploit()
{
}

/*************************************
* HEAP VULNERABILITY
* This function contains a heap smashing vulnerability
*************************************/
void heapVulnerability()
{
}

/*************************************
 * HEAP WORKING
 * This calls the heap vulnerability function.
 * This do not exploit the vulnerability, but rather
 * demonstrates the heap vulnerability function executes
 * normally under non-malicious input.
 ************************************/
void heapWorking()
{
}

/**************************************
 * HEAP EXPLOIT
 * This calls the the heap vulnerability function
 * and demonstrates heap spraying.
 *************************************/
void heapExploit()
{
}

/*************************************
* INTEGER VULNERABILITY
* 1. There must be a security check represented by an expression.
* 2. The expression must have the potential for overflow.
* 3. At least one of the numbers used to compute the sentinel must be
* reachable through external input. This sentinel is a variable used to make
* the security decision from the first requirement.
*************************************/
void intVulnerability(int input){

    // Variable testCase to "simulate" user input #3
    int testCase = input;
    int sentinel = 2147483647;

    // Security check represented by an expression #1
    // Expression has potential for overflow #2
    if (testCase > 0 && testCase < sentinel) {
        cout << "Overflow has been avoided!\n" << endl;
    }
    else {
        cout << "Overflow has occurred!\n" << endl;
    }
}

/*************************************
 * INTEGER WORKING
 * Call intVulnerability() in a way that does
 * not yield unexpected behavior
 ************************************/
void integerWorking(){
    intVulnerability(1000);
}

/**************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value, that is directly or
 * indirectly used in the vulnerable expression.
 * 2. The input must exceed the valid bounds of the data-type, resulting in an
 * overflow or underflow condition
 *************************************/
void intExploit(){
    intVulnerability(2147483650);
}

/*************************************
* ANSI-UNICODE CONVERSION
* This function is is vulnerable to an ANSI-Unicode attack.
*************************************/
void ansiVulnerability()
{
}

/*************************************
 * ANSI WORKING
 * This calls the ansi vulnerability function.
 * This do not exploit the vulnerability, but rather
 * demonstrates the heap vulnerability function executes
 * normally under non-malicious input.
 ************************************/
void ansiWorking()
{
}

/**************************************
 * ANSI EXPLOIT
 * This calls the the ansi vulnerability function
 * and demonstrates an ANSI_Unicode attack.
 *************************************/
void ansiExploit()
{
}
