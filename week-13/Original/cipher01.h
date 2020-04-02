/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Collin Steel"; }
   virtual std::string getCipherName()  { return "Multiplicative Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("�Multiplicative Cipher�, Tutorialspoint,  https://www.tutorialspoint.com/cryptography_with_python/cryptography_with_python_multiplicative_cipher.htm");
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
      str =  "Function encrypt\n";
      str += "   INPUT password, plaintext\n";
      str += "   INIT alphebet : string\n";
      str += "   INIT cipher : string, key : int\n\n";
      str += "   FOR each char in password\n";
      str += "      COMPUTE key as key + index of password char in alphabet\n";
      str += "   ENDFOR\n\n";
      str += "   FOR each char in plaintext\n";
      str += "      INIT index\n";
      str += "      COMPUTE index as(key * index of plaintext char in alphabet) modulus sizeofalphabet\n";
      str += "      COMPUTE cipher as cipher + alphabet at index\n";
      str += "   ENDFOR\n\n";
      str += "RETURN cipher\n\n";

      
      // The decrypt pseudocode
      str += "Function decrpyt\n";
      str += "   INPUT password, plaintext\n";
      str += "   INIT alphebet : string\n";
      str += "   INIT cipher : string, key : int\n\n";
      str += "   FOR each char in password\n";
      str += "      COMPUTE key as key + index of password char in alphabet\n";
      str += "   ENDFOR\n\n";
      str += "   FOR each char in cipherText\n";
      str += "      FOR n from 0 to sizeofalphabet\n";
      str += "         IF (n * key) modulus sizeofalphabet == char of cipherText\n";
      str += "            COMPUTE plainText as plainText + alphabet at n of alphabet\n";
      str += "            BREAK\n";
      str += "         ENDIF\n";
      str += "      ENDFOR\n";
      str += "   ENDFOR\n\n";
      str += "RETURN cipher\n\n";

      return str;
   }

   
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
      std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";
      std::string cipherText = "";
      int key = 0;

      for (int i = 0; i < password.length(); i++)
      {
         key += alphabet.find(password[i]);
      }

      for (int j = 0; j < plainText.length(); j++)
      {
         int index = (key * alphabet.find(plainText[j])) % alphabet.length();
         cipherText += alphabet[index];
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
      // // TODO - Add your code here
       return plainText;
   }
};

#endif // CIPHER01_H
