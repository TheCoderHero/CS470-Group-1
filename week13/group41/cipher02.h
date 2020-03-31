/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

#include <iostream>
#include <math.h>
#include <map>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Nick Campbell"; }
   virtual std::string getCipherName() { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Tori Fife"; }
   virtual std::string getDecryptAuth() { return "Heather Mason"; }

   /***********************************************************
   * GET CIPHER CITATION
   * Returns the citation from which we learned about the cipher
   ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "GeeksforGeeks.com (2019), ";
      citation += "\"Keyword Cipher\', \n   retrieved: ";
      citation += "https://www.geeksforgeeks.org/keyword-cipher/";
      return std::string("citation");
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
      str = "Function encrypt()\n";
      str += "encoded <- encoder(password)";
      str += "\tcipher <- ''\n";
      str += "\tFOR i = 0 to plainText.size()\n";
      str += "\t\tIF plainText[i] >= 'a' && plainText[i] <= 'z'\n";
      str += "\t\t\tTHEN int pos = plainText[i] - 97\n";
      str += "\t\t\tAND cipher += encoded[pos]\n";
      str += "\t\tELSE IF plainText[i] >= 'A' && plainText[i] <= 'Z'\n";
      str += "\t\t\tTHEN int pos = plainText[i] - 65\n";
      str += "\t\t\tAND cipher += encoded[pos]\n";
      str += "\t\tELSE cipher += plainText[i]\n";
      str += "RETURN cipher\n";

      // The decrypt pseudocode
      str += "Function decrypt()\n";
      str += "encoded <- encoder(password)\n";
      str += "alphabet <- \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"\n";
      str += "map <char,int> enc\n";
      str += "\tFOR i = 0 to encoded.size()\n";
      str += "\t\tenc[encoded[i]] = i\n";
      str += "\tdecipher <- ''\n";
      str += "\tFOR i = 0 to cipherText.size()\n";
      str += "\t\tIF cipherText[i] >= 'a' && cipherText[i] <= 'z'\n";
      str += "\t\t\tTHEN int pos = enc[cipherText[i] - 32]\n";
      str += "\t\t\tAND decipher += alphabet[pos]\n";
      str += "\t\tELSE IF cipherText[i] >= 'A' && cipherText[i] <= 'Z'\n";
      str += "\t\t\tTHEN int pos = enc[cipherText[i]]\n";
      str += "\t\t\tAND decipher += alphabet[pos]\n";
      str += "\t\tELSE decipher += cipherText[i]\n";
      str += "RETURN decipher\n";
      return str;
   }
 
   /**********************************************************
    *ENCODER
    *Encode alphabet based on password
    **********************************************************/
  virtual std::string encoder(string password)
  {
     string alphabet = password + "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
     string encoded = "";
     for (int i = 0; i < alphabet.length(); i++)
     {
        if (isalpha(alphabet[i]))
        {
           alphabet[i] = toupper(alphabet[i]);
           if (encoded.find(alphabet[i]) == string::npos)
           {
              encoded.push_back(alphabet[i]);
           }
        }
     }
     return encoded;
   }
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
      const std::string & password)
   {
      std::string cipherText = "";
    std::string encoded = encoder(password);
    for (int i = 0; i < plainText.length(); i++)
    {
       if (isalpha(plainText[i]))
       {
          cipherText.push_back(encoded[toupper(plainText[i]) - 'A']);
       }
       else
       {
          cipherText.push_back(plainText[i]);
       }
    }
      return cipherText;
   }

    /**********************************************************
     * DECRYPT
     * takes the ciphertext and password, gets the encoded key,
     * and decrypts the message using it. 
     **********************************************************/
   virtual std::string decrypt(const std::string & cipherText,
      const std::string & password)
   {
      std::string plainText = "";
      // TODO - Add your code here
      std::string encoded = encoder(password);
      std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      std::map <char, int> enc;
      for (int i = 0; i < encoded.length(); i++)
      {
         enc[encoded[i]] = i;
      }
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
         {
            int pos = enc[cipherText[i] - 32];
            plainText += alphabet[pos];
         }
         else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
         {
            int pos = enc[cipherText[i]];
            plainText += alphabet[pos];
         }
         else 
         {
            plainText += cipherText[i];
         }
      }
      return plainText;
   }
};

#endif // CIPHER02_H
