#include "dynaAllocTwoDimArr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the missing function here
char **allocate_memory(int *xdim, int ydim)
{
	char **arr_p;
	arr_p = malloc(ydim * sizeof(char *));

	for (int i = 0; i < ydim; i++)
	{
		arr_p[i] = malloc(xdim[i] + 1);
	}

	return arr_p;
}

void free_array(char **w, int ydim)
{
	for (int j = 0; j < ydim; j++)
	{
		free(w[j]);
	}
	free(w);
}

void print_array(char **words, int num)
{
	for (int j = 0; j < num; j++)
	{
		printf("%s\n", words[j]);
	}
}

void copy_to_array(char **dest, char **src, int num)
{
	for (int j = 0; j < num; j++)
	{
		strcpy(dest[j], src[j]);
	}
}
