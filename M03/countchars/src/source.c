#include <stdio.h>

unsigned int arraylen(const char *array)
{
    unsigned int len = 0;

    while (*array)
    {
        len++;
        array++;
    }

    return len;
}

void countchars(const char *array, unsigned int *counts)
{
    int len = arraylen(array);
    for (int i = 0; i < len; i++)
    {
        char ele = array[i];
        for (int n = 'a'; n <= 'z'; n++)
        {
            char letter = (char)n; // convert to char
            if (ele == letter)
            {
                counts[n] = *(counts + n) + 1;
            }
        }
    }
}