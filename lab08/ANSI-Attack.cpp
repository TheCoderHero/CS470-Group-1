#include <iostream>
#include <string>
#include <sstream> //for std::stringstream
#include <cwchar>
#include <iomanip>


using namespace std;

void ansiVulnerability(wchar_t (&entryText)[32]);
void ansiWorking();
void ansiExploit();

int main() {

   ansiWorking();


   ansiExploit();
   //count the number of vowels
   return 0;
}

/*************************************
* ANSI-UNICODE CONVERSION
* This function is is vulnerable to an ANSI-Unicode attack.
*************************************/
void ansiVulnerability(wchar_t (&entryText)[32]) {

   int vowelCount = 0;
   
   wcout << "Original Sentence: " << entryText << "\n" << "Vowels:            ";

   for(int i = 0; i < sizeof(entryText); i++) {

      if(tolower(entryText[i]) == 'a' ||
        tolower(entryText[i]) == 'e' ||
        tolower(entryText[i]) == 'i' ||
        tolower(entryText[i]) == 'o' ||
        tolower(entryText[i]) == 'u') 
         {
            wcout << entryText[i];
            vowelCount++;
         }else{
            wcout << " ";
         }
   }
   wcout << "\n\nYou have " << vowelCount <<" vowel(s) in your sentence.\n";
   wcout << "=====================================\n";
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
    wchar_t vowelSentence[32] = {'T','h','i','s',' ','i','s',' ','a',
      's',' ','l','o','n','g',' ','a','s',
      ' ','I',' ','c','a','n',' ','g','e',
      't','.'};
      
    ansiVulnerability(vowelSentence);
}

/**************************************
 * ANSI EXPLOIT
 * This calls the the ansi vulnerability function
 * and demonstrates an ANSI_Unicode attack.
 *************************************/
void ansiExploit()
{
   wchar_t vowelSentence[32] = {'I',' ','a','m',' ','a',' ','g','r','e','a','t',' ',
   'h','a','c','k','k','e','r','!',' ','I',' ','h','a','v','e',' ','b','e','a'};

/*    wcout << ((long * ) (&vowelSentence[31]) ) << "\n";
   wcout << (wchar_t) *((long * ) (&vowelSentence[31]) ) << "\n";
   wcout << ((long * ) (&vowelSentence[33]) ) << "\n";

   wcout << "+1 " << ((long * ) (&vowelSentence[32])+1 ) << "\n";

   wcout << "+2 " << ((long * ) (&vowelSentence[32])+2 ) << "\n";
   wcout << "+4 " << ((long * ) (&vowelSentence[32])+4 ) << "\n";
 */
/*    *((long * ) (&vowelSentence[31]) + 1) = 't';
   *((long * ) (&vowelSentence[31]) + 2) = ' ';
   *((long * ) (&vowelSentence[31]) + 3) = 'Y';
   *((long * ) (&vowelSentence[31]) + 4) = 'o';
   *((long * ) (&vowelSentence[31]) + 5) = 'u';
 */
 
   *((long * ) (&vowelSentence[32]) ) = 't';
   *((long * ) (&vowelSentence[33]) ) = 'e';
   *((long * ) (&vowelSentence[34]) ) = 'n';
   *((long * ) (&vowelSentence[35]) ) = ' ';
   *((long * ) (&vowelSentence[36]) ) = 'Y';
   *((long * ) (&vowelSentence[37]) ) = 'O';
   *((long * ) (&vowelSentence[38]) ) = 'U';

   ansiVulnerability(vowelSentence);
}