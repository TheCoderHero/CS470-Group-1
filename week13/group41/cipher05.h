/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ashley Loo"; }
   virtual std::string getCipherName()  { return "Simple Substitution Cipher"; }
   virtual std::string getEncryptAuth() { return "Ankita Dev"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
		citation += "Practical Cryptography.com, ";
		citation += "\"Simple Substitution Cipher\', \n   retrieved: ";
		citation += "http://practicalcryptography.com/ciphers/simple-substitution-cipher/";
      citation += "http://www.crypto-it.net/eng/simple/simple-substitution-ciphers.html?tab=1";
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
      str =  "encrypt(message, password)\n";
      str += " var cipher\n";
      str += " key = getkey(password)\n";
      str += " FOR each letter in message\n";
      str += "    cipher += key[letter]\n";
      str += "RETURN cipher\n";
      str += "\n";

      // The decrypt pseudocode
      str += "decrypt(message, password)\n";
      str += " var decipher\n";
      str += " key = getkey(password)\n";
      str += " FOR each letter in message\n";
      str += "    IF letter = key[i]\n";
      str += "       decipher += alphabet[i]\n";
      str += "RETURN decipher\n";
      str += "\n";

      //Key
      str += "getkey(password)\n";
      str += " var letters = alphabet \n";
      str += " FOR each letter in password\n";
      str += "    IF letter is in letters\n";
      str += "       letters - letter\n";
      str += " letters = password + letters\n";
      str += "RETURN letters\n";

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
      std::string cipher = "";
      std::string key = getkey(password);
      for(int i = 0; i < plainText; i++)
         cipher += key[i]
      return cipher;
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

#endif // CIPHER05_H
