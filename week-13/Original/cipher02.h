/********************************************************************
* Header:
*    Beaufort Cipher
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <string>
#include "cipher.h"
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "pseudocode author"; }
   virtual std::string getCipherName()  { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "PracticalCryptography.com,";
      s += "\"Practical Cryptography - Beaufort Cipher \",\n   retrieved: ";
      s += "http://practicalcryptography.com/ciphers/beaufort-cipher/";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   RETURN beaufort(plainText, password)\n\n";
     
      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   RETURN beaufort(cipherText, password)\n\n";

      // beaufort cipher algorithm
      str += "beaufort(text, password)\n";
      str += "   INIT alphabet\n";
      str += "   INIT output\n";
      str += "   text <- change text to all uppercase\n";
      str += "   password <- change password to all uppercase\n";
      str += "   FOR i is all letters in text\n";
      str += "      INIT a <- text[i]\n";
      str += "      INIT b <- password[i \% sizeOfPassword]\n";
      str += "      INIT begin <- 0\n";
      str += "      FOR j is all letters in alpabet\n"; 
      str += "         IF alphabet = a\n";
      str += "            begin <- j\n";
      str += "            BREAK\n";
      str += "      INIT offset <- 0\n";
      str += "      FOR k starts at begin and counts to begin + sizeOfAlphabet\n";
      str += "         INIT c <- k \% sizeOfAlphabet\n";
      str += "         IF alphabet[c] = b\n";
      str += "            BREAK\n";
      str += "         offset = offset + 1\n";
      str += "      output += alphabet[offset]\n";
      str += "   RETURN output\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER02_H
