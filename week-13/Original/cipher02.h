/********************************************************************
* Header:
*    Beaufort Cipher
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <string>
#include <cctype>
#include "cipher.h"
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Jordon Thompson"; }
   virtual std::string getCipherName() { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Collin Steel"; }
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
      str = "encrypt(plainText, password)\n";
      str += "   RETURN beaufort(plainText, password)\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   RETURN beaufort(cipherText, password)\n\n";

      // beaufort cipher algorithm
      str += "beaufort(text, password)\n";
      str += "   INIT alphabet\n";
      str += "   INIT output\n";
      str += "   FOR i is all letters in text\n";
      str += "      INIT a <- text[i]\n";
      str += "      INIT b <- password[i \% sizeOfPassword]\n"; // This will allow the key to repeat
      str += "      INIT begin <- 0\n";
      str += "      FOR j is all letters in alpabet\n";
      str += "         IF alphabet[i] = a(changed to lowercase)\n";
      str += "            begin <- j\n";
      str += "            BREAK\n";
      str += "      INIT offset <- 0\n";
      str += "      FOR k starts at begin and counts to begin + sizeOfAlphabet\n";
      str += "         INIT c <- k \% sizeOfAlphabet\n";
      str += "         IF alphabet[c] = b(changed to lowercase)\n";
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
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText = beaufort(plainText, password);
      
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText = beaufort(cipherText, password);

      return plainText;
   }

   virtual std::string beaufort(const std::string &text,
                                const std::string &password)
   {
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string output = "";

      for (int i = 0; i < text.length(); i++)
      {
         char a = text[i];
         char b = password[i % password.length()];
         int begin = 0;
         for (int j = 0; j < alphabet.length(); j++)
         {
            if (alphabet[j] == a)
            {
               begin = j;
               break;
            }
         }
         int offset = 0;
         for (int k = begin; k < (begin + alphabet.length()); k++)
         {
            int c = k % alphabet.length();
            if (alphabet[c] == b)
            {
               break;
            }
            offset = offset++;
         }
         output += alphabet[offset];
         
      }
      return output;
      
   }
};

#endif // CIPHER02_H
