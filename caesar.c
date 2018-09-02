//The program enrypts a given string using the Caesar algorithm.
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define numberOfAlphabet 26 //To avoid using magic numbers directly in my code.
#define numberOfCmdArg 2

int checkCmdArg(int number); //Safeguard the number of cmdline arguments received.
string caesarCipher(string text, int key); //Encrpt the given text using the Caesar cipher.

int main(int argc, string argv[])
{
    if (!checkCmdArg(argc))
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
    int key = atoi(argv[1]);
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: %s\n", caesarCipher(plaintext, key));
    return 0;
}

int checkCmdArg(int number)
{
    if (number != numberOfCmdArg)
    {
        return 0; //0 is false in boolean
    }
    else
    {
        return 1; //1 is true in boolean
    }
}

string caesarCipher(string text, int key)
{
    string ciphertext = text; //Assign a value to this string to silence the warning from compiler.
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i])) //Encrypt alphabetical characters ONLY.
        {
            if (islower(text[i]))
            {
                ciphertext[i] = (text[i] - 'a' + key) % numberOfAlphabet + 'a';
            }

            else if (isupper(text[i]))
            {
                ciphertext[i] = (text[i] - 'A' + key) % numberOfAlphabet + 'A';
            }
        }
        else // Do nothing to non-alphabetical char and simply print 'em out.
        {
            ciphertext[i] = text[i];
        }
    }
    return ciphertext;
}