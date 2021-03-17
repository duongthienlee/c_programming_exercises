
#include "source.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *remove_single_line_comments(char *input)
{
    int i = 0;
    while (input[i])
    {
        if (input[i] == '/' && input[i + 1] == '/')
        {
            int j = i;
            while (input[j] != '\n')
            {
                memmove(&input[j], &input[j + 1], strlen(input) - j);
            }
            if (input[j] == '\n')
                memmove(&input[j], &input[j + 1], strlen(input) - j);
        }

        ++i;
    }
    return input;
}

char *remove_multi_line_comments(char *input)
{
    int i = 0;
    while (input[i])
    {
        if (input[i] == '/' && input[i + 1] == '*')
        {
            int j = i;
            while (1)
            {
                if (input[j] == '*' && input[j + 1] == '/')
                {
                    memmove(&input[j], &input[j + 1], strlen(input) - j);
                    memmove(&input[j], &input[j + 1], strlen(input) - j);
                    break;
                }
                memmove(&input[j], &input[j + 1], strlen(input) - j);
            }
        }

        ++i;
    }
    return input;
}

/* Remove C comments from the program stored in memory block <input>.
 * Returns pointer to code after removal of comments.
 * Calling code is responsible of freeing only the memory block returned by
 * the function.
 */
char *delete_comments(char *input)
{
    input = remove_single_line_comments(input);
    input = remove_multi_line_comments(input);
    return input;
}


/* 
// Aalto's answer

char* delete_comments(char* input) {
    char* output = malloc(strlen(input)+1);
    int j = 0;
    for(unsigned int i=0; i<strlen(input); i++) {
        if(input[i] == '/' && input[i+1] == '/') {
            while(input[i] != '\n')
                i++;
        } else if(input[i] == '/' && input[i+1] == '*') {
            while(input[i] != '*' || input[i+1] != '/') 
                i++;
            i++;
        } else {
            output[j] = input[i];
            j++;
        }
    }

    output[j] = 0;

    free(input);

    return output;
}
 */