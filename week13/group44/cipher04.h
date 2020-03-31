/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Cal Wilson"; }
   virtual std::string getCipherName() { return "Autokey Cipher"; }
   virtual std::string getEncryptAuth() { return "John Soon"; }
   virtual std::string getDecryptAuth() { return "Ben Fisher"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "PracticalCryptography.com, ";
      citation += "\"Practical Cryptograph - Autokey Cipher\", \n  retrieved: ";
      citation += "http://practicalcryptography.com/ciphers/autokey-cipher/";
      return citation;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str = "encrypt(plainText, key)\n";
      str += "   IF key length is less than plaintext length\n";
      str += "      key = buildKey(key, plainText)\n";
      str += "   cipherText = buildCipherText(key, plainText)\n";
      str += "   RETURN cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, key)\n";
      str += "   plainText = buildPlainText(key, cipherText, alphabet)\n";
      str += "   RETURN plainText\n\n";

      // Build the rest of the key if it is smaller than the plaintext
      str += "buildKey(key, plainText)\n";
      str += "   FOR i is all the values in plainText WHILE length of plainText != length of key INCREMENT i by 1\n";
      str += "      key += *i\n";
      str += "   RETURN key\n\n";

      // Build the cypherText
      str += "buildCipherText(key, plainText)\n";
      str += "   cipherText = \"\"\n";
      str += "   FOR i is the current index of plainText\n";
      str += "      ascii += (plainText[i] + key[i]) % 26\n";
      str += "      ascii += 'A'\n";
      str += "      cipherText += ascii\n";
      str += "   RETURN cipherText\n\n";

      // Build the plainText
      str += "buildPlainText(key, cipherText, alphabet)\n";
      str += "   plainText = \"\"\n";
      str += "   FOR i is the current index of cipherText\n";
      str += "      ascii += (cipherText[i] - key[i] + 26) % 26\n";
      str += "      ascii += 'A'\n";
      str += "      plainText += ascii\n";
      str += "      IF length of key != length of cipherText\n";
      str += "         key += ascii\n";
      str += "   RETURN plainText\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string cipherText;
      std::string key = password;
      // TODO - Add your code here
      if(key.length() < plainText.length())
      {
          key = buildKey(password, plainText);  
      }
      cipherText = buildCipherText(key, plainText);
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
//      std::string plainText = buildPlainText(password, cipherText);
      std:: string plainText = cipherText;
      return plainText;
   }

   /**********************************************************
    * BUILDKEY
    * TODO: ADD description
    **********************************************************/
   std::string buildKey(const std::string &password, const std::string &plainText)
   {
      std::string key = password;
      for (int i = 0; plainText.length() < key.length(); i++)
      {
         key += plainText[i];
      }
      return key;
   }

   /**********************************************************
    * BUILDCIPHERTEXT
    * TODO: ADD description
    **********************************************************/
   std::string buildCipherText(const std::string &password, const std::string &plainText)
   {
      std::string cipherText = "";
      std::string ascii = "";
      for (int i = 0; i < plainText.length(); i++)
      {
         ascii += (plainText[i] + password[i]) % 26;
         ascii += "A";
         cipherText += ascii;
      }
      return cipherText;
   }


   /**********************************************************
    * BUILDPLAINTEXT
    * TODO: ADD description
    **********************************************************/
/*   std::string buildPlainText(const std::string &password, const std::string &cipherText)
   {
      std::string plainText = "";
      std::string ascii= "";
      for (int i = 0; i < cipherText.length(); i++)
      {
         ascii += (cipherText[i] + password[i]) % 26;
         ascii += "A";
         plainText += ascii;
      }

      return plainText;
   }
*/ 
};

#endif // CIPHER04_H
