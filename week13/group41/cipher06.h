/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#include <string>
#include <cassert>
#ifndef CIPHER06_H
#define CIPHER06_H


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Heather Mason"; }
   virtual std::string getCipherName()  { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Whitney Chase"; }
   virtual std::string getDecryptAuth() { return "Ashley Loo"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "LearnCryptography.com (2016), ";
      citation += "\"Learn Cryptography - Vigenere Cipher\', \n   retrieved: ";
      citation += "https://learncryptography.com/classical-encryption/vigenere-cipher";
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
      // The encrypt pseudocod
      str =  "encrypt(plainText, password)\n";
      str += "   key = prepareKey(plainText, password)\n";
      str += "   FOR each character of plaintext\n";
      str += "      index = getEOffset(char of plaintext, char of key)\n";
      str += "      cipherText += charFromindex(index)\n";
      str += "   RETURN cipherText\n";
      str += "\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   key = prepareKey(cipherText, password)\n";
      str += "   FOR each character of cipherText\n";
      str += "      index = getDOffset(char of ciphertext, char of key)\n";
      str += "      cipherText += charFromindex(index)\n";
      str += "   RETURN cipherText\n";

      //the getEOffset function
      str += "getEOffset(pText, kText)\n";
      str += "   offset = (index of pText + index of kText) % alphabet size \n";
      str += "   return offset\n";

      //the getDOffset function
      str += "getEOffset(cText, kText)\n";
      str += "   offset = (index of cText - index of kText) % alphabet size \n";
      str += "   return offset\n";

      //the prepareKey function
      str += "prepareKey(text, password)\n";
      str += "   if password.length < text.length\n";
      str += "      key = password\n";
      str += "      key += password chars till length = text.length\n";
      str += "   if password.length > text.length\n";
      str += "      key += password chars till length = text.length\n";
      str += "   RETURN key\n";
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
      std::string key;

      key = prepareKey(plainText, password);
      for (int index = 0; index < plainText.length(); index++)
      {
        (char)index = getEOffset(plainText, key);
        cipherText += plainText[index];
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
      std::string key = prepareKey(cipherText, password);
      for (int index = 0; index < cipherText.length(); index++)
      {
        (char)index = getDOffset(cipherText, key);
        plainText += cipherText[index];
      }
      return plainText;
   }

  private:
    /**********************************************************
    * getEOffset
    * TODO: ADD description
    **********************************************************/
    std::string getEOffset(std::string pText, std::string kText)
    {
      std::string offset;

      for (int i = 0; i < pText.length(); i++)
      {
        offset = ((pText[i] + kText[i]) % 26);
      }
        return offset;
    }

    /**********************************************************
    * getDOffset
    * TODO: ADD description
    **********************************************************/
    std::string getDOffset(std::string cText, std::string kText)
    {
        std::string offset;

      for (int i = 0; i < cText.length(); i++)
      {
        offset = ((cText[i] - kText[i]) % 26);
      }
        return offset;
    }

    /**********************************************************
    * PREPAREKEY
    * TODO: ADD description
    **********************************************************/
    std::string prepareKey(std::string text, std::string password)
    {
        std::string key;

        if (password.length() < text.length())
        {
          key =  password;
          do
          {
            key += password;
          }
          while(password.length() <= text.length());
        }
        if (password.length() > text.length())
        {
          do
          {
            key += password;
          }
          while(password.length() <= text.length());
        }

        return key;
    }
};

#endif // CIPHER06_H
