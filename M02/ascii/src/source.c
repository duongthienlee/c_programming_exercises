#include "source.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void ascii_chart(char min, char max)
{
    for (int i = min; i <= max; i++)
    {
        /* three-character field that shows the given number as an integer. If the number
         * takes less than three characters (it is < 100), it is aligned right.
         * %3d Denotes field length/width.
         */
        printf("%3d 0x%02x", i, i);
        // check if character is printable with isprint
        if (isprint(i) == 0)
            printf(" ?");
        else
            printf(" %c", i);

        // break line at the fourth column
        if ((i - min + 1) % 4 == 0)
            printf("\n");
        else
            printf("\t");
    }
}
