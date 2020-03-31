/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

#include <string>
#include "cipher.h"

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "John Soon"; }
   virtual std::string getCipherName() { return "Playfair Cipher"; }
   virtual std::string getEncryptAuth() { return "Cal Wilson"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string citation;
      citation += "Practicalcryptography.com. (2019). Practical Cryptography.[online]\n";
      citation += "Available at: http://practicalcryptography.com/ciphers/playfair-cipher/ [Accessed 14 Dec. 2019].";
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
      str += "key = buildKey(password)\n";
      str += "IF plainText length MOD 2 != 0\n";
      str += "   APPEND x to plainText\n";
      str += "STRING cipherText\n";
      str += "FOR i=0  while i < plainText length i + 2\n";
      str += "   STRING a = plainText[i]\n";
      str += "   STRING b = plainText[i+1]\n";
      str += "   STRING c\n";
      str += "   STRING d\n";
      str += "   IF a is equal to b\n";
      str += "      b = 'x'\n";
      str += "   INT row1 = key index of a / 5\n";
      str += "   INT col1 = key index of a MOD 5\n";
      str += "   INT row2 = key index of b / 5\n";
      str += "   INT col2 = key index of b MOD 5\n";
      str += "   IF row1 is equal to row2\n";
      str += "      IF col1 is equal to 4\n";
      str += "         c = key[row1*5]\n";
      str += "      ELSE c = key[row1*5 + col1 + 1]\n";
      str += "      IF col2 is equal to 4\n";
      str += "         d = key[row2*5]\n";
      str += "      ELSE d = key[row2*5 + col2 + 1]\n";
      str += "   ELSE IF col1 is equal to col2\n";
      str += "      IF  row1 is equal to 4\n";
      str += "         c = key[col1]\n";
      str += "      ELSE c = key[(row1 + 1) * 5 + col1]\n";
      str += "      IF  row2 is equal to 4\n";
      str += "         d = key[col2]\n";
      str += "      ELSE d = key[(row2 + 1) * 5 + col2]\n";
      str += "   ELSE\n";
      str += "      c = key[row1*5 + col2]\n";
      str += "      d = key[row2*5 + col1]\n";
      str += "   cipherText += c + d\n";
      str += "RETURN cipherText\n";

      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "key = buildKey(password)\n";
      str += "IF cipherText MOD 2 != 0\n";
      str += "   ERROR cipherText must be even\n";
      str += "STRING plainText\n";
      str += "FOR i=0  while i < cipherText length i + 2\n";
      str += "   STRING a = cipherText[i]\n";
      str += "   STRING b = cipherText[i+1]\n";
      str += "   STRING c\n";
      str += "   STRING d\n";
      str += "   IF a is equal to b\n";
      str += "      b = 'x'\n";
      str += "   INT row1 = key index of a / 5\n";
      str += "   INT col1 = key index of a MOD 5\n";
      str += "   INT row2 = key index of b / 5\n";
      str += "   INT col2 = key index of b MOD 5\n";
      str += "   IF row1 is equal to row2\n";
      str += "      IF col1 is equal to 4\n";
      str += "         c = key[row1*5]\n";
      str += "      ELSE c = key[row1*5 + col1 + 1]\n";
      str += "      IF col2 is equal to 4\n";
      str += "         d = key[row2*5]\n";
      str += "      ELSE d = key[row2*5 + col2 + 1]\n";
      str += "   ELSE IF col1 is equal to col2\n";
      str += "      IF  row1 is equal to 4\n";
      str += "         c = key[col1]\n";
      str += "      ELSE c = key[(row1 + 1) * 5 + col1]\n";
      str += "      IF  row2 is equal to 4\n";
      str += "         d = key[col2]\n";
      str += "      ELSE d = key[(row2 + 1) * 5 + col2]\n";
      str += "   ELSE\n";
      str += "      c = key[row1*5 + col2]\n";
      str += "      d = key[row2*5 + col1]\n";
      str += "   plainText += c + d\n";
      str += "RETURN plainText\n";

      // Password helper function
      str += "buildKey(password)\n";
      str += "FOR i is all the values in password WHILE i < length of password INCREMENT i by 1\n";
      str += "   IF password at index i is equal to j\n";
      str += "      password[i] = i\n";
      str += "   IF password at index i is equal to password at index i - 1\n";
      str += "      password[i] = x\n";
      str += "   IF password at index i is a digit 0-9 OR symbol\n";
      str += "      password[i] = y\n";
      str += "   IF password at index i is a space\n";
      str += "      password[i] = z\n";
      str += "IF password length is greater than 25\n";
      str += "   trim password to length 25\n";
      str += "IF password length is less than 25\n";
      str += "   WHILE password length is less than 25 push_back abcde...\n";
      str += "RETURN password";
      return str;
   }

   /**********************************************************
    * BUILD KEY
    * TODO: ADD description
    **********************************************************/
   std::string buildKey(std::string password)
   {
      for (int i = 0; i < password.length(); i++)
      {
         if (password[i] == 'j')
         {
            password[i] == 'i';
         }
         if (password[i] == password[i - 1])
         {
            password[i] == 'x';
         }
         if (isdigit(password[i]) || ispunct(password[i]))
         {
            password[i] == 'y';
         }
         if (password[i] == ' ')
         {
            password[i] == 'z';
         }
      }
      if (password.length() > 25)
      {
         password.erase(25, std::string::npos);
      }
      if (password.length() < 25)
      {
         int ascii = 97;
         while (password.length() < 25)
         {
            password += ascii;
            ascii++;
         }
      }
      return password;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string &plainText,
                               const std::string &password)
   {
      std::string newPlainText = plainText;
      std::string key = buildKey(password);
      if (newPlainText.length() % 2 != 0)
      {
         newPlainText += 'x';
      }
      std::string cipherText = "";
      for (int i = 0; i < newPlainText.length(); i + 2)
      {
         char a = newPlainText[i];
         char b = newPlainText[i + 1];
         char c;
         char d;
         if (a == b)
         {
            b = 'x';
         }
         int row1 = key[a] / 5;
         int col1 = key[a] % 5;
         int row2 = key[b] / 5;
         int col2 = key[b] % 5;
         if (row1 == row2)
         {
            if (col1 == 4)
            {
               c = key[row1 * 5];
            }
            else
            {
               c = key[row1 * 5 + col1 + 1];
            }
            if (col2 == 4)
            {
               d = key[row2 * 5];
            }
            else
            {
               d = key[row2 * 5 + col2 + 1];
            }
         }
         else if (col1 == col2)
         {
            if (row1 == 4)
            {
               c = key[col1];
            }
            else
            {
               c = key[(row1 + 1) * 5 + col1];
            }
            if (row2 == 4)
            {
               d = key[col2];
            }
            else
            {
               d = key[(row2 + 1) * 5 + col2];
            }
         }
         else
         {
            c = key[row1 * 5 + col2];
            d = key[row2 * 5 + col1];
         }
         cipherText += c + d;
      }
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string &cipherText,
                               const std::string &password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER03_H
