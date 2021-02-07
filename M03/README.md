#Basic Course in C programming.

All the text below here is from Aalto university.
I pasted some topics that I found important to remember for quick reference purpose.

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
