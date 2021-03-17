#include "source.h"
#include <stdlib.h>
#include <stdio.h>

/* Dynamic Array Reader */
/* Parameters:
 * n: Number of values to be read
 * 
 * Returns: pointer to the dynamically allocated array
 */
int *create_dyn_array(unsigned int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr != NULL)
    {
        for (unsigned int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        return arr;
    }
    free(arr);
    return NULL;
}

/* Add to array */
/* Parameters:
 * arr: Existing array of integers
 * num: number of integers in the array before the call
 * newval: new value to be added
 * 
 * Returns: pointer to the allocated array
 */
int *add_dyn_array(int *arr, unsigned int num, int newval)
{
    int *newArr = (int *)realloc(arr, (num + 1) * sizeof(int));
    if (newArr != NULL)
    {
        newArr[num] = newval;
        return newArr;
    }

    free(newArr);
    return NULL;
}

/* 
// Aalto's answer
int* create_dyn_array(unsigned int n) {
    int* array = malloc(n * sizeof(int));

    for(int i=0; n > 0; i++) {
        int ret = scanf("%d", &array[i]);
        
        if(ret != 1) {
            printf("Reading failed!\n");
            return array;
        }
        n--;
    }

    return array;
}

int* add_dyn_array(int* arr, unsigned int num, int newval) {
    arr = realloc(arr, (num + 1) * sizeof(int));
    arr[num] = newval;
    return arr;
}
 */
