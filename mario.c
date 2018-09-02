#include <stdio.h>
#include <cs50.h>

int main()
{
    int height;
    do
    {
        height = get_int("Height (A positive integer no greater than 23): ");
    }
    while (height < 0 || height > 23); //Safe guard the input.
    for (int i = 0; i < height; i++)
    {
        //The following two for loops are copied from marioEasy with slihgt modification.
        for (int x = height - 1; x > i; x--)
        {
            printf(" ");
        }
        for (int n = 0, l = i + 1; n < l; n++)
            //So the printing will start from one instead of two hashes.
        {
            printf("#");
        }
        for (int t = 0, p = 2; t < p; t++) //The space in the middle is always 2.
        {
            printf(" ");
        }
        for (int n = 0, l = i + 1; n < l; n++)
            //This is just the modified pyramid without the space in the beginning.
        {
            printf("#");
        }
        printf("\n");
    }
}