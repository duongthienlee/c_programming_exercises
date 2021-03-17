#include "source.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* Print string */
/* Parameters:
 * s: string to be printed */
void qstr_print(const char *s)
{
    for (int i = 0; s[i] != '?'; i++)
        printf("%c", s[i]);
}

/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s)
{
    int n = 0;
    for (; s[n] != '?'; n++)
        ;
    return n;
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char *dst, const char *src)
{
    int i = 0;
    for (; dst[i] != '?'; i++)
        ;

    for (unsigned int j = 0; j <= qstr_length(src); j++, i++)
    {
        dst[i] = src[j];
    }

    return qstr_length(dst);
}

/* String strstr */
const char *qstr_strstr(const char *str1, const char *str2)
{
    const char *haystack = str1, *needle = str2;
    for (;;) // loop until return is called
    {
        // pointer of needle reaches the end or the character is '?'
        if (!*needle || *needle == '?')
        {
            return str1;
        }

        // pointer of haystack reaches the end or the character is '?' but no substr found.
        if (!*haystack || *haystack == '?')
            return NULL;
        /* check current char in haystack == current char in needle
         * then increment pointer address of both */
        if (*haystack++ == *needle++)
            /* similar to break statement but it allows to continue the loop
             * but skips everything below
             **/
            continue;

        haystack = ++str1; // assign next pointer address of str1 to haystack
        needle = str2;     // assign initial pointer address of str2 aka substring to needle
    }
    return NULL;
}

/* 
// Aalto's answer
const char* qstr_strstr(const char* str1, const char* str2) {
    for(unsigned int i=0; i<qstr_length(str1); i++) {
        if(str1[i] == str2[0]) { // First character match
            for(int j=i, k=0; str1[j]==str2[k]; ) {
                k++;
                j++;

                if(str2[k] == '?') {
                    // Found substring!
                    return &str1[i];
                }
            }
        }
    }

    return NULL;
}

 */