
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
void sort(int *arr, int n)
{
   
    int i, j, min_idx; 
  
    for (i = 0; i <= n; i++) 
    { 
        // assume first index is the minimum
        min_idx = i; 
        // loop look ahead with index start at i index +1
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    }
}
