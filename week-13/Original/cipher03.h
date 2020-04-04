/********************************************************************
* Header:
*   Vernam Cipher
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H
#include <string>
#include "cipher.h"
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Zach Heiner"; }
   virtual std::string getCipherName()  { return "Vernam Cipher"; }
   virtual std::string getEncryptAuth() { return "Aaron Eiche"; }
   virtual std::string getDecryptAuth() { return "Jordan Thompson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Geeksforgeeks.com,";
      s += "\"Vernam Cipher in Cryptography \",\n   retrieved: ";
      s += "https://www.geeksforgeeks.org/vernam-cipher-in-cryptography/?ref=rp";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      str =  "encrypt(plainText, password\n";
      str += "   INIT alphabet\n";
      str += "   INIT cipherText\n";
      str += "   IF sizeOfPassword <= sizeOfPlainText \n";
      str += "      PROMPT for newPassword\n";
      str += "   FOR i in all letters in plainText\n";
      str += "      cipherText[i] = plainText[i] ^ password[j]\n";
      str += "      j++\n";
      str += "      IF j >= sizeOFPassword\n";
      str += "         j = 0\n";
      str += "   RETURN cipherText\n";

      // The decrypt pseudocode
      str =  "decrypt(cipherText, password\n";
      str += "   INIT alphabet\n";
      str += "   INIT plainText\n";
      str += "   FOR i in all letters in cipherText\n";
      str += "      plainText[i] = cipherText[i] ^ password[j]\n";
      str += "      j++\n";
      str += "      IF j >= sizeOFPassword\n";
      str += "         j = 0\n";
      str += "   RETURN plainText\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText = "";
      // std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

      for (int i = 0; i < plainText.length(); i++) {
         int text = alphabet.find(plainText[i]);
         int pass = alphabet.find(password[i % password.length()]);
         int sum = pass + text;
         if (sum > alphabet.length()) {
            sum -= alphabet.length();
         }
         cipherText += alphabet[sum];
      }
      // std::string cipherText = plainText;
      // // TODO - Add your code here
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
      // std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

      for (int i = 0; i < cipherText.length(); i++) {
         int text = alphabet.find(cipherText[i]);
         int pass = alphabet.find(password[i % password.length()]);
         int sum = text - pass;
         if (sum < 0) {
            sum += alphabet.length();
         }
         plainText += alphabet[sum];
      }

      return plainText;
   }
};

#endif // CIPHER03_H
