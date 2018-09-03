/* Helpers functions for music:
The program reads computer-friendly music sheet, translates the notes and their duration,
and hands the information to a synthesizer program to create music.
*/

#define C4ToA4 9
#define D4ToA4 7
#define E4ToA4 5
#define F4ToA4 4
#define G4ToA4 2
#define B4ToA4 2
#include <cs50.h>
#include <ctype.h> //Added to be able to use isdigit
#include <math.h> //Added to be able to use pow()
#include <string.h> //Added to be able to use strcmp()
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int noteLength = 0;
    int numerator = atoi(&fraction[0]);
    int denominator = atoi(&fraction[2]);
    if (denominator == 8) //For notes of the length of 1/8
    {
        noteLength = numerator;
    }
    else if (denominator < 8) //For notes of length other than 1/8
    {
        noteLength = 8 / denominator;

    }
    return noteLength;
}

// Calculates frequency (in Hz) of a note
//The function can be largely simplified. Need to figure that out.
int frequency(string note)
{
    float noteFrequency = 0.0; //Use float instead of int to get as precise number as possible.
    int octave = 0;
    float A4 = 440.00;
    if (isdigit(note[1]))
        //When there's no accidental ('#' or 'b')
    {
        octave = atoi(&note[1]);
    }
    else
        //When there's an accidental
    {
        octave = atoi(&note[2]);
    }

    if (8 >= octave && octave > 4)
        //Moving up in the octave
    {
        if (note[0] == 'A')
        {
            int move = octave - 4;
            noteFrequency = A4;
            for (int i = 0; i < move; i++)
            {
                noteFrequency = noteFrequency * 2;
            }
        }
        else if (note[0] == 'C')
        {
            int distanceFromA4 = 0;
            if (octave == 5) //Interval from A4 to C5 is different from to C6 - 8.
            {
                distanceFromA4 = 12 - C4ToA4;
            }
            distanceFromA4 = 12 * (octave - 5) + 3;
            noteFrequency = pow(2, (1 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'D')
        {
            int distanceFromA4 = 0;
            if (octave == 5) //Interval from A4 to D5 is different from to D6 - 8.
            {
                distanceFromA4 = 12 - D4ToA4;
            }
            distanceFromA4 = 12 * (octave - 5) + (12 - D4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'E')
        {
            int distanceFromA4 = 0;
            if (octave == 5) //Interval from A4 to E5 is different from to E6 - 8.
            {
                distanceFromA4 = 12 - E4ToA4;
            }
            distanceFromA4 = 12 * (octave - 5) + (12 - E4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'F')
        {
            int distanceFromA4 = 0;
            if (octave == 5) //Interval from A4 to F5 is different from to F6 - 8.
            {
                distanceFromA4 = 12 - F4ToA4;
            }
            distanceFromA4 = 12 * (octave - 5) + (12 - F4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'G')
        {
            int distanceFromA4 = 0;
            if (octave == 5) //Interval from A4 to G5 is different from to G6 - 8.
            {
                distanceFromA4 = 12 - G4ToA4;
            }
            distanceFromA4 = 12 * (octave - 5) + (12 - G4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'B') //Interval from A4 to B5 - 8 follows the same pattern.
        {
            int distanceFromA4 = 12 * (octave - 4) + B4ToA4;
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        if (note[1] == '#') //In case where there's accidental.
        {
            noteFrequency = noteFrequency * pow(2, 1.0 / 12.0);
        }
        else if (note[1] == 'b')
        {
            noteFrequency = noteFrequency / pow(2, 1.0 / 12.0);
        }
    }
    else if (0 <= octave && octave < 4)
        //Moving down in the octave
    {
        if (note[0] == 'A')
        {
            int move = 4 - octave;
            noteFrequency = A4;
            for (int i = 0; i < move; i++)
            {
                noteFrequency = noteFrequency / 2;
            }
        }
        else if (note[0] == 'C')
        {
            int distanceFromA4 = -(12 * (4 - octave) + C4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'D')
        {
            int distanceFromA4 = -(12 * (4 - octave) + D4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'E')
        {
            int distanceFromA4 = -(12 * (4 - octave) + E4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'F')
        {
            int distanceFromA4 = -(12 * (4 - octave) + F4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'G')
        {
            int distanceFromA4 = -(12 * (4 - octave) + G4ToA4);
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        else if (note[0] == 'B')
        {
            int distanceFromA4 = 0;
            if (octave == 3) //A4 - B3 differs from A4 to B2 - 0.
            {
                distanceFromA4 = -(12 - B4ToA4);
            }
            distanceFromA4 = -(12 * (3 - octave) + (12 - B4ToA4));
            noteFrequency = pow(2, (1.0 / 12.0) * distanceFromA4) * A4;
        }
        if (note[1] == '#') // In case where there's accidental.
        {
            noteFrequency = noteFrequency * pow(2, 1.0 / 12.0);
        }
        else if (note[1] == 'b')
        {
            noteFrequency = noteFrequency / pow(2, 1.0 / 12.0);
        }
    }
    else if (octave == 4)
    {
        if (note[0] == 'A')
        {
            noteFrequency = A4;
        }
        else if (note[0] == 'C')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * -(C4ToA4)) * A4;
        }
        else if (note[0] == 'D')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * -(D4ToA4)) * A4;
        }
        else if (note[0] == 'E')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * -(E4ToA4)) * A4;
        }
        else if (note[0] == 'F')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * -(F4ToA4)) * A4;
        }
        else if (note[0] == 'G')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * -(G4ToA4)) * A4;
        }
        else if (note[0] == 'B')
        {
            noteFrequency = pow(2, (1.0 / 12.0) * (B4ToA4)) * A4;
        }
        if (note[1] == '#')
        {
            noteFrequency = noteFrequency * pow(2, 1.0 / 12.0);
        }
        else if (note[1] == 'b')
        {
            noteFrequency = noteFrequency / pow(2, 1.0 / 12.0);
        }
    }
    int result = round(noteFrequency);
    return result;
}

// Determines whether a string represents a rest
// A rest is represented by a blank line in the txt file.
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
        //If the line is blank(i.e."") then is_rest returns true;
    {
        return true;
    }
    else
        //if not, then returns false.
    {
        return false;
    }
}