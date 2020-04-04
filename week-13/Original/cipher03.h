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
   virtual std::string getDecryptAuth() { return "Jordon Thompson"; }

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
      str += "   FOR i in all letters in plainText\n";
      str += "   INIT text = FIND in alphabet, plainText at i\n";
      str += "   INIT pass = FIND in alphabet , password at i % length of password\n";
      str += "   INIT sum = pass + text\n";
      str += "   IF sum >= length of alphabet\n";
      str += "       sum -= length of alphabet\n";
      str += "   cipherText += alphabet at sum";
      str += "   RETURN cipherText\n";

      // The decrypt pseudocode
      str =  "decrypt(cipherText, password\n";
      str += "   INIT alphabet\n";
      str += "   INIT cipherText\n";
      str += "   FOR i in all letters in cipherText\n";
      str += "   INIT text = FIND in alphabet, cipherText at i\n";
      str += "   INIT pass = FIND in alphabet , password at i % length of password\n";
      str += "   INIT sum = text - pass\n";
      str += "   IF sum < 0\n";
      str += "       sum += length of alphabet\n";
      str += "   plainText += alphabet at sum";
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
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      // std::string alphabet = "abcdefghijklmnopqrstuvwxyz";

      for (int i = 0; i < plainText.length(); i++) {
         int text = alphabet.find(plainText[i]);
         int pass = alphabet.find(password[i % password.length()]);
         int sum = text + pass;
         if (sum >= alphabet.length()) {
            sum -= alphabet.length();
         }
         cipherText += alphabet[sum];
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * This function takes cipher text and a password. for each
    * cipherText and password character it gets the index value
    * of the char from the alphabet. Then subtract password int
    * from the cipherText int. check alphabet size and then add
    * result to plainText. 
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
                               const std::string & password)
   {
      std::string plainText = "";
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";

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
