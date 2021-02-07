#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    char sharp = '#';
    char dot = '.';

    scanf("%u", &size);

    for (int o = 1; o <= size; o++)
    {
        for (int i = 0; i < size - o; i++)
        {
            printf("%c", dot);
        };

        for (int n = 0; n < o; n++)
        {
            printf("%c", sharp);
        };
        printf("\n");
    }
}
