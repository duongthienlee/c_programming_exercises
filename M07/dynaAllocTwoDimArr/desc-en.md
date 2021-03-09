In this task, you are supposed to implement two functions that are 
responsible of the memory allocation and freeing for a multidimensional array.

Function char** allocate_memory(int* xdim, int ydim) creates a multidimensional
array variable that will contain char type elements and allocates memory for it.
The program will expect that memory is allocated first for pointers according to
parameter ydim. After that, for each pointer, memory should be allocated according
to elements in parameter xdim. This means that the first pointer should have enough
memory allocated to contain a string of length xdim[0] and so on. And since we are
dealing with strings, you should take into consideration the terminating nil.
Finally, return the created array.

Function void free_array(char** w, int ydim) will free all the memory allocated
for the multidimensional array w.