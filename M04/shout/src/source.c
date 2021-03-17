#include "source.h"
#include <ctype.h>

/* Remove all hash occurrences in string */
/* Parameters:
 * str: string to be handled 
 * startFrom: start index to traverse
 * */
void removeHashStartFrom(char *str, const int startFrom)
{
    for (int i = startFrom; str[i] != '\0'; i++)
    {
        for (int j = i; str[j] != '\0'; j++)
        {
            str[j] = str[j + 1];
        }
        // Since a character is removed, i shouldn't be incremented
        i--;
    };
}

char *my_toupper(char *dest, const char *src)
{
    int destIndex = 0;
    for (int i = 0; src[i] != '\0'; i++)
    {
        char srcChar = src[i];
        if (srcChar == '?')
            dest[destIndex] = '!';
        else if (srcChar == '.')
        {
            dest[destIndex] = '!';
            dest[destIndex + 1] = '!';
            dest[destIndex + 2] = '!';
            destIndex += 2;
        }
        else
            dest[destIndex] = toupper(srcChar);

        destIndex++;
    };

    removeHashStartFrom(dest, destIndex);
    return dest;
}

/* 
// Aalto's answer
    int j=0;
	for(int i=0; src[i]; i++, j++) {
        if(src[i] == '?') 
            dest[j] = '!';
        else if(src[i] == '.') {
            // store the !!! 

            // strcat looks for the '\0' at the end of the string,
            // so that needs to be added to the position we
            // want the !!! to go to:
            dest[j] = 0;
            strcat(dest, "!!!");
            j+=2;
            
            // you could do this also like
            
            // dest[j++] = '!';
            // dest[j++] = '!';
            // dest[j] = '!';
           
        } else {
            dest[j] = toupper(src[i]);
        }
    }

    dest[j] = 0;

    return dest;
}
 */