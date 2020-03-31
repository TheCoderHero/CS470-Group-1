/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER07_H
#define CIPHER07_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher07 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Hyde Xu"; }
   virtual std::string getCipherName()  { return "Vernam Cipher"; }
   virtual std::string getEncryptAuth() { return "Caleb Hensley"; }
   virtual std::string getDecryptAuth() { return "Ben Dzado"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation = "URL: http://ieeexplore.ieee.org/stamp/stamp.jsp?tp=&arnumber=5061224&isnumber=5061201\n";
      citation += "Author: Gilbert Vernam \n";
      citation += "Title: Cipher Printing Telegraph Systems For Secret Wire and Radio Telegraphic Communications \n\n";
      citation += "Date of publication : Jan. 1926 \n";
      citation += "URL: https://www.geeksforgeeks.org/vernam-cipher-in-cryptography \n";
      citation += "Author: Ramswarup Kulhary \n";
      citation += "Title: Vernam Cipher in Cryptography \n";
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
      str =  "The encrypt pseudocode:\n";
      str += "convert(){\n";
      str += "    takes the string and convert into 0-25 \n";
      str += "    if it's doing keyword, it need to fill up to the length of the msg\n";
      str += "    return the array of numbers\n";
      str += "    }\n";
      str += "cipher(){\n";
      str += "    adds up two arrays, if any number is bigger than 26, minus 26 from it\n";
      str += "    use the array to convert it back to letters\n";
      str += "    }\n";
      str += "vernamCipher(){ \n";
      str += "    get the plain-text and keyword \n";
      str += "    call convert() and pass the msg and key to get the arrays of numbers \n";
      str += "    call cipher() with the two arrays to get the ciphered text\n";
      str += "    prints out the ciphered text\n";
      str += "    }\n\n";


      // The decrypt pseudocode
      str += "The decrypt pseudocode:\n";
      str += "convert(){\n";
      str += "    takes the number array and convert it into letters \n";
      str += "    return the letters\n";
      str += "decipher(){\n";
      str += "    subtract two arrays, Cipher array - key array\n";
      str += "    if any number in the cipher array is smaller than the key array, add 26 to that number\n";
      str += "    }\n";
      str += "vernamDecipher(){ \n";
      str += "    take the cipher text and keyword \n";
      str += "    call decipher() and pass the cipher text and key to get the arrays of number \n";
      str += "    call convert() with the array to get the decrypted text\n";
      str += "    prints out the decrypted text\n";
      str += "    }\n";

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

#endif // CIPHER07_H
