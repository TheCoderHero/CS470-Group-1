/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H
#include <string>
#include "cipher.h"
string generateKey(string str, string key);

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
    virtual std::string getPseudoAuth() { return "Aaron Eiche"; }
    virtual std::string getCipherName() { return "Vigenere Cipher"; }
    virtual std::string getEncryptAuth() { return "Osvaldo Carrillo"; }
    virtual std::string getDecryptAuth() { return "Collin Steel"; }

    /***********************************************************
     * GET CIPHER CITATION
     * Returns the citation from which we learned about the cipher
     ***********************************************************/
    virtual std::string getCipherCitation()
    {
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

        // TODO: please format your pseudocode
        str = "ENCRYPT PSUEDOCODE:\n\
      encrypt(message,key)\n\
        FOR character in message\n\
            c <- index of character in alphabet\n\
            k <- index of (the correlated character of the key) in alphabet \n\
            cryptogram <- cryptogram + index of c+k%26 in alphabet\n\
        RETURN cryptogram\n\n";

        // The decrypt pseudocode
        str += "DECRYPT PSUEDOCODE:\n\
         decrypt(message,key)\n\
            FOR character in message\n\
               c <- index of character in alphabet\n\
               k <- index of (the correlated character of the eKey) in alphabet\n\
               IF c is greater than k \n\
                     c <- c + 26\n\
               cryptogram <- cryptogram + index of c - k % 26 in alphabet\n\n";

        return str;
    }

    /**********************************************************
    * SAVED KEY
    * This cipher return a key which the user has to use as the
    * password to decode the message. In this scenario, this
    * variable is store globaly to recreate the desire effect.
    **********************************************************/
    string savedKey;
    /**********************************************************
     * ENCRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string encrypt(const std::string &plainText,
                                const std::string &password)
    {
        std::string cipherText = "";
        //std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";

        //string cipher_text;
        for (int i = 0; i < plainText.length(); i++)
        {
            int c = alphabet.find(plainText[i]);
            int k = alphabet.find(password[i % password.length()]);
            cipherText += alphabet[(c + k) % alphabet.length()];
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
        std::string plainText = "";
        //std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ !\"#$%&'()*+-,./:;<=>?@[]\\^_{}0123456789";

        for (int i = 0; i < cipherText.length(); i++)
        {
            int c = alphabet.find(cipherText[i]);
            int k = alphabet.find(password[i % password.length()]);
            if (c < k)
                c += alphabet.length();
            plainText += alphabet[(c - k) % alphabet.length()];
        }

        return plainText;
    }
};

#endif // CIPHER05_H
