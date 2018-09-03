//The program validates a credit card number and identifies what company issued the card.
#include <stdio.h>
#include <cs50.h>

int checkSum_EveryOther(long long number); //Calculate the sum of every other digit multiplied by 2.
int checkSum_TheRest(long long number); // Calculate the sum of the rest of the digits.
int cardValidate(int sum1, int sum2); // Check if the above two added together gives a number that ends in 0.
int numLength(long long number); // Calculate the length of the card number.
int identifyCompany(long long number); // Give the first two digits of the card number.

int main()
{
    long long cardNum = get_long_long("Number: "); //Prompt credit card number from user.
    int a = checkSum_EveryOther(cardNum); //Store the sum of every other digit multiplied by 2 into a variable.
    int b = checkSum_TheRest(cardNum); //Store the sum of the rest of the digits into another.
    if (!cardValidate(a, b)) // When the sum of a and b doesn't end in 0.
    {
        printf("INVALID\n");
    }
    else
    {
        if (numLength(cardNum) == 15 && identifyCompany(cardNum) == 34)
        {
            printf("AMEX\n");
            return 0;
        }
        if (numLength(cardNum) == 15 && identifyCompany(cardNum) == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        if (numLength(cardNum) == 16 && 51 <= identifyCompany(cardNum) && identifyCompany(cardNum) <= 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        if (numLength(cardNum) == 16 && identifyCompany(cardNum) / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        if (numLength(cardNum) == 13 && identifyCompany(cardNum) / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
}

int checkSum_EveryOther(long long number)
{
    int firstSum = 0;
    int firstLength = numLength(number) / 2;
    //Every other digit is needed in this calculation. The number of such digits can be obtained through
    //dividing the length of the given sequence of numbers.
    for (int i = 0; i < firstLength; i++)
    {
        if (number / 10 % 10 * 2 >= 10)
            //If the product equals to or is greater than 10, it should be broken down into 2 digits.
        {
            firstSum = firstSum + (number / 10 % 10 * 2) / 10 + (number / 10 % 10 * 2) % 10;
        }
        else
        {
            firstSum = firstSum + number / 10 % 10 * 2;
        }
        number = number / 100;
    }
    return firstSum;
}

int checkSum_TheRest(long long number)
{
    int secondSum = 0;
    int secondLength = numLength(number) - numLength(number) / 2;
    for (int i = 0; i < secondLength; i++)
    {
        secondSum = secondSum + number % 10;
        number = number / 100;
    }
    return secondSum;
}

int cardValidate(int sum1, int sum2)
{
    if ((sum1 + sum2) % 10 == 0)
        // If the total sum modulo 10 results in 0, that means the total sum indeed ends in 0.
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int numLength(long long number)
{
    int counter = 0;
    while (number > 10)
    {
        number = number / 10;
        counter++;
    }
    return counter + 1;
}

int identifyCompany(long long number)
{
    int identifier = 0;
    int length = numLength(number);
    for (int i = 0, l = length - 2; i < l; i++)
    {
        number = number / 10;
    }
    identifier = number;
    return identifier;
}