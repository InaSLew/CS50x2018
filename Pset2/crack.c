//The program handles passwords consisted of 1 to 4 alphabetical characters just fine,
//but for the ones that have five characters and case variation,
//manual configuration in crackFiveAlpha is needed to be able to hack it.
#define _XOPEN_SOURCE
#define numberOfAlphabet 52
#define numberOfCmdArg 2
#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <string.h>

int countCmdArg(int number); //Safeguard the number of cmdline arguments received.
void crackSingleAlpha(string password, string salt); //Cover both upper- and lowercase.
void crackTwoAlpha(string password, string salt); //Cover both upper- and lowercase.
void crackThreeAlpha(string password, string salt); //Cover both upper- and lowercase.
void crackFourAlpha(string password, string salt); //Cover both upper- and lowercase.
void crackFiveAlpha(string password, string salt); //Need configuration to be able to hack the password.

int main(int argc, string argv[])
{
    if (!countCmdArg(argc))
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
    string hashedPasswd = argv[1];
    char salt[2] = {hashedPasswd[0], hashedPasswd[1]};
    //Get the salt from the first chars in the hashed password.
    crackSingleAlpha(hashedPasswd, salt); //For one-character key
    crackTwoAlpha(hashedPasswd, salt); //For two-character key
    crackThreeAlpha(hashedPasswd, salt); //For three-character key
    crackFourAlpha(hashedPasswd, salt); //For four-character key
    crackFiveAlpha(hashedPasswd, salt); //For five-character key
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

void crackSingleAlpha(string password, string salt)
{
    string allAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char singleAlpha[2];
    singleAlpha[1] = '\0';
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        singleAlpha[0] = allAlphabet[i];
        if (strcmp(crypt(singleAlpha, salt), password) == 0)
        {
            printf("%s\n", singleAlpha);
            return;
        }
    }
}
void crackTwoAlpha(string password, string salt)
{
    string allAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char twoAlpha[3];
    twoAlpha[2] = '\0';
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        twoAlpha[0] = allAlphabet[i]; //For when the first char is lowercase
        for (int n = 0; n < numberOfAlphabet; n++)
        {
            twoAlpha[1] = allAlphabet[n];
            if (strcmp(crypt(twoAlpha, salt), password) == 0)
            {
                printf("%s\n", twoAlpha);
                return;
            }
        }
    }
}
void crackThreeAlpha(string password, string salt)
{
    string allAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char threeAlpha[4];
    threeAlpha[3] = '\0';
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        threeAlpha[0] = allAlphabet[i];
        for (int n = 0; n < numberOfAlphabet; n++)
        {
            threeAlpha[1] = allAlphabet[n];
            for (int x = 0; x < numberOfAlphabet; x++)
            {
                threeAlpha[2] = allAlphabet[x];
                if (strcmp(crypt(threeAlpha, salt), password) == 0)
                {
                    printf("%s\n", threeAlpha);
                    return;
                }
            }
        }
    }
}
void crackFourAlpha(string password, string salt)
{
    string allAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char fourAlpha[5];
    fourAlpha[4] = '\0';
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        fourAlpha[0] = allAlphabet[i];
        for (int n = 0; n < numberOfAlphabet; n++)
        {
            fourAlpha[1] = allAlphabet[n];
            for (int x = 0; x < numberOfAlphabet; x++)
            {
                fourAlpha[2] = allAlphabet[x];
                for (int y = 0; y < numberOfAlphabet; y++)
                {
                    fourAlpha[3] = allAlphabet[y];
                    if (strcmp(crypt(fourAlpha, salt), password) == 0)
                    {
                        printf("%s\n", fourAlpha);
                        return;
                    }
                }
            }
        }
    }
}
void crackFiveAlpha(string password, string salt)
{
    string allAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char fiveAlpha[6];
    fiveAlpha[5] = '\0';
    for (int i = 0; i < numberOfAlphabet; i++)
    {
        fiveAlpha[0] = allAlphabet[i];
        for (int n = 0; n < numberOfAlphabet; n++)
        {
            fiveAlpha[1] = allAlphabet[n];
            for (int x = 0; x < numberOfAlphabet; x++)
            {
                fiveAlpha[2] = allAlphabet[x];
                for (int y = 0; y < numberOfAlphabet; y++)
                {
                    fiveAlpha[3] = allAlphabet[y];
                    for (int z = 0; z < numberOfAlphabet; z++)
                    {
                        fiveAlpha[4] = allAlphabet[z];
                        if (strcmp(crypt(fiveAlpha, salt), password) == 0)
                        {
                            printf("%s\n", fiveAlpha);
                            return;
                        }
                    }
                }
            }
        }
    }
}