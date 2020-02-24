#include <iostream>
#include <string>
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
    cout << "  2.  Pointer Subterfuge\n";
    cout << "  3.  ARC Injection\n";
    cout << "  4.  VTable Spraying\n";
    cout << "  5.  Stack Smashing\n";
    cout << "  6.  Heap Spraying\n";
    cout << "  7.  Integer Overflow\n";
    cout << "  8.  ANSI-Unicode Conversion\n";

    int selection;
    cin >> selection;

    switch (selection) {
    case 1: arrayWorking(); arrayExploit();
        break;
    case 2:;
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
    //cout << "The array vulnerability:" << &array[-3] << endl;
    //cout << "The array vulnerability:" << &array[-2] << endl;
    //cout << "The array vulnerability:" << &array[-1] << endl;
    //cout << "The array vulnerability:" << &array[0] << endl;
    //cout << "The array vulnerability:" << &array[1] << endl;
    //cout << "The array vulnerability:" << &array[2] << endl;
    //cout << "The array vulnerability:" << &array[3] << endl;
    //cout << "The array vulnerability:" << &array[4] << endl;


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
* This function is vulnerable to the ARC injection attack
*************************************/
void arcVulnerability() {

}

/*************************************
 * ARC WORKING
 * This calls the arc vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void  arcWorking() {

}

/**************************************
 * ARC EXPLOIT
 * This calls the the arc vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void arcExploit() {

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
