#include <iostream>
#include <string>
#include <sstream> //for std::stringstream
#include <cstring>
#include <cassert> // for assert

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
void ansiVulnerability(wchar_t (&entryText)[32]);
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
class Base
{
private:
   char buffer[10];

public:
   virtual void firstMethod()
   {
      printf("%s\n", buffer);
   }
   virtual void secondMethod()
   {
      printf("%s\n", buffer);
   }
   void setBuffer(const char *value)
   {
      printf("%S\n", value);
      strcpy(buffer, value);
   }
};

/*************************************
* Class  Vulnerability
* This class is vulnerable to vtable smashing attack
*************************************/
class Vulnerability : public Base
{
public:
   void firstMethod()
   {
      printf("FirstMeth: ");
      Base::firstMethod();
   }
   void secondMethod()
   {
      printf("SecondMeth: ");
      Base::secondMethod();
   }
};
/*************************************
* Class  Vulnerability
* This class is vulnerable to vtable smashing attack
*************************************/
class Vulnerability1 : public Base
{
public:
   void firstMethod()
   {
      printf("SecondClass: ");
      Base::firstMethod();
   }
   void secondMethod()
   {
      printf("SecondClass: ");
      Base::secondMethod();
   }
};

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   cout << "LAB 08: VULNERABILITIES AND EXPLOITS\n\n";

   int menuOption = 0;

   do
   {
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
      case 8:
         break;
      default:
         cout << "Unkown option\n";
         break;
      }
   } while (menuOption != 8);

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

   /****NOTE: This solution might work in some compilers and in others no. The parameter assign to
   this is '-3'****/
   int array[4];
   bool authen = true;

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
void arrayWorking()
{

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
 * This calls the arc vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
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
   // void *pDangerous = dangerous;
   // stringstream addressToString;
   // addressToString << pDangerous;
   // string address = addressToString.str();

   // // Get the hexadeciaml to int
   // unsigned int x;
   // stringstream ss;
   // ss << std::hex << address;
   // ss >> x;
   // cout << "ARC Vulnerability exploit" << endl;
   // arcVulnerability(x);
}

/*************************************
 * VTABLE WORKING
 * This instances the Vulneravility object and calls
 * the vulnerable method.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void vtableWorking()
{
   Base *instance[2];
   instance[0] = new Vulnerability;
   instance[1] = new Vulnerability1;

   instance[0]->setBuffer("First Buf");
   instance[0]->firstMethod();
   instance[0]->secondMethod();

   instance[1]->setBuffer("Sec Buf");
   instance[1]->firstMethod();
   instance[1]->secondMethod();
}

/**************************************
 * VTABLE EXPLOIT
 * This demonstrade the vtable sprying
 *************************************/
void vtableExploit()
{
   Base *instance[2];
   instance[0] = new Vulnerability;
   instance[1] = new Vulnerability1;

   long spray = (long)&instance[0];
   long spray1 = (long)&instance[1];

   char temp[18] = "First Buf";
   char temp1[10];
   sprintf(temp1, "%d", spray);
   strcat(temp, temp1);
   instance[0]->setBuffer(temp);
   instance[0]->firstMethod();
   instance[0]->secondMethod();

   char temp2[18] = "Second Bu";
   char temp3[10];
   sprintf(temp3, "%d", spray1);
   strcat(temp2, temp3);
   instance[1]->setBuffer(temp2);
   instance[1]->firstMethod();
   instance[1]->secondMethod();
}

/*************************************
* STACK EXPLOITED
* This function replaces a pointer with a cout statement
*************************************/
void exploited()
{
   cout << "exploited" << endl;
}

/*************************************
* STACK VULNERABILITY
* This function contains a stack smashing vulnerability
*************************************/
void stackVulnerability(long int input[], long int size)
{
   long int buffer[1];

   for (long int i = 0; i < size; i++)
   {
      buffer[i] = input[i];
      cout << i << "" << buffer[i] << endl;
   }

   cout << buffer << endl;
}

/*************************************
 * STACK WORKING
 * This calls the stack vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the arc vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void stackWorking()
{
   //this is a short buffer
   long int buffer[1] = {1};

   //The buffer is small but it works
   stackVulnerability(buffer, 1);

   cout << "The buffer is not overloaded!";
}

/**************************************
 * STACK EXPLOIT
 * This calls the the stack vulnerability function
 * and demonstrade the concept of the array vulnerability
 *************************************/
void stackExploit()
{
   //overload the buffer with more than it will hold and add a function pointer to something different
   long int buffer[8] = {0, 7, 4, 8, 9, (long int)&exploited};

   //this is bigger than the buffer can handle
   stackVulnerability(buffer, 8);

   cout << "The buffer has been overloaded!";
}

/*************************************
* HEAP VULNERABILITY
* This function contains a heap smashing vulnerability
*************************************/
void heapVulnerability(stringstream &input)
{
   // create vulnerability
   char *buffer1 = new char[5];
   char *buffer2 = new char[5];

   cout << "buffer1 before: " << *buffer1 << " " << buffer1 << endl;
   cout << "buffer2 before: " << *buffer2 << " " << buffer2 << endl;

   assert(buffer1 < buffer2);

   // get input
   for (int i = 0; !input.eof(); i++)
   {
      input >> buffer1;
   }

   cout << "buffer1 after : " << *buffer1 << " " << buffer1 << endl;
   cout << "buffer2 after : " << *buffer2 << " " << buffer2 << endl;

   // delete second buffer first
   delete[] buffer2;

   // create test input
   stringstream test;
   test.str("test");

   // Try to insert new data into buffer 1 to see if it still works
   for (int i = 0; !test.eof(); i++)
   {
      test >> buffer1;
   }
   delete[] buffer1;
}

/*************************************
 * HEAP WORKING
 * This calls the heap vulneravility function.
 * This does not exploit the vulnerability, but rather
 * demonstrades the heap vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void heapWorking()
{
   cout << "-- Heap Working Test --" << endl;
   stringstream test;
   //test << 't' << 'e' << 's' << 't' << '\n';
   test.str("data");
   heapVulnerability(test);
   // return test;
}

/**************************************
 * HEAP EXPLOIT
 * This calls the the heap vulnerability function
 * and demonstrates heap spraying.
 *************************************/
void heapExploit()
{
   cout << "-- Heap Exploit Test --" << endl;
   stringstream test;
   // test << 't' << 'e' << 's' << 't' << 'b' << 'r' << 'o' << 'k' << 'e' << 'n';
   test.str("brokentest");
   heapVulnerability(test);
}

/*************************************
* INTEGER VULNERABILITY
* 1. There must be a security check represented by an expression.
* 2. The expression must have the potential for overflow.
* 3. At least one of the numbers used to compute the sentinel must be
* reachable through external input. This sentinel is a variable used to make
* the security decision from the first requirement.
*************************************/
void intVulnerability(int input)
{

   // Variable testCase to "simulate" user input #3
   int testCase = input;
   int sentinel = 2147483647;

   // Security check represented by an expression #1
   // Expression has potential for overflow #2
   if (testCase > 0 && testCase < sentinel)
   {
      cout << "Overflow has been avoided!\n"
           << endl;
   }
   else
   {
      cout << "Overflow has occurred!\n"
           << endl;
   }
}

/*************************************
 * INTEGER WORKING
 * Call intVulnerability() in a way that does
 * not yield unexpected behavior
 ************************************/
void integerWorking()
{
   intVulnerability(1000);
}

/**************************************
 * INTEGER EXPLOIT
 * 1. Provide input, either a buffer size or a single value, that is directly or
 * indirectly used in the vulnerable expression.
 * 2. The input must exceed the valid bounds of the data-type, resulting in an
 * overflow or underflow condition
 *************************************/
void intExploit()
{
   intVulnerability(2147483650);
}

/*************************************
* ANSI-UNICODE CONVERSION
* This function is is vulnerable to an ANSI-Unicode attack.
*************************************/
void ansiVulnerability(wchar_t (&entryText)[32])
{
   int vowelCount = 0;

   wcout << "Original Sentence: " << entryText << "\n"
         << "Vowels:            ";
   for (int i = 0; i < sizeof(entryText); i++)
   {
      if (tolower(entryText[i]) == 'a' ||
              tolower(entryText[i]) == 'e' ||
              tolower(entryText[i]) == 'i' ||
              tolower(entryText[i]) == 'o' ||
              tolower(entryText[i]) == 'u')
      {
         wcout << entryText[i];
         vowelCount++;
      }
      else
      {
         wcout << " ";
      }
   }
   wcout << "\n\nYou have " << vowelCount << " vowel(s) in your sentence.\n";
   wcout << "=====================================\n";
}

/*************************************
 * ANSI WORKING
 * This calls the ansi vulneravility function.
 * This do not exploit the vulnerability, but rather
 * demonstrades the heap vulnerability function functions
 * normally under non-malicious input.
 ************************************/
void ansiWorking()
{
   wchar_t vowelSentence[32] = {'T', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a',
                                's', ' ', 'l', 'o', 'n', 'g', ' ', 'a', 's',
                                ' ', 'I', ' ', 'c', 'a', 'n', ' ', 'g', 'e',
                                't', '.'};

   ansiVulnerability(vowelSentence);
}

/**************************************
 * ANSI EXPLOIT
 * This calls the the ansi vulnerability function
 * and demonstrates an ANSI_Unicode attack.
 *************************************/
void ansiExploit()
{
   wchar_t vowelSentence[32] = {'I', ' ', 'a', 'm', ' ', 'a', ' ', 'g', 'r', 'e', 'a', 't', ' ',
                                'h', 'a', 'c', 'k', 'k', 'e', 'r', '!', ' ', 'I', ' ', 'h', 'a', 'v', 'e', ' ', 'b', 'e', 'a'};
       /*    wcout << ((long * ) (&vowelSentence[31]) ) << "\n";
      wcout << (wchar_t) *((long * ) (&vowelSentence[31]) ) << "\n";
      wcout << ((long * ) (&vowelSentence[33]) ) << "\n";
   ​
      wcout << "+1 " << ((long * ) (&vowelSentence[32])+1 ) << "\n";
   ​
      wcout << "+2 " << ((long * ) (&vowelSentence[32])+2 ) << "\n";
      wcout << "+4 " << ((long * ) (&vowelSentence[32])+4 ) << "\n";
    */
       /*    *((long * ) (&vowelSentence[31]) + 1) = 't';
      *((long * ) (&vowelSentence[31]) + 2) = ' ';
      *((long * ) (&vowelSentence[31]) + 3) = 'Y';
      *((long * ) (&vowelSentence[31]) + 4) = 'o';
      *((long * ) (&vowelSentence[31]) + 5) = 'u';
    */

   *((long *)(&vowelSentence[32])) = 't';
   *((long *)(&vowelSentence[33])) = 'e';
   *((long *)(&vowelSentence[34])) = 'n';
   *((long *)(&vowelSentence[35])) = ' ';
   *((long *)(&vowelSentence[36])) = 'Y';
   *((long *)(&vowelSentence[37])) = 'O';
   *((long *)(&vowelSentence[38])) = 'U';
   ansiVulnerability(vowelSentence);
}
