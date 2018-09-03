//The program encrypts a given plaintext with the Vigenere cipher.
#define numberOfAlphabet 26 //To avoid using magic numbers directly in my code.
#define numberOfCmdArg 2
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countCmdArg(int number); //Safeguard the number of cmdline arguments received.
int checkAlpha(string text); //Safeguard for non-alphabetical keyword.
string vigenereCipher(string text, string keyword); //Encrpt the given text using the Vigenere cipher.

int main(int argc, string argv[])
{
    if (!countCmdArg(argc) || checkAlpha(argv[1]) != 0) //Safeguard the keyword.
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    string keyword = argv[1];
    string plaintext = get_string("Plaintext: ");
    printf("ciphertext: %s\n", vigenereCipher(plaintext, keyword));
    return 0;
}

int countCmdArg(int number)
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

int checkAlpha(string text)
{
    int counter = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (!isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

string vigenereCipher(string text, string keyword)
{
    string ciphertext = text; //Assign a value to this string to silence the warning from compiler.
    for (int i = 0, counterForKeyword = 0, textLength = strlen(text), wordLength = strlen(keyword); i < textLength; i++)
    {
        int key = tolower(keyword[counterForKeyword]) - 'a';
        //Calculate the key in each loop. Convert each char to lowercase to remove case sensitivity.
        if (isalpha(text[i])) //Encrypt alphabetical characters ONLY.
        {
            if (islower(text[i]))
            {
                ciphertext[i] = (text[i] - 'a' + key) % numberOfAlphabet + 'a';
                counterForKeyword++; //Counter for keyword only increments when a char in plaintext is encrypted.
            }

            else if (isupper(text[i]))
            {
                ciphertext[i] = (text[i] - 'A' + key) % numberOfAlphabet + 'A';
                counterForKeyword++; //Counter for keyword only increments when a char in plaintext is encrypted.
            }
        }
        else // Do nothing to non-alphabetical char and leave 'em be.
        {
            ciphertext[i] = text[i];
        }
        if (counterForKeyword > wordLength - 1) //Reset counter for keyword to 0 when the counter hits the last char in keyword.
        {
            counterForKeyword = 0;
        }
    }
    return ciphertext;
}