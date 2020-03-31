/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

#include<iostream>
#include<string>

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Tori Fife"; }
   virtual std::string getCipherName()  { return "Playfair Cipher"; }
   virtual std::string getEncryptAuth() { return "Ankita Dev"; }
   virtual std::string getDecryptAuth() { return "Nick Campbell"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string s;
      s += "PracticalCryptography.com, ";
      s += "\"Practical Cryptography - Playfair Cipher\", \n   retrieved: ";
      s += "http://practicalcryptography.com/ciphers/playfair-cipher/";
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
      str += "   keysquare <- getKeySquare(password)\n";
      str += "   cleanText <- getCleanText(plainText)\n";
      str += "   cipherText <- empty string\n";
      str += "   FOR int i in length of cleanText\n";
      str += "      index1 <- keysquare.find(cleanText[i])\n"; //indexes are ints
      str += "      i++\n"; //increase i for next letter (they're used in pairs)
      str += "      IF i NOT equal or greater than cleanText length\n";
      str += "         index2 <- keysquare.find(cleanText[i])\n";
      str += "      ELSE index2 <- keysquare.find('x')\n";
                    //here we're checking if they're in the same column
      str += "      IF index1 % 5 EQUALS index2 % 5\n";
      str += "         IF index1 Greater or Equal to 20\n";
      str += "            cipherText.push_back <- keysquare[index1 - 20]\n";
      str += "         ELSE cipherText.push_back <- keysquare[index1 + 5]\n";
      str += "         IF index2 Greater or Equal to 20\n";
      str += "            cipherText.push_back <- keysquare[index2 - 20]\n";
      str += "         ELSE cipherText.push_back <- keysquare[index2 + 5]\n";
                    //if we got this far, we need to check if they're in the
                    //same row. The function will take care of everything.
                    //Returns false if they weren't in the same row. Just use
                    //it as a bool and move on
      str += "      ELSE IF NOT (processRowsEncrypt(index1, index2, keysquare, cipherText))\n";
                       //start and end will give us the row boundaries
      str += "         start <- 20\n";
      str += "         end <- 25\n";
      str += "         IF index1 < 5\n";
      str += "            start <- 0\n";
      str += "            end <- 5\n";
      str += "         ELSE IF index1 < 10\n";
      str += "            start <- 5\n";
      str += "            end <- 10\n";
      str += "         ELSE IF index1 < 15\n";
      str += "            start <- 10\n";
      str += "            end <- 15\n";
      str += "         ELSE IF index1 < 20\n";
      str += "            start <- 15\n";
      str += "            end <- 20\n";
                       //note: 20-25 is already taken care of by default
      str += "      FOR start; start < end; start++\n";
                       //check for same column as index2
      str += "         IF keysquare[i] % 5 == keysquare[index2] % 5\n";
      str += "            cipherText.push_back <- keysquare[start]\n";
                       //we're repeating all of this for index2
      str += "         start <- 20\n";
      str += "         end <- 25\n";
      str += "         IF index2 < 5\n";
      str += "            start <- 0\n";
      str += "            end <- 5\n";
      str += "         ELSE IF index2 < 10\n";
      str += "            start <- 5\n";
      str += "            end <- 10\n";
      str += "         ELSE IF index2 < 15\n";
      str += "            start <- 10\n";
      str += "            end <- 15\n";
      str += "         ELSE IF index2 < 20\n";
      str += "            start <- 15\n";
      str += "            end <- 20\n";
                       //note: 20-25 is already taken care of by default
      str += "      FOR start; start < end; start++\n";
                       //check for same column as index1
      str += "         IF keysquare[i] % 5 == keysquare[index1] % 5\n";
      str += "            cipherText.push_back <- keysquare[start]\n";
      str += "   RETURN cipherText\n\n";


      // The decrypt pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   keysquare <- getKeySquare(password)\n";
      str += "   plainText <- empty string\n";
      str += "   FOR int i in length of cipherText\n";
      str += "      index1 <- keysquare.find(cipherText[i])\n"; //indexes are ints
      str += "      i++\n"; //increase i for next letter (they're used in pairs)
      str += "      index2 <- keysquare.find(cipherText[i])\n";
                    //here we're checking if they're in the same column
      str += "      IF index1 % 5 EQUALS index2 % 5\n";
      str += "         IF index1 Equals 0\n";
      str += "            plainText.push_back <- keysquare[index1 + 20]\n";
      str += "         ELSE plainText.push_back <- keysquare[index1 - 5]\n";
      str += "         IF index2 Equals 20\n";
      str += "            plainText.push_back <- keysquare[index2 + 20]\n";
      str += "         ELSE plainText.push_back <- keysquare[index2 - 5]\n";
                    //if we got this far, we need to check if they're in the
                    //same row. The function will take care of everything.
                    //Returns false if they weren't in the same row. Just use
                    //it as a bool and move on
      str += "      ELSE IF NOT (processRowsDecrypt(index1, index2, keysquare, plainText))\n";
                       //start and end will give us the row boundaries
      str += "         start <- 20\n";
      str += "         end <- 25\n";
      str += "         IF index1 < 5\n";
      str += "            start <- 0\n";
      str += "            end <- 5\n";
      str += "         ELSE IF index1 < 10\n";
      str += "            start <- 5\n";
      str += "            end <- 10\n";
      str += "         ELSE IF index1 < 15\n";
      str += "            start <- 10\n";
      str += "            end <- 15\n";
      str += "         ELSE IF index1 < 20\n";
      str += "            start <- 15\n";
      str += "            end <- 20\n";
                       //note: 20-25 is already taken care of by default
      str += "      FOR start; start < end; start++\n";
                       //check for same column as index2
      str += "         IF keysquare[i] % 5 == keysquare[index2] % 5\n";
      str += "            plainText.push_back <- keysquare[start]\n";
                       //we're repeating all of this for index2
      str += "         start <- 20\n";
      str += "         end <- 25\n";
      str += "         IF index2 < 5\n";
      str += "            start <- 0\n";
      str += "            end <- 5\n";
      str += "         ELSE IF index2 < 10\n";
      str += "            start <- 5\n";
      str += "            end <- 10\n";
      str += "         ELSE IF index2 < 15\n";
      str += "            start <- 10\n";
      str += "            end <- 15\n";
      str += "         ELSE IF index2 < 20\n";
      str += "            start <- 15\n";
      str += "            end <- 20\n";
                       //note: 20-25 is already taken care of by default
      str += "      FOR start; start < end; start++\n";
                       //check for same column as index1
      str += "         IF keysquare[i] % 5 == keysquare[index1] % 5\n";
      str += "            plainText.push_back <- keysquare[start]\n";
      str += "   RETURN plainText\n\n";
      
      // helper routine to format the plaintext for encryption
      // P.S. this code is already written!
      str += "getCleanText(plaintext)\n";
      str += "   cleantext <- empty string\n";
      str += "   prev <- 'x'\n";
      str += "   FOR c in all characters in plaintext\n";
      str += "      IF c is letter\n";
      str += "         make c lowercase, if 'j' make 'i'\n";
      str += "         cleantext.push_back <- c\n";
      str += "   RETURN cleantext\n\n";
      
      // helper routine to create keysquare for both encryption and decryption
      // P.S. this code is already written!
      str += "getKeySquare(password)\n";
      str += "   alphabet <- password + 'abcdefghiklmnopqrstuvwxyz'\n";
      str += "   FOR c in all characters in alphabet\n";
      str += "     IF c is letter\n";
      str += "        make c lowercase, if 'j' make 'i'\n";
      str += "        IF c is not in keysquare\n";
      str += "           keysquare.push_back <- c\n";
      str += "   RETURN keysquare\n\n";
      
      // helper routine to do the encryption if in the same row
      // P.S. this code is already written!
      str += "processRowsEncrypt(indexA, indexB, &keysquare, &cipherText)\n";
      str += "   FOR r is all rows (range 0-4, 1-9, 10-14, 15-19, 20-24)\n";
      str += "      IF indexA AND indexB in row\n";
      str += "        IF indexA farthest right (e.g. 4)\n";
      str += "           plainText.push_back <- keysquare[farthest left (e.g. 0)]\n";
      str += "        ELSE plainText.push_back <- keysquare[IndexA + 1]\n";
      str += "        Repeat previous 3 lines for indexB\n";
      str += "        RETURN true\n";
      str += "   RETURN false\n\n";

      // helper routine to do the decryption if in the same row
      // P.S. this code is already written!
      str += "processRowsDecrypt(indexA, indexB, &keysquare, &plainText)\n";
      str += "   FOR r is all rows (range 0-4, 1-9, 10-14, 15-19, 20-24)\n";
      str += "      IF indexA AND indexB in row\n";
      str += "        IF indexA farthest left (e.g. 0)\n";
      str += "           cipherText.push_back <- keysquare[farthest right (e.g. 4)]\n";
      str += "        ELSE cipherText.push_back <- keysquare[IndexA - 1]\n";
      str += "        Repeat previous 3 lines for indexB\n";
      str += "        RETURN true\n";
      str += "   RETURN false\n\n";
      
      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string  & plainText,
                               const std::string & password)
   {
      // std::string cipherText = plainText;
      // TODO - Add your code here
      std::string keySquare = getKeySquare(password);
      std::string cleanText = getCleanText(plainText);
      std::string cipherText = "";
      int index1;
      int index2;
      int start;
      int end;
      for(int i = 0; i< cleanText.length();i++)
      {
         index1 = keySquare.find(cleanText[i]);
         if(!(i >= cleanText.length()))
            index2 = keySquare.find(cleanText[i]);
         else
            index2 = keySquare.find('x');
         if((index1 %5) == (index2 %5))
         {
            if(index1 >= 20)
               cipherText.push_back(keySquare[index1-20]);
            else
               cipherText.push_back(keySquare[index1+5]);
            if(index2 >= 20)
               cipherText.push_back(keySquare[index2-20]);
            else
               cipherText.push_back(keySquare[index2+5]);
         }
         else if(!(processRowsEncrypt(index1, index2, keySquare, cipherText)))
         {
            start = 20;
            end = 25;
            if (index1<5)
            {
               start = 0;
               end = 5;
            }
            else if(index1 < 10)
            {
               start = 5;
               end = 10;
            }
            else if(index1 < 15)
            {
               start = 10;
               end = 15;
            }
            else if(index1 < 20)
            {
               start = 15;
               end = 20;
            }
            //note: 20-25 is already taken care of by default
         }
         for(start; start < end; start++)
         {
            //check for same column as index2
            if(keySquare[i] % 5 == keySquare[index2] % 5)
               cipherText.push_back(keySquare[start]);
            //we're repeating all of this for index2
            start = 20;
            end = 25;
            if (index2<5)
            {
               start = 0;
               end = 5;
            }
            else if(index2 < 10)
            {
               start = 5;
               end = 10;
            }
            else if(index2 < 15)
            {
               start = 10;
               end = 15;
            }
            else if(index2 < 20)
            {
               start = 15;
               end = 20;
            }
         }
         for(start; start < end; start++)
         {
              //check for same column as index1
            if(keySquare[i] % 5 == keySquare[index1] % 5)
               cipherText.push_back(keySquare[start]);
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
      // TODO - Add your code here
      string keysquare = getKeySquare(password);
      string plainText = "";
      for(int i = 0; i < cipherText.size(); i++)
      {
        index1 = keysquare.find(cipherText[i]);
        i++;
        index2 = keysquare.find(cipherText[i]);
        
        if(index1%5 == index2%5)
        {
          if(index1 == 0)
          {
            plainText.push_back = keysquare[index1 + 20]; 
          }
          else
          {
            plainText.push_back = keysquare[index1 - 5];
          }
          if(index2 == 20)
          {
            plainText.push_back = keysquare[index2 + 20];
          }
          else
          {
            plainText.push_back = keysquare[index2 - 5];
          }
        }
        else if(!processRowsDecrypt(index1, index2, keysquare, plainText))
        {
          int start = 20;
          int end = 25;
          
          if(index1 < 5)
          {
            start = 0;
            end = 5;
          }
          else if(index1 < 10)
          {
            start = 5;
            end = 10;
          }
          else if(index1 < 15)
          {
            start = 10;
            end = 15;
          }
          else if(index1 < 20)
          {
            start = 15;
            end = 20;
          }
        }
        for(start; start < end; start++)
        {
          if(keysquare[i] % 5 == keysquare[index2] % 5)
          {
            plainText.push_back = keysquare[start];
          }
        }
          int start = 20;
          int end = 25;
          
          if(index2 < 5)
          {
            start = 0;
            end = 5;
          }
          else if(index2 < 10)
          {
            start = 5;
            end = 10;
          }
          else if(index2 < 15)
          {
            start = 10;
            end = 15;
          }
          else if(index2 < 20)
          {
            start = 15;
            end = 20;
          }
        }
        for(start; start < end; start++)
        {
          if(keysquare[i] % 5 == keysquare[index1] % 5)
          {
            plainText.push_back = keysquare[start];
          }
        }
      }
      return plainText;
   }
   
   private:
   /**************************************************
    * GET KEY SQUARE
    * Returns a string to be used as a keysquare
    *************************************************/
   std::string getKeySquare(std::string password)
   {
      // Example: if password = "hello world!", the keysquare would be:
      // "helowrdabcfgikmnpqstuvxyz" or, so you can visualize it...
      //  h e l o w
      //  r d a b c
      //  f g i k m
      //  n p q s t
      //  u v x y z
      std::string alphabet = password + "abcdefghiklmnopqrstuvwxyz";
      std::string keysquare = "";
      for (int i = 0; i < alphabet.length(); i++)
      {
         if (isalpha(alphabet[i]))
         {
            alphabet[i] = tolower(alphabet[i]);
            if (alphabet[i] == 'j')
            {
               alphabet[i] = 'i';
            }
            if (keysquare.find(alphabet[i]) == std::string::npos)
            {
               keysquare.push_back(alphabet[i]);
            }
         }
      }
      return keysquare;   
   }
   
   /**************************************************
    * GET CLEAN TEXT
    * Returns a string of formatted plaintext to work with encryption
    *************************************************/
   std::string getCleanText(std::string plaintext) //it's a copy on purpose
   {
      std::string cleanText = "";
      char prev = 'x'; //initialize to 'x' won't cause problems
      for (int i = 0; i < plaintext.length(); i++)
      {
         if (isalpha(plaintext[i]))
         {
            plaintext[i] = tolower(plaintext[i]);
            if (plaintext[i] == 'j')
            {
               plaintext[i] = 'i';
            }
            if (plaintext[i] == prev)
            {
               plaintext[i] = 'x'; //second in a double letter becomes 'x'
            }
            cleanText.push_back(plaintext[i]);
            prev = plaintext[i];
         }
      }
      return cleanText;
   }

   
   /**************************************************
    * PROCESS ROWS ENCRYPT
    * Just does the row processing part of the encryption
    * algorithm
    *************************************************/
    bool processRowsEncrypt(int a, int b, std::string &keysquare, std::string &cipherText)
    {
       //if both in row 1...
       if (a < 5 && b < 5)
       {
          //if 4, go to 0, otherwise just go plus 1. Do for a and b.
          if (a == 4)
          {
             cipherText.push_back(keysquare[0]);
          }
          else
          {
             cipherText.push_back(keysquare[a + 1]);
          }
          if (b == 4)
          {
             cipherText.push_back(keysquare[0]);
          }
          else
          {
             cipherText.push_back(keysquare[b + 1]);
          }
          return true;
       }
       //row 2
       else if (a >= 5 && b >= 5 && a < 10 && b < 10)
       {
          if (a == 9)
          {
             cipherText.push_back(keysquare[5]);
          }
          else
          {
             cipherText.push_back(keysquare[a + 1]);
          }
          if (b == 9)
          {
             cipherText.push_back(keysquare[5]);
          }
          else
          {
             cipherText.push_back(keysquare[b + 1]);
          }
          return true;
       }
       //row 3
       else if (a >= 10 && b >= 10 && a < 15 && b < 15)
       {
          if (a == 14)
          {
             cipherText.push_back(keysquare[10]);
          }
          else
          {
             cipherText.push_back(keysquare[a + 1]);
          }
          if (b == 14)
          {
             cipherText.push_back(keysquare[10]);
          }
          else
          {
             cipherText.push_back(keysquare[b + 1]);
          }
          return true;
       }
       //row 4
       else if (a >= 15 && b >= 15 && a < 20 && b < 20)
       {      
          if (a == 19)
          {
             cipherText.push_back(keysquare[15]);
          }
          else
          {
             cipherText.push_back(keysquare[a + 1]);
          }
          if (b == 19)
          {
             cipherText.push_back(keysquare[15]);
          }
          else
          {
             cipherText.push_back(keysquare[b + 1]);
          }
          return true;
       }
       // row 5
       else if (a >= 20 && b >= 20)
       {
          if (a == 24)
          {
             cipherText.push_back(keysquare[20]);
          }
          else
          {
             cipherText.push_back(keysquare[a + 1]);
          }
          if (b == 24)
          {
             cipherText.push_back(keysquare[20]);
          }
          else
          {
             cipherText.push_back(keysquare[b + 1]);
          }
          return true;
       }
       else
       {
          return false;
       }
    }
    /**************************************************
    * PROCESS ROWS Decrypt
    * Just does the row processing part of the decrypt
    * algorithm
    *************************************************/
    bool processRowsDecrypt(int a, int b, std::string &keysquare, std::string &plainText)
    {
       //if both in row 1...
       if (a < 5 && b < 5)
       {
          //if 0, go to 4, otherwise just go minus 1. Do for a and b.
          if (a == 0)
          {
             plainText.push_back(keysquare[4]);
          }
          else
          {
             plainText.push_back(keysquare[a - 1]);
          }
          if (b == 0)
          {
             plainText.push_back(keysquare[4]);
          }
          else
          {
             plainText.push_back(keysquare[b - 1]);
          }
          return true;
       }
       //row 2
       else if (a >= 5 && b >= 5 && a < 10 && b < 10)
       {
          if (a == 5)
          {
             plainText.push_back(keysquare[9]);
          }
          else
          {
             plainText.push_back(keysquare[a - 1]);
          }
          if (b == 5)
          {
             plainText.push_back(keysquare[9]);
          }
          else
          {
             plainText.push_back(keysquare[b - 1]);
          }
          return true;
       }
       //row 3
       else if (a >= 10 && b >= 10 && a < 15 && b < 15)
       {
          if (a == 10)
          {
             plainText.push_back(keysquare[14]);
          }
          else
          {
             plainText.push_back(keysquare[a - 1]);
          }
          if (b == 10)
          {
             plainText.push_back(keysquare[14]);
          }
          else
          {
             plainText.push_back(keysquare[b - 1]);
          }
          return true;
       }
       //row 4
       else if (a >= 15 && b >= 15 && a < 20 && b < 20)
       {      
          if (a == 15)
          {
             plainText.push_back(keysquare[19]);
          }
          else
          {
             plainText.push_back(keysquare[a - 1]);
          }
          if (b == 15)
          {
             plainText.push_back(keysquare[19]);
          }
          else
          {
             plainText.push_back(keysquare[b - 1]);
          }
          return true;
       }
       // row 5
       else if (a >= 20 && b >= 20)
       {
          if (a == 20)
          {
             plainText.push_back(keysquare[24]);
          }
          else
          {
             plainText.push_back(keysquare[a - 1]);
          }
          if (b == 20)
          {
             plainText.push_back(keysquare[24]);
          }
          else
          {
             plainText.push_back(keysquare[b - 1]);
          }
          return true;
       }
       else
       {
          return false;
       }
    }
};
  

#endif // CIPHER04_H
