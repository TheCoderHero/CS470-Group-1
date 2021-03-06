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
   virtual std::string getDecryptAuth() { return "Zach Heiner"; }

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
      str += "   INIT alphabet\n";
      str += "   INIT cipherText\n";
      str += "   FOR i is all characters in plainText\n";
      str += "      INIT a <- plainText[i]\n";
      str += "      INIT b <- password[i % sizeOfPassword]\n"; // This will allow the key to repeat
      str += "      INIT begin <- 0\n";
      str += "      FOR j is all characters in alpabet\n";
      str += "         IF alphabet[j] = a\n";
      str += "            begin <- j\n";
      str += "            BREAK\n";
      str += "      INIT offset <- 0\n";
      str += "      FOR k starts at begin and counts to begin + sizeOfAlphabet\n";
      str += "         INIT c <- k % sizeOfAlphabet\n";
      str += "         IF alphabet[c] = b\n";
      str += "            BREAK\n";
      str += "         offset = offset + 1\n";
      str += "      cipherText += alphabet[offset]\n";
      str += "   RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   INIT alphabet\n";
      str += "   INIT plainText\n";
      str += "   FOR i is all letters in cipherText\n";
      str += "      INIT a <- cipherText[i]\n";
      str += "      INIT b <- password[i % sizeOfPassword]\n"; // This will allow the key to repeat
      str += "      INIT begin <- 0\n";
      str += "      FOR j is all letters in alpabet\n";
      str += "         IF alphabet[j] = a\n";
      str += "            begin <- j\n";
      str += "            BREAK\n";
      str += "      INIT offset <- 0\n";
      str += "      FOR k starts at begin and counts to begin + sizeOfAlphabet\n";
      str += "         INIT c <- k % sizeOfAlphabet\n";
      str += "         IF alphabet[c] = b\n";
      str += "            BREAK\n";
      str += "         offset = offset + 1\n";
      str += "      plainText += alphabet[offset]\n";
      str += "   RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string cipherText = "";

      for (int i = 0; i < plainText.length(); i++)
      {
         char a = plainText[i];
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
            offset++;
         }
         cipherText += alphabet[offset];
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string plainText = "";

      for (int i = 0; i < cipherText.length(); i++)
      {
         char a = cipherText[i];
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
            offset++;
         }
         plainText += alphabet[offset];
      }
      return plainText;
   }
};

#endif // CIPHER02_H
