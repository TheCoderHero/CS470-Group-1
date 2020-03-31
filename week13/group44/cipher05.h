/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
*    Affine Cypher
*    Daniel Thomsen - PseudoCode
*
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Daniel Thomsen"; }
   virtual std::string getCipherName()  { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Ben Fisher"; }
   virtual std::string getDecryptAuth() { return "Astrid Vargas"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://practicalcryptography.com/ciphers/classical-era/affine/");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The CoPrime variables listed here need to be co-prime to 
      //eachother (They must have no common factors)
      //A simple boolean function can be used to check this
      //I suggest this: https://www.geeksforgeeks.org/check-two-numbers-co-prime-not/
      str =  "encrypt(coPrime1, coPrime2, plainText)\n";
      str += "   checkIfCoPrime(coPrime1, coPrime2);\n";
      str += "   FOR p is all values of plainText\n";
      str += "      index += ((coPrime1 * indexFromCharacter(*p)) + coPrime2) % 26\n";
      str += "      cipherText += characterFromIndex(index)\n";
      str += "   RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(coPrime1, coPrime2, cypherText)\n";
      str += "   FOR c is all values of encryptedText\n";
      str += "      index += ((coPrime1 ^ -1(cypherText) - coPrime2) % 26)\n";
      str += "      decryptedText += characterFromIndex(index)\n";
      str += "   RETURN decryptText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText,
                               const std::string & password)
   {
      std::string cipherText;
      int coPrime1 = 13;
      int coPrime2 = 7;

      for (const char * p = plainText.c_str(); *p; p++)
      {
         int index = ((coPrime1 * indexFromCharacter(*p)) + coPrime2) % 26;
         cipherText += characterFromIndex(index);
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
      std::string plainText;
      
      // int coPrime1 = 13;
      // int coPrime2 = 7;
      // int a_inv = 0; 
      // int flag = 0; 
      
      // for (int i = 0; i < 26; i++) 
      // { 
      //    flag = (coPrime1 * i) % 26; 

      //    if (flag == 1) 
      //    {  
      //       a_inv = i; 
      //    } 
      // } 
    
      // for (int i = 0; i < cipherText.length(); i++) 
      // { 
      //    if(cipherText[i]!=' ') 
      //       plainText = plainText +  
      //          (char) (((a_inv * ((cipherText[i]+ 'A' - coPrime2)) % 26)) + 'A'); 
      //    else
      //       plainText += cipherText[i];  
      // }

      return plainText;
   }

private:
   /**************************************************
    * INDEX FROM CHARACTER
    * Get an index value from a given letter.
    *************************************************/
   int indexFromCharacter(char letter)
   {
      char valueMinimum = ' ';
      char valueMaximum = '~';
      int sizeAlphabet = valueMaximum - valueMinimum;
      // return the value
      if (letter > valueMaximum || letter < valueMinimum)
         return 0;
      else
         return (int)(letter - valueMinimum);
   }

   /**************************************************
    * CHARACTER FROM INDEX
    * Get the characer value from a given index.
    *************************************************/
   char characterFromIndex(int index)
   {
      char valueMinimum = ' ';
      char valueMaximum = '~';
      int sizeAlphabet = valueMaximum - valueMinimum;
      if (index >= 0 && index < sizeAlphabet)
         return (char)(index + valueMinimum);
      else
         return ' ';
   }
};

#endif // CIPHER05_H
