
#include "source.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* Selection sort */
/* Parameters:
 * start: start of an array
 * size: length of an array
 * {3, 4, 7, 2, 8}
 */
void sort(int *start, int size)
{

    int i, j, min_idx;

    for (i = 0; i <= size; i++)
    {
        // assume first index is the minimum
        min_idx = i;
        // loop look ahead with index start at i index +1
        for (j = i + 1; j < size; j++)
            if (start[j] < start[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&start[min_idx], &start[i]);
    }
}

/* 
// Aalto's answer
void sort(int* start, int size) {
    for(int i=0; i<size; i++) {
        int smallest_idx = i;

        for(int j=i; j<size; j++) {
            if(start[j] < start[smallest_idx])
                smallest_idx = j;
        }

        int temp = start[i];
        start[i] = start[smallest_idx];
        start[smallest_idx] = temp;
    }
}
 */