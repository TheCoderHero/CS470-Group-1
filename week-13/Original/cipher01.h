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
      return std::string("“Multiplicative Cipher”, Tutorialspoint,  https://www.tutorialspoint.com/cryptography_with_python/cryptography_with_python_multiplicative_cipher.htm");
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
      str =  "DECLARE alphebet: enum\n\nFunction encrypt\n\tINPUT password, plaintext\n\tINIT cipher : string, key : byte\n\n\tFOR each char in password\n\t\tCOMPUTE key += ascii value of each char\n\t\tCOMPUTE key as key modulus 26\n\n\t\tFOR char in plaintext\n\t\t\tCOMPUTE cipherChar as(char* key) % enumlength\n\t\t\tCOMPUTE cipher += cipherChar\n\t\tENDFOR\nRETURN cipher\n";

      // The decrypt pseudocode
      str += "Function decrypt/nINPUT password, cipher\n\tINIT plaintext : string, key : byte\n\n\tFOR each char in password\n\t\tCOMPUTE key as key plus ascii value of char\n\tENDFOR\n\tCOMPUTE key as key modulus 26\n\tFOR each char in cipher\n\t\tFOR n = 0 to n = 25\n\t\t\tIF(n multiplied by key) modulus enumlength equals cipher[]\n\t\t\t\tCOMPUTE plaintext plus plainChar\n\t\t\t\tCONTINUE\n\t\tENDFOR\n\tENDFOR\nRETURN plaintext\n";

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
      // TODO - Add your code here
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
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER01_H
