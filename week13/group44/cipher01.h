/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include "cipher.h"
#include <map>
#include <string>


// Original alphabet
std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Christopher Lujo"; }
   virtual std::string getCipherName()  { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Astrid Vargas"; }
   virtual std::string getDecryptAuth() { return "John Soon"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Practicalcryptography.com";
      s += "PracticalCryptography - Simple Substitution Cipher";
      s += "http://practicalcryptography.com/ciphers/simple-substitution-cipher/";
      return s;
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
      str =  "encrypt(key)\n";
      str += "bool array <-- {}\n";
      str += "FOR i < key size\n\n";
      str += "IF i >='A' && i <= 'Z'\n";
      str += "IF i - 65 == 0\n";
      str += "encoded += i\n";
      str += "ELSE IF i >= 'a' && i <= 'z'\n";
      str += "IF i - 97 == 0\n";
      str += "encoded += i - 32\n";
      str += "FOR i < 26";
      str += "IF i == 0";
      str += "i == 1";
      str += "RETURN encoded";

      // The decrypt pseudocode
      str += "FOR i < encoded.size";
      str += "string deciper = """;
      str += "FOR i < message.size";
      str += "IF message >= 'a' && i <= 'z'";
      str += "deciper += plaintext";
      str += "RETURN deciper";

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

	   // Cipher the message
	   for (int i = 0; i < plainText.size(); i++)
	   {
		   if (plainText[i] >= 'a' && plainText[i] <= 'z')
		   {
			   int pos = plainText[i] - 97;
			   cipherText += password[pos];
		   }
		   else if (plainText[i] >= 'A' && plainText[i] <= 'Z')
		   {
			   int pos = plainText[i] - 65;
			   cipherText += password[pos];
		   }
		   else
		   {
			   cipherText += plainText[i];
		   }
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
      
      // code goes here

      return plainText;
   }
   
   /**********************************************************
    * ENCODER
    * TODO: ADD description
    **********************************************************/
   std::string encoder(std::string key)
   {
	   std::string encoded = "";
	   bool arr[26] = {0};

	   // Key and alphabet Merge!!
	   for (int i = 0; i < key.size(); i++)
	   {
		   if(key[i] >= 'A' && key[i] <= 'Z')
		   {
			   // Check repetition
			   if (arr[key[i] - 65] == 0)
			   {
				   encoded += key[i];
				   arr[key[i] - 65] = 1;
			   }
		   }
		   else if (key[i] >= 'a' && key[i] <= 'z')
		   {
			   if (arr[key[i] - 97] == 0)
			   {
				   encoded += key[i] - 32;
				   arr[key[i] - 97] = 1;
			   }
		   }
	   }

	   // Push the rest
	   for (int i = 0; i < 26; i++)
	   {
		   if(arr[i] == 0)
		   {
			   arr[i] = 1;
			   encoded += char(i + 65);
		   }
	   }
	   return encoded;
   }

};

#endif // CIPHER01_H
