//The program uses Greedy algorithm to calculate the minimum number of coins needed for change.
#include <stdio.h>
#include <cs50.h>

int main()
{
    float input;
    do
    {
        input = get_float("Change owed: ");
    }
    while (input < 0);
    int change = 1000 * input / 10;
    //Multiplied by 1000 to avoid bugs caused by imprecision and downsize back via dividing by 10.
    int counter = 0;
    if (change >= 25)
    {
        counter = change / 25;
        //The counter is the quotient in this division.
        change = change % 25;
        //The leftover change that can't be divided by 25 is obtained through modulo.
    }
    if (25 > change && change >= 10)
    {
        counter = counter + (change / 10);
        //The counter keeps going in each level.
        change = change % 10;
        //The carryover is also constantly being updated.
    }
    if (10 > change && change >= 5)
    {
        counter = counter + (change / 5);
        change = change % 5;
    }
    if (5 > change && change >= 1)
    {
        counter = counter + change;
        change = 0;
        //Because at this point there's no change left for further calculation.
    }
    if (change == 0)
        //When user punches in 0 or the remaining change becomes 0.
    {
        printf("%i\n", counter);
    }
}