/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#include <cassert>
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Whitney Chase"; }
   virtual std::string getCipherName()  { return "Affine cipher"; }
   virtual std::string getEncryptAuth() { return "Heather Mason"; }
   virtual std::string getDecryptAuth() { return "Tori Fife"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "LearnCryptography.com (2016), ";
      citation += "\"Learn Cryptography - Affine Cipher\', \n   retrieved: ";
      citation += "https://learncryptography.com/classical-encryption/affine-cipher";
      return citation;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str += "encryptMessage(plainText, password)\n";
      str +=  "\n";
      str += "  FOR  each character of the str\n";
      str += "    IF the character in the str is not a space\n";
      str += "       str + (((keyA * single character in str) + keyB) % alphabet size)\n";
      str += "    ELSE str += single character in str\n";
      str += "return str\n";



      // The decrypt pseudocode
      str += "decryptMessage(plainText, password)\n";
      str += "\n";
      str += "For i is less than alphabet size\n";
      str += "   int value = ((keyA * i) % alphabet size)\n";
      str += "   IF value == 1\n";
      str += "     int inverse = i\n";
      str += "FOR each character of the str\n";
      str += "     If the character is not a space\n";
      str += "     newStr + cast to a character (( inverse * (( character in str - keyB)) % alphabet size))\n";
      str += "  ELSE newStr += character of the str\n";
      str += "return newStr\n";

      //the code for the keyB
      str += "getKeyB(&password)\n";
      str += "  key = 0\n";
      str += "  FOR the length of the password\n";
      str += "    key += character in password\n";
      str += "  key = key mod alphabet size\n";
      str += "  IF key is 0\n";
      str += "    key = 1\n";
      str += "retun key\n";


      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Uses a common key A, and derives a key B from the password
    * Loops through the plaintext to encrypt each character using
    * both the keys.
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      int alphabetSize = 26;
      int keyA = 5;
      int keyB = getKeyB(password);

      std::string cipherText = "";
      for (int i = 0; i < plainText.length(); i++)
      {
         if (plainText[i] != ' ')
         {
            char newChar = (char)((((keyA * (plainText[i] - 'A')) + keyB) % alphabetSize) + 'A');
            cipherText += newChar;
         }
         else cipherText += plainText[i];
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
      int alphabetSize = 26;
      int keyA = 5;
      int keyB = getKeyB(password);
      int inverse = 0;
      //find the inverse of keyA
      for (int i = 0; i < alphabetSize; i++)
      {
         if(((keyA * i) % alphabetSize) == 1)
         {
            inverse = i;
         }
      }
      //decrypt the message
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText[i] != ' ')
         {
            char newChar = (char)((inverse * (toupper(cipherText[i]) + 'A' - keyB) % alphabetSize) + 'A');
            plainText.push_back(newChar);
         }
         else
         {
            plainText.push_back(cipherText[i]);
         }
      }
      return plainText;
   }
   /**********************************************************
    * getKeyB
    * takes the password and converts it into an int to use as
    * keyB
    **********************************************************/
   int getKeyB(const std::string &password)
   {
      int key = 0;
      for (int i = 0; i < password.length(); i++)
      {
         key += password[i];
      }
      key = key % 26;
      if (key == 0)
      {
         key = 1;
      }
      return key;
   }
};


#endif // CIPHER01_H
