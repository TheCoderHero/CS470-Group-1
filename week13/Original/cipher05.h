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
   virtual std::string getPseudoAuth()  { return "Aaron Eiche"; }
   virtual std::string getCipherName()  { return "Vigenère cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {

      // “Crypto,” Practical Cryptography. [Online]. Available: http://practicalcryptography.com/ciphers/vigenere-gronsfeld-and-autokey-cipher/. [Accessed: 04-Apr-2020].

      return std::string("LearnCryptography.com (2016), \n\
      \"Learn Cryptography - Vigenère and Gronsfeld Cipher\', \n   retrieved: \n\
      http://practicalcryptography.com/ciphers/vigenere-gronsfeld-and-autokey-cipher/\n\
      \n\
      “Vigenère cipher,” Wikipedia, 07-Mar-2020. [Online].\n\
      Available: https://en.wikipedia.org/wiki/Vigenère_cipher.\n");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encrypt pseudocode
      str =  "ENCRYPT PSUEDOCODE:\n\
      encrypt(message,key)\n\
        eKey <- extendKey(key)\n\
        FOR character in message\n\
            c <- index of character in alphabet\n\
            k <- index of (the correlated character of the key) in alphabet \n\
            cryptogram <- cryptogram + index of c+k%26 in alphabet\n\
        RETURN cryptogram\n\n";

      // The decrypt pseudocode
      str += "DECRYPT PSUEDOCODE:\n\
         decrypt(message,key)\n\
            eKey <- extendKey(key)\n\
            FOR character in message\n\
               c <- index of character in alphabet\n\
               k <- index of (the correlated character of the eKey) in alphabet\n\
               IF c is greater than k \n\
                     c <- c + 26\n\
               cryptogram <- cryptogram + index of c - k % 26 in alphabet\n\n";

      str += "HELPER FUNCTION:\n\
      extendKey(key)\n\
         IF length of KEY is greater than the length of MESSAGE\n\
            keycount <- length of message divided by length of key\n\
            WHILE keycount is greater than zero\n\
                  extendedKey <- extendedKey + key\n\
                  keycount <- keycount - 1\n\
            remainder <- length of message modulus (%) length of extendedKey\n\
            WHILE i is less than or equal to remainder\n\
                  extendedKey <- extendedKey + character at index i of key\n\
                  i <- i + 1\n\
         RETURN extendedKey\n";
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

#endif // CIPHER05_H
