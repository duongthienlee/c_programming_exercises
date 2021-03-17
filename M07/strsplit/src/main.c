#include <stdio.h>
#include <stdlib.h>
#include "stringsplit.h"

int main() {
   /*  char str1[] = "Test string split with this test string"; */
    char str2[] = "Split_ab!#this_ab!#case_ab!#correctly_ab!#too!";

    /* char** str1_split = split_string(str1, " "); */
    char** str2_split = split_string(str2, "_ab!#");
    
/*     printf("\"%s\" split:\n", str1);
    print_split_string(str1_split); */

    printf("\n\"%s\" split:\n", str2);
    print_split_string(str2_split);
    
 /*    free_split_string(str1_split); */
    free_split_string(str2_split);

    return 0;
}
