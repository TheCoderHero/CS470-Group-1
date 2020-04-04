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
    virtual std::string getPseudoAuth() { return "pseudocode author"; }
    virtual std::string getCipherName() { return "Vigenère Cipher"; }
    virtual std::string getEncryptAuth() { return "Osvaldo Carrillo"; }
    virtual std::string getDecryptAuth() { return "decrypt author"; }

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
        str = "insert the encryption pseudocode\n";

        // The decrypt pseudocode
        str += "insert the decryption pseudocode\n";

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
    virtual std::string encrypt(const std::string& plainText,
        const std::string& password)
    {
        std::string cipherText;
        // TODO - Add your code here

        //string cipher_text;
        string keyPassword = generateKey(plainText, password);

        for (int i = 0; i < plainText.size(); i++)
        {
            // converting in range 0-25 
            int x = (plainText[i] + keyPassword[i]) % 26;

            // convert into alphabets(ASCII) 
            x += 'A';

            cipherText.push_back(x);
        }

        savedKey = keyPassword;
        return cipherText;
    }

    /**********************************************************
     * DECRYPT
     * TODO: ADD description
     **********************************************************/
    virtual std::string decrypt(const std::string& cipherText,
        const std::string& password)
    {
        std::string plainText;

        for (int i = 0; i < cipherText.size(); i++)
        {
            // converting in range 0-25 
            int x = (cipherText[i] - savedKey[i] + 26) % 26;

            // convert into alphabets(ASCII) 
            x += 'A';
            plainText.push_back(x);
        }

        return plainText;
    }


    // This function generates the key in 
 // a cyclic manner until it's length isi'nt 
 // equal to the length of original text 
    string generateKey(string str, string key)
    {
        int x = str.size();

        for (int i = 0; ; i++)
        {
            if (x == i)
                i = 0;
            if (key.size() == str.size())
                break;
            key.push_back(key[i]);
        }
        return key;
    }
};

#endif // CIPHER05_H
