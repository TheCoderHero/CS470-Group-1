#include <iostream>
#include <string>
#include <sstream> //for std::stringstream 

using namespace std;

void arrayVulnerability(int param);
void arrayWorking();
void arrayExploit();
void arcVulnerability();
void  arcWorking();
void arcExploit();
void  vtableWorking();
void vtableExploit();
void stackVulnerability();
void  stackWorking();
void stackExploit();
void heapVulnerability();
void  heapWorking();
void heapExploit();
void intVulnerability();
void  integerWorking();
void intExploit();
void ansiVulnerability();
void  ansiWorking();
void ansiExploit();

// Utilities
void safe();
void dangerous();
int convert(char num[]);

/*************************************
* Class  Vulnerability
* This class is vulnerable to vtable smashing attack
*************************************/
class Vulnerability {
public:
    void firstMethod() {
        cout << "First Method\n";
    }

    void secondMethod() {
        cout << "Second Method\n";
    }
};


/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{

    // prompt
    cout << "Please select an option:\n";
    cout << "  1.  Array Index Attack\n";
    cout << "  2.  ARC Injection\n";
    cout << "  3.  VTable Spraying\n";
    cout << "  4.  Stack Smashing\n";
    cout << "  5.  Heap Spraying\n";
    cout << "  6.  Integer Overflow\n";
    cout << "  7.  ANSI-Unicode Conversion\n";

    int selection;
    cin >> selection;

    switch (selection) {
    case 1: arrayWorking(); arrayExploit();
        break;
    case 2: /*arcWorking();*/ arcExploit();
        break;
    default:
        cout << "Unkown option\n";
        return 1;

    }

    return 0;


}


/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ************************************/
void arrayVulnerability(int param) {

    /****NOTE: This solution might work in some compilers and in others no. The parameter assign to
    this is '-3'****/
    int array[4];
    bool  authen = true;

    cout << "The Boolean 'authen' variable before being assign to the array: " << authen << endl;

    array[param] = false; // If param ==4 or >4, problems.
    cout << "The Boolean 'authen' variable after being assign to the array: " << authen << endl;



}

/*************************************
 * ARRAY WORKING
 * This calls the array vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the array vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void arrayWorking() {

    cout << "Array Working as expected\n";
    arrayVulnerability(2);

}

/**************************************
 * ARRAY EXPLOIT
 * This calls the the array vulnerability function
 * and demonstrade the concept of the array vulnerability
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
void arcVulnerability(int param) {

    /** WORKING ON THIS */
    long buffer[1];
    void(*pointerFunction)() = safe;

    //cout << "Address of the dangerous function: " << *dangerous << endl;
    //cout << "Address of the safe function: " << *safe << endl;
    //cout << "Address of the pointer function safe: " << (void*)pointerFunction << endl;
    //cout << "Address of the pointer function: " << &pointerFunction << endl;

    //cout << "Buffer 0: " << &buffer[-3] << endl;
    //cout << "Buffer 1: " << &buffer[1] << endl;
    cout << "Input: " << param << endl;
    buffer[-3] = param;

    pointerFunction();



}

void safe() {
    cout << "This is a safe function" << endl;
}

void dangerous() {

    cout << "This is a dangerous function" << endl;

}

//convert hexadecimal to decimal
int convert(char num[]) {
    int len = strlen(num);
    int base = 1;
    int temp = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            temp += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F') {
            temp += (num[i] - 55) * base;
            base = base * 16;
        }
    }
    return temp;
}

/*************************************
 * ARC WORKING
 * This calls the arc vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  arcWorking() {

    /* NO WORKING YET*/
    cout << "ARC Vulnerability working" << endl;
    arcVulnerability(1);

}

/**************************************
 * ARC EXPLOIT
 * This calls the the arc vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void arcExploit() {

    void* pDangerous = dangerous;
    stringstream addressToString;
    addressToString << pDangerous;
    string address = addressToString.str();
    /* cout << address << endl;*/

     // Get the hexadeciaml to int
    unsigned int x;
    stringstream ss;
    ss << std::hex << address;
    ss >> x;
    //cout << "The address :" << x << endl;
    cout << "ARC Vulnerability exploit" << endl;
    arcVulnerability(x);
}


/*************************************
 * VTABLE WORKING
 * This instances the Vulneravility object and calls
 * the vulnerable method.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  vtableWorking() {
    Vulnerability instance;
    instance.firstMethod();
}

/**************************************
 * VTABLE EXPLOIT
 * This demonstrade the vtable sprying
 *************************************/
void vtableExploit() {

}

/*************************************
* STACK VULNERABILITY
* This function contains a stack smashing vulnerability
*************************************/
void stackVulnerability() {

}

/*************************************
 * STACK WORKING
 * This calls the stack vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  stackWorking() {

}

/**************************************
 * STACK EXPLOIT
 * This calls the the stack vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void stackExploit() {

}

/*************************************
* HEAP VULNERABILITY
* This function contains a heap smashing vulnerability
*************************************/
void heapVulnerability() {

}

/*************************************
 * HEAP WORKING
 * This calls the heap vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the heap vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  heapWorking() {

}

/**************************************
 * HEAP EXPLOIT
 * This calls the the heap vulnerability function
 * and demonstrates heap spraying.
 *************************************/
void heapExploit() {

}

/*************************************
* INTEGER OVERFLOW
* This function is vulnerable to an integer overflow attack
*************************************/
void intVulnerability() {

}

/*************************************
 * INTEGER WORKING
 * This calls the integer vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the heap vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  integerWorking() {

}

/**************************************
 * INTEGER EXPLOIT
 * This calls the the integer vulnerability function
 * and demonstrates integer overflow attack.
 *************************************/
void intExploit() {

}

/*************************************
* ANSI-UNICODE CONVERSION
* This function is is vulnerable to an ANSI-Unicode attack.
*************************************/
void ansiVulnerability() {

}

/*************************************
 * ANSI WORKING
 * This calls the ansi vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the heap vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  ansiWorking() {

}

/**************************************
 * ANSI EXPLOIT
 * This calls the the ansi vulnerability function
 * and demonstrates an ANSI_Unicode attack.
 *************************************/
void ansiExploit() {

}
