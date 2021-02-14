#include "source.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/* Remove all hash occurrences in string */
/* Parameters:
 * str: string to be handled 
 * startFrom: start index to traverse
 * */
void removeHashStartFrom(char *str, const int startFrom)
{
    for (int i = startFrom; str[i] != '\0'; i++)
    {
        for (int j = i; str[j] != '\0'; j++)
        {
            str[j] = str[j + 1];
        }
        // Since a character is removed, i shouldn't be incremented
        i--;
    };
}

/* Get length of string until the first occurrence of provided character */
/* Parameters:
 * s: string to be looked in
 * c: char thats end the count
 * Returns: string length.*/
unsigned int getLenUntilChar(const char *s, const char c)
{
    int count = 0;
    while (*s)
    {
        if (*s == c)
            break;
        count++;
        s++;
    }
    return count;
}

/* Print string */
/* Parameters:
 * s: string to be printed */
void qstr_print(const char *s)
{
    int strLen = getLenUntilChar(s, '?');

    char result[200];
    memset(result, '#', 199);
    result[199] = 0;

    for (int i = 0; i < strLen; i++)
        result[i] = s[i];

    removeHashStartFrom(result, strLen);

    printf("%s", result);
}

/* String length */
/* Parameters:
 * s: string to be evaluated
 * Returns: length of the string */
unsigned int qstr_length(const char *s)
{
    return getLenUntilChar(s, '?');
}

/* String cat */
/* Parameters:
 * dst: buffer to which the new string is appended
 * src: string to be appended
 * Returns: Number of characters in the new string */
int qstr_cat(char *dst, const char *src)
{
    int dstLen = qstr_length(dst);
    int srcLen = qstr_length(src);

    for (int i = 0; i <= srcLen; i++)
    {
        char charOfSrc = src[i];

        dst[dstLen] = charOfSrc;
        if (charOfSrc != '?')
            dstLen++;
    }

    return dstLen;
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