/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#include <string>
#ifndef CIPHER03_H
#define CIPHER03_H


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ankita Dev"; }
   virtual std::string getCipherName()  { return "Vernam cipher"; }
   virtual std::string getEncryptAuth() { return "Ashley Loo"; }
   virtual std::string getDecryptAuth() { return "Whitney Chase"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "cryptomuseum.com ";
      citation += " The Vernam Cipher \n retrieved: ";
      citation += "https://www.cryptomuseum.com/crypto/vernam.htm";
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
      str = "encrypt(plainText, password)\n";
      str += "   cipherText <- '' \n";
      str += "   ptr <- 0 \n";
      str += "   FOR i in size() of plaintext \n"; // might have to use (unsigned) while comparing
      str += "           ciphertext += plainText[i]^password[ptr] \n";
      str += "           if ptr >= size of password \n";// might have to use (unsigned) while comparing
      str += "                   ptr <- 0 \n";
      str += "   return cipherText\n\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   decryptText <- '' \n";
      str += "   ptr <-0 \n";
      str += "   FOR i in size() of cipherText \n"; // might have to use (unsigned) while comparing
      str += "           decryptText += cipherText[i]^password[ptr] \n";
      str += "           if ptr >= size()of password \n"; // might have to use (unsigned) while comparing
      str += "                   ptr <- 0 \n";
      str += "   return decryptTes\n\n";
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      // TODO - Add your code here
      std::string cipherText = "";
      int ptr = 0;
      for(int i = 0; (unsigned)i < plainText.size(); i++)
      {
         cipherText += plainText[i]^password[ptr];
         if((unsigned)ptr >= password.size())
         {
           ptr = 0;
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
      std::string plainText = cipherText;
      std::string decryptText = "";
      int ptr = 0;

      for (int i = 0; (unsigned)i < plainText.size(); i++)
      {
        decryptText += cipherText[i]^password[ptr];
        if((unsigned)ptr >= password.size())
        {
          ptr = 0;
        }
      }
      return plainText;
   }
};

#endif // CIPHER03_H
