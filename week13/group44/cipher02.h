/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H
#include <iostream>
#include <string>
#include <locale>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Astrid Vargas"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Chris Lujo"; }
   virtual std::string getDecryptAuth() { return "Cal Wilson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "PracticalCyrptography.com (2012)";
      citation += "\"Vigenère and Gronsfeld Cipher\", \n retrieved: ";
      citation += "http://practicalcryptography.com/ciphers/classical-era/vigenere-gronsfeld-and-autokey/";
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
      str += "encrypt(message, key)\n";
      str += "   string cipherText";
      str += "   FOR i is zero, less than message size and i++\n";
      str += "      x <- (message[i] plus key[i]) mod 26\n";
      str += "      x += \'A\' (ASCII) \n";
      str += "      cipherText <- pushback x\n";
      str += "RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, key)\n";
      str += "   string decryptedText\n";
      str += "   FOR i is zero and less than decryptedText size and i++\n";
      str += "      x <- (cipherText[i] - key[i] + 26) % 26\n";
      str += "      x += \'A\' (ASCII)\n";
      str += "      decryptedText <- pushback x\n";
      str += "RETURN decryptedText";

      // Generate Key helper function
      str += "generateKey(string message, string key)\n";
      str += "   FOR i is zero and i++\n";
      str += "   if the size of the message is equal to i \n";
      str += "      i = 0\n";
      str += "   If the size of the key it's equal to the size of the message stop";
      str += "   push k[i] to key";
      str += "RETURN key";

      return str;
   }

   /**********************************************************
   * ENCRYPT
   * This function returns the encrypted text using the key
   * string. It only works with uppercase
   **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;

      for (int i = 0; i < plainText.size(); i++) 
      { 
         // converting in range 0-25 
         int x = (plainText[i] + password[i]) % 26; 
  
         // convert into alphabets(ASCII) 
         x += 'A'; 
  
         cipherText.push_back(x); 
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
      std::string plainText;
      
      for (int i = 0 ; i < cipherText.size(); i++) 
      { 
         // converting in range 0-25 
         int x = (cipherText[i] - password[i] + 26) % 26;
  
         // convert into alphabets(ASCII) 
         x += 'A'; 
         plainText.push_back(x); 
      } 
      return plainText;
   }

   /**********************************************************
   * GENERATE KEY
   * This function generates the key several times until its
   * lenght isn't equal to the original message.
   **********************************************************/
   std::string generateKey(std::string message, std::string key) 
   { 
      for (int i = 0; ; i++) 
      { 
         if (message.size() == i) 
            i = 0; 
         if (key.size() == message.size()) 
            break; 
         key.push_back(key[i]); 
      } 
   
      return key;
   }
};

#endif // CIPHER02_H
