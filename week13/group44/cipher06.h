/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Ben Fisher"; }
   virtual std::string getCipherName()  { return "Beaufort Cipher"; }
   virtual std::string getEncryptAuth() { return "Daniel Thomsen"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "Lyons, James. \'Crypto.\' Practical Cryptography, ";
      s += "practicalcryptography.com/ciphers/classical-era/beaufort/.";
      return s;
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str =  "encrypt(plainText, password)\n";
      str += "   FOR p is all values of plainText\n";
      str += "      index <- p % password.length()\n";
      str += "      cipherText += matchingLetter(p, password[index], alphabet)\n";
      str += "   RETURN cipherText\n\n";
   
      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   FOR c is all values of cipherText\n";
      str += "      index <- c % password.length()\n";
      str += "      plainText += matchingLetter(c, password[index])\n";
      str += "   RETURN plainText\n\n";

      // Helper routines
      str += "matchingLetter(inputLetter, selectedLetter, alphabet)\n";
      str += "   RETURN alphabet[(indexOf(selectedLetter) - indexOf(inputLetter) + 26) % 26]\n\n";

      str += "indexOf(givenLetter, alphabet)\n";
      str += "   FOR i is current value in alphabet\n";
      str += "      IF alphabet[i] is equal to givenLetter\n";
      str += "         RETURN index\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * The encryption algoritm based on the psuedocode provided above
    **********************************************************/
   int indexOf(char givenLetter, char alphabet)
   {
   char alphabet2[]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      for (int i = 0; i < 26; i++)
      {
         if (alphabet2[i] == givenLetter)
         {
            return alphabet2[i];
         }
      }
     return alphabet;
   }    
    
   char matchingLetter(int p, char selectedLetter, char inputLetter)
   {
      char alphabet[]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      int i = (indexOf(selectedLetter, alphabet[p]) - (indexOf(inputLetter, alphabet[p])) + 26) % 26;
      
      return alphabet[i];
   }
   

  //*/   
    
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
  {
      std::string cipherText = plainText;
      // TODO - Add your code here
      int index;
      char alphabet[]{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
      for (int p; p < plainText.length(); p++)
      {
         index = p % password.length();
         cipherText += matchingLetter(p, password[index], alphabet[p]);
         
      }
      
   //*/   
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

#endif // CIPHER06_H
