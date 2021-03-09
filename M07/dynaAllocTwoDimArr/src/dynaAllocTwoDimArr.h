#ifndef AALTO_STRINGSPLIT_H
#define AALTO_STRINGSPLIT_H

char **allocate_memory(int *xdim, int ydim);
void free_array(char **w, int ydim);
void print_array(char **words, int num);
void copy_to_array(char **dest, char **src, int num);

#endif
