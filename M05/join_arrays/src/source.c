#include "source.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int *join_arrays(unsigned int n1, const int *a1,
				 unsigned int n2, const int *a2,
				 unsigned int n3, const int *a3)
{
	int sizeOfA1 = n1 * sizeof(int);
	int sizeOfA2 = n2 * sizeof(int);
	int sizeOfA3 = n3 * sizeof(int);
	int *arr = (int *)malloc(sizeOfA1 + sizeOfA2 + sizeOfA3);

	if (arr != NULL)
	{
		memcpy(arr, a1, sizeOfA1);
		memcpy(arr + n1, a2, sizeOfA2);
		memcpy(arr + n1 + n2, a3, sizeOfA3);
		return arr;
	}
	free(arr);
	return NULL;
}
