#include <stdio.h>
#include <math.h>
#include "source.h"

void draw_triangle(unsigned int size)
{
    char sharp = '#';
    char dot = '.';

    for (unsigned int o = 1; o <= size; o++)
    {
        for (unsigned int i = 0; i < size - o; i++)
        {
            printf("%c", dot);
        };

        for (unsigned int n = 0; n < o; n++)
        {
            printf("%c", sharp);
        };
        printf("\n");
    }
}


/* 
// Aalto's answer
void draw_triangle(unsigned int size) {
    for(unsigned int y = 1; y <= size; y++) {
        for(unsigned int x = 1; x <= size; x++) {
            if(y <= size-x)
                printf(".");
            else
                printf("#");
        }
        
        printf("\n");
    }
} */
