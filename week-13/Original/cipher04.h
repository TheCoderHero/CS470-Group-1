/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <string>
#include "cipher.h"
#include <map>

using namespace std;
// Key for Columnar Transposition 
string const key = "HACK";
map<int, int> keyMap;
string encryptMessage(string msg, string password);
string decryptMessage(string cipher, string password);
void setPermutationOrder(string password);
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Osvaldo C."; }
    virtual std::string getCipherName() { return "Transposition Cipher"; }
    virtual std::string getEncryptAuth() { return "Zach Heiner"; }
    virtual std::string getDecryptAuth() { return "Collin Steel"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
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
        str = "Function encrypt\n";
        str += "   INPUT password, plaintext\n";
        str += "   INIT cipher : string\n";
        str += "   INIT column.length : int, row.length / col : int, jIndex: int\n\n";
        str += "   IF plaintext.length %  column.length\n";
        str += "      row.length += 1\n";
        str += "   INIT matrix = NEW : int [row]\n";
        str += "   FOR INIT iIndex 0 < row\n";
        str += "      matrix[iIndex] = NEW : int[columns]\n";
        str += "   FOR INIT iIndex 0 < row\n";
        str += "   FOR INIT kIndex 0 < column\n";
        str += "   IF plaintext == \\0\n";
        str += "      matrix[iIndex][jIndex] = '_'\n";
        str += "      jIndex++\n";
        str += "   IF isAlpha(plaintext[kIndex]) OR isAlphe(plaintext[kIndex] == ' ')\n";
        str += "      matrix[iIndex][jIndex] = plaintext[kIndex]\n";
        str += "      jIndex++\n";
        str += "   kIndex++\n\n";
        str += "   ENDFOR\n\n";
        str += "   ENDFOR\n\n";
        str += "   FOR keyMap : map int = iterator = keyMap BEGIN; keyMap END iterator++\n";
        str += "   jIndex = iterator -> SECOND\n\n";
        str += "   FOR INIT iIndex < row\n";
        str += "   IF isAlpha(matrix[iIndex][jIndex]) OR matrix[iIndex][jIndex] == ' ' OR matrix[iIndex][jIndex]== '_')\n";
        str += "      matrix[iIndex][jIndex] = plaintext[kIndex]\n";
        str += "   ENDFOR\n\n";
        str += "   ENDFOR\n\n";




        // The decrypt pseudocode
        str += "Function decrpyt\n";
        str += "   INPUT password, plaintext\n";
        str += "   INIT column = password.length : int, row = plaintext.length / colomn\n";
        str += "   INIT cipherM = NEW : int [row]\n";
        str += "   FOR INIT iIndex 0 < row\n";
        str += "      cipherM[iIndex] = NEW : int[columns]\n";
        str += "   ENDFOR\n\n";
        str += "   FOR INIT kIndex jIndex 0 < column\n";
        str += "     FOR INIT iIndex 0 < row\n";
        str += "     cipherM[iIndex][jIndex] = plaintext[kIndex] \n";
        str += "     ENDFOR\n\n";
        str += "   ENDFOR\n\n";
        str += "   INIT index : int\n";
        str += "   FOR keyMap : map int = iterator = keyMap BEGIN; keyMap END iterator++\n";
        str += "     iterator -> SECOND = index++\n\n";
        str += "   ENDFOR\n\n";
        str += "   INIT deCipher = NEW : int [row]\n";
        str += "   FOR INIT iIndex 0 < row\n";
        str += "      deCipher[iIndex] = NEW : int[columns]\n";
        str += "   ENDFOR\n\n";
        str += "   INIT kIndex : int\n";
        str += "   FOR INIT jIndex iIndex; password[iIndex] IN NOT EQUAL = \\0 row\n";
        str += "    jIndex = keyMap[password[iIndex++]]\n";
        str += "   FOR INIT kIndex 0 < row\n";
        str += "    deCipher[iIndex][kIndex] = cipherMat[iIndex][jIndex]\n";
        str += "   ENDFOR\n";
        str += "   ENDFOR\n\n";
        str += "   INIT cipher : string\n";
        str += "   FOR INIT iIndex < row \n";
        str += "   FOR INIT jIndex 0 < column\n";
        str += "    IF deCipher[iIndex][jIndex] != '_'\n";
        str += "         ciper += deCipher[iIndex][jIndex]\n";
        str += "   ENDFOR\n";
        str += "   ENDFOR\n\n";
        str += "RETURN cipher\n\n";


        return str;
    }

    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        int row, col, j;
       string cipher = "";

       /* calculate column of the matrix*/
       col = password.length();

       /* calculate Maximum row of the matrix*/
       row = msg.length() / col;

       if (msg.length() % col)
           row += 1;

       //allocate the array
       int** matrix = new int* [row];
       for (int i = 0; i < row; i++)
           matrix[i] = new int[col];

       for (int i = 0, k = 0; i < row; i++)
       {
           for (int j = 0; j < col; )
           {
               if (msg[k] == '\0')
               {
                   /* Adding the padding character '_' */
                   matrix[i][j] = '_';
                   j++;
               }

               if (isalpha(msg[k]) || msg[k] == ' ')
               {
                   /* Adding only space and alphabet into matrix*/
                   matrix[i][j] = msg[k];
                   j++;
               }
               k++;
           }
       }

       for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
       {
           j = ii->second;

           // getting cipher text from matrix column wise using permuted key 
           for (int i = 0; i < row; i++)
           {
               if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
                   cipher += matrix[i][j];
           }
       }

       for (int i = 0; i < row; i++)
           delete[] matrix[i];
       delete[] matrix;

       return cipher;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        int col = password.length();
        string plainText = "";

       int row = cipher.length() / col;
       //char cipherMat[row][col];
       int** cipherMat = new int* [row];
       for (int i = 0; i < row; i++)
           cipherMat[i] = new int[col];

       /* add character into matrix column wise */
       for (int j = 0, k = 0; j < col; j++)
           for (int i = 0; i < row; i++)
               cipherMat[i][j] = cipher[k++];

       /* update the order of key for decryption */
       int index = 0;
       for (map<int, int>::iterator ii = keyMap.begin(); ii != keyMap.end(); ++ii)
           ii->second = index++;

       /* Arrange the matrix column wise according
       to permutation order by adding into new matrix */
       //char decCipher[row][col];
       int** decCipher = new int* [row];
       for (int i = 0; i < row; i++)
           decCipher[i] = new int[col];

       map<int, int>::iterator ii = keyMap.begin();
       int k = 0;
       for (int l = 0, j; password[l] != '\0'; k++)
       {
           j = keyMap[password[l++]];
           for (int i = 0; i < row; i++)
           {
               decCipher[i][k] = cipherMat[i][j];
           }
       }

       /* getting Message using matrix */
       string msg = "";
       for (int i = 0; i < row; i++)
       {
           for (int j = 0; j < col; j++)
           {
               if (decCipher[i][j] != '_')
                   msg += decCipher[i][j];
           }
       }
      return plainText;
    }



// Encryption  
string encryptMessage(string msg, string password)
{
    
}


// Decryption  
string decryptMessage(string cipher, string password)
{
    /* calculate row and column for cipher Matrix */
    
}

void setPermutationOrder(string password)
{
    // Add the permutation order into map  
    for (int i = 0; i < password.length(); i++)
    {
        keyMap[password[i]] = i;
    }
}
#endif // CIPHER04_H
