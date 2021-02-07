#Basic Course in C programming.

Some of the texts below here are quoted from Aalto university.
I rewrite some of them to make it easy for me to understand and remember.

### Pointers
A pointer takes 4 bytes from the memory.
```
void main(void)
{
    char a = 10;
    char b = 12;
    int c = 123456;
    char *d = &a;
    char *e;

    e = d; // this copies the address of the pointer d
    printf("*e: %d   e: %p\n", *e, e);  // Output *e: 10   e: 0x7fff8e3c8f22
   
    *d = 13;
    printf("*d: %d   d: %p   *e: %d   a: %d   c: %d\n", *d, d, *e, a, c);
    // above outputs *d: 13   d: 0x7fff8e3c8f22   *e: 13   a: 13   c: 123456
    if (*d > b)
        printf("New value is greater than b!\n");
        // above output New value is greater than b!
}
```
>Variables a and b use one byte of memory each, and variable c takes
4 bytes.
As the variables are declared, their initial values are set. If this was not done, the memory would be allocated in the similar way, but its content would be unspecified. Variable d is a pointer to a char-type value in memory, and it is initialized to point to the location of variable a using an **address operator (&)**. Even though it points to a char-type value, variable d takes four bytes from the memory, because it is a pointer: its value is a memory address (in this example we assume that addresses are 32 bits long)
>
>A pointer variable is declared and initialized, using the **dereferencing operator ( * )** after the data type. The value referenced by a pointer can be accessed using the ***dereferencing operator ( * )**.
> To get the value of pointer in hexadecimal format, use **%p**.
>**The dereferencing operator** can also be used to modify the memory the pointer is referencing.

>When function exits, the memory allocated for local variables is released. This is not a problem for the basic data types, because compiler raises an error if the program tries to use the variable from outside the scope it was declared. However, when referring to the variable via pointers, the compiler cannot protect the programmer from referring to invalid memory location. Therefore careless use of pointers may cause problems, for example when referring to memory that has already been released for other use.
>Like other types of variables, an uninitialized pointer has unknown value. Use of such pointer will likely cause the program to crash.


### Pointers in functions

When pointer is used as parameters in function call: there are two ways to set it. Either by
creating a new pointer or using **address operator (&)**.
```
int main(void)
{
    int a;
    int *ptr_a = &a;
    my_readint(ptr_a) // first way using a new pointer.
    my_readint(&a); // second way using address operator directly.
}
```
#### Useful tips to convert ASCII-character string to int number
For example, to get number from `scanf` function in which format parameter 
is `%c` aka ASCII-character, subtract
the value to a string contain zero digit. i.e. '0'.
```
char c;
scanf("%c", &c);  // read one ASCII-character
int num = c - '0';   // convert it to the corresponding number
```
### Pointers usage with array (Address arithmetics)
We can assign the start of the array to a pointer
```
#include <stdio.h>

int main(void)
{
    int array[50];  // reserve space for 50 integers
    int *intPtr = array;  // assign the start of the array to a pointer
    int i = 50;
    while (i > 0) {
        *intPtr = i * 2;  // write i*2 to the location indicated by the pointer
        intPtr++;  // move the pointer to the next element
        i--;
    }

    intPtr = array;  // move the pointer back to the beginning of the array

    for (i = 0; i < 50; i++) {
        int value = *(intPtr + i);  // retrieve the i:th element in the array
        printf("%d ", value);
    }
}
```
### Arrays
```
/* Initialize array without declaration but specify the size of 4 elements aka 4 memory slots.
 * The system allocate enough memory ( 4 short int = 2 bytes * 4) for 4 short data type elements.
 */
short slots[4]; 

/* Initialize array with declaration but no need to specify the size memory slots.
 */
int slots[] = { 12 ,3 ,4 ,15}; 

/*
 * If initialization list is shorter than the explicitly given array length, 
 * the unspecified values are *initialized to 0. This is true only if the
 * initialization list contains at least one element.
 */
 int table[1000] = { 0 };
```
Assign value to a slot of an array by using array notation 
**`slots[index] = 10`**

To access the value, we can either use the above array notation or [pointer arithmetics](#pointers-usage-with-array-address-arithmetics). i.e. 
**`slots[index]`** or **`*(slots + index)`**

***Notice***: `*** stack smashing detected ***: <unknown> terminated` is an error message indicates
the access index is not within the array bounds. For example: array size if 5, but the access
index is also 5.
```
short slots[4] = {0};
slots{4} // throw mentioned above error.
```

### Arrays in function
>Arrays can be passed as function arguments, but the array operator is usually not used in that case. Arrays are rather passed using a pointer type, where the pointer refers to the first element in array. The length of the array cannot be read from the function parameter, but it needs to be indicated by some other means. Here are some solutions:
>* Pass the length as another function parameter which tells directly how many elements are in the array
>* Indicate the end of an array by some special value after the last element. In this latter case the allocated length of the array needs to have extra space for the end marker.
>* If the data type of the array is integer, its size can be told in the first element of the of the array (data communication protocols are designed like this).
>* etc…

The third way can be illustrated in the following example:
```
long array[30] = { 3, 6, 12, 24};
int sizeOfArr = sizeof(array)/sizeof(long);
```
