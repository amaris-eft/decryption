//Amaris Efthimou
//CSCI 136
//Melissa Lynch
//Lab 6D
//decryption functions corresponding to the above ciphers.
#include <iostream>
#include <string>
using namespace std;
string encryptCaesar(string plaintext, int rshift);
string encryptVigenere(string plaintext, string keyword);
string decryptCaesar(string ciphertext, int rshift);
string decryptVigenere(string ciphertext, string keyword);

string encryptCaesar(string plaintext, int rshift)//ceasar cypher
{
    string ans = "";
    char c;
    int n;
    int num = 0;
    for (int i = 0; i < plaintext.length(); i++)
    {
        c = plaintext[i];
        if (c >= 'A' && c <= 'Z')
        {
            n = plaintext[num] - 'a';
            num = (num + 1) % plaintext.length(); //upper case shift
            c = 'A' + (c - 'A' + n + 26) % 26;
        }
        if (c >= 'a' && c <= 'z')
        {                           //shifts lowercase characters up the alphabet
            n = plaintext[num] - 'a'; //the n-th letter of the alphabet will shift by n − 1 to the right
            num = (num + 1) % plaintext.length();
            c = 'a' + (c - 'a' + n + 26) % 26;
        }
        ans = ans + c; //add values
    }
    return ans; //return the string
}
char shiftChar(char c, int rshift)
{ //shifts one character using rshift
    if (c >= 'a' && c <= 'z')//lowercase
        c = 'a' + (c - 'a' + rshift + 26) % 26; //lower case
    if (c >= 'A' && c <= 'Z')//upper
        c = 'A' + (c - 'A' + rshift + 26) % 26; //upper case
    return c;
}
string encryptCaesar(string plaintext, int rshift)// encrypting ceasar cypher
{ //caesar cypher encryption
    string ans = "";
    for (int i = 0; i < plaintext.length(); ++i)
    {
        ans += shiftChar(plaintext[i], rshift); //add each value to the string
    }
    return ans;
}
string decryptCaesar(string cipherText, int rshift){//decrypt caesar
    char c;
    for(int i = 0; cipherText[i] !='\0'; ++i){
        c = cipherText[i];
        if(c >= 'a' && c <= 'z'){//lower
            c = c - rshift;
            if(c < 'a'){
                c =  c + 'z' - 'a' + 1;
            }
            cipherText[i] = c;
        }
        else if(c >= 'A' && c <= 'Z'){//upper
            c = c + 'Z' - 'A' + 1;
        }
        cipherText[i] = c;
    }
    return cipherText;
}
string decryptVigenere(string ciphertext, string keyword)//decrypt vigenere cypher
{
    int i, j;
    string plain = "";
    char p;
    for (int k = 0; k < keyword.length(); k++)
    {
        if (islower(keyword[k]))
        {
            keyword[k] = keyword[k] - 32;
        }
    }
    int len = ciphertext.length() / keyword.length();
    for (i = 0; i < len; i++)
    {
        keyword += keyword;
    }
    j = 0;
    for (i = 0; i < ciphertext.length(); i++)
    {
        if ((ciphertext[i] >= 'a' && ciphertext[i] <= 'z') || (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z'))//lower + upper
        {
            if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z')
            {
                p = (ciphertext[i] - 'a' - (keyword[j] - 'A')) % 26 + 'a';
            }
            else
            {
                p = (ciphertext[i] - 'A' - (keyword[j] - 'A')) % 26 + 'A';
            }
            plain = plain + p;
            j++;
        }
        else
            plain = plain + ciphertext[i];
    }
    return plain;
}
int main()//main function
{
    string plaintext;
    int rshift;
    cout << "Enter plaintext: " << endl;
    getline(cin, plaintext);
    cout << "= Caesar =" << endl;
    cout << "Enter right shift:" << endl;
    cin >> rshift;
    string cipher = encryptCaesar(plaintext, rshift);//output cypher
    cout << "Cyphertext: " << encryptCaesar(plaintext, rshift) << endl;/output decrypted
    decryptCaesar(cipher, rshift) == plaintext;
    cout << "Decrypted: " << plaintext << endl;
    //cout << "Decrypted: " << decryptCaesar(ciphertext, rshift) << endl;
    cout << endl;
    string plaintext;
    string keyword;
    cout << "= Vigenere =" << endl;
    cout << "Enter plaintext: " << endl;
    getline(cin, plaintext);
    cout << "Enter keyword:" << endl;
    cin >> keyword;
    string cipher_text = encryptVigenere(plaintext, keyword);
    cout << "Cyphertext: " << encryptVigenere(plaintext, keyword) << endl;//ouput cypher
    cout << "Decrypted: " << decryptVigenere(cipher_text, keyword) << endl;//oytput decrypted
    //cout << "Decrypted: " << decryptVigenere(ciphertext, keyword) << endl;
    return 0;
}