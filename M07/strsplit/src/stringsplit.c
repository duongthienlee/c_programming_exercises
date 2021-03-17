#include "stringsplit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_array_append(char **array, size_t nitems, const char *item, size_t itemlen)
{
    char *copy;
    if (item == NULL)
        copy = NULL;
    else
    {
        copy = malloc(itemlen + 1);
        if (copy == NULL)
            return NULL;
        memcpy(copy, item, itemlen);
        copy[itemlen] = '\0';
    }

    array = realloc(array, (nitems + 2) * sizeof(array[0]));
    if (array == NULL)
    {
        free(copy);
        return NULL;
    }

    array[nitems] = copy;
    array[nitems + 1] = NULL;
    return array;
}

/* Split string by another string, return split parts + NULL in array.
 *
 * Parameters: 
 *  str: the string to split
 *  split: the string to split str with
 *
 * Returns:
 *  A dynamically reserved array of dynamically reserved string parts.
 *
 * For example called with "Test string split" and " ",
 * returns ["Test", "string", "split", NULL].
 * Or called with "Another - test" and " - ",
 * returns ["Another", "test", NULL].
 */

char **split_string(const char *str, const char *split)
{
    size_t nitems = 0;
    char **array = NULL;
    const char *start = str;
    char *next = strstr(start, split);
    size_t seplen = strlen(split);
    const char *item;
    size_t itemlen;

    for (;;)
    {
        next = strstr(start, split);
        if (next == NULL)
        {
            char **new = str_array_append(array, nitems, start, strlen(start));
            if (new == NULL)
            {
                free_split_string(array);
                return NULL;
            }
            array = new;
            ++nitems;
            break;
        }
        else if (next == str)
        {
            item = "";
            itemlen = 0;
        }
        else
        {
            item = start;
            itemlen = next - item;
        }
        char **new = str_array_append(array, nitems, item, itemlen);
        if (new == NULL)
        {
            free_split_string(array);
            return NULL;
        }
        array = new;
        ++nitems;
        start = next + seplen;
    }

    if (nitems == 0)
    {
        array = str_array_append(array, nitems, str, strlen(str));
    }

    return array;
}

void print_split_string(char **split_string)
{
    int i = 0;
    while (*(split_string + i) != NULL)
    {
        printf("%s\n", *(split_string + i));
        i++;
    }
}

void free_split_string(char **split_string)
{
    if (split_string == NULL)
        return;
    for (size_t i = 0; split_string[i] != NULL; ++i)
        free(split_string[i]);
    free(split_string);
}

/* 
// Aalto's answer

char** split_string(const char* str, const char* split) {
    // Create an array
    char** array = malloc(sizeof(char*));
    array[0] = NULL;

    int c = 0;

    // Loop through the str
    while(1) {
        // Find the split
        char* ptr = strstr(str, split);

        if(!ptr)
            break;

        // Allocate more memory
        array = realloc(array, (c+2) * sizeof(char*));
        array[c+1] = NULL;

        int len = ptr-str;

        // Reserve memory part
        array[c] = calloc(len+1, sizeof(char));

        // Copy the part of the string
        strncpy(array[c], str, len);

        str = ptr + strlen(split);
        c++;
    }

    int l = strlen(str);
    array = realloc(array, (c+2) * sizeof(char*));
    array[c] = calloc(l+1, sizeof(char));
    strncpy(array[c], str, l);
    array[c+1] = NULL;

    // Return the array
    return array;
}

void print_split_string(char** split_string) {
    for(int i=0; split_string[i]!=NULL; i++) {
        printf("%s\n", split_string[i]);
    }
}

void free_split_string(char** split_string) {
    for(int i=0; split_string[i]!=NULL; i++) {
        free(split_string[i]);
    }

    free(split_string);
}
 */