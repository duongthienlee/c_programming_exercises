#Basic Course in C programming.

All the text below here is from Aalto university.
I pasted some topics that I found important to remember for quick reference purpose.

### Formatted output
Here are some conversion types:
>**%d**: (int) – integer in decimal format  
**%u**: (unsigned int) – unsigned integer in decimal format  
**%o**: (unsigned int) – octal number  
**%x, %X**: (unsigned int) – hexadecimal number, using either lowercase letters (former) or uppercase letters (latter)  
**%c**: (int) – single character based on the used character encoding (e.g., ASCII), as discussed earlier with the character constants.  
**%s**: (char*) – string. We will take a more detailed look into strings in the next section.  
**%f**: (double) – floating point number (format: n.nnnnnn). Default number of decimals included in output is 6.  
**%e, %E**: (double) – floating point number (format: n.nnnnnnE+-xx)  
**%g, %G**: (double) – choose either %f or %e format, depending on the value of exponent.  
>

### Formatted input

>The following adjustments can be made on the formatting specification before one of the above letters, after the percent sign. Different adjustments can be combined, but they need to be in the following order:

>**number** (e.g %4d): Denotes field length/width.  
**minus** (-) (e.g. %-4d): align the output left of the available field, when the field **length** is specified.  
**plus** (+) (%+4d): for numeric conversion types, always include sign (+ or -).  
**0** for numeric conversion types with specified length, pad the field with leading zeros instead of space.  
**period followed by number** (%4.1f): for floating point numbers, the precision (number of decimals following the point).  
**h or l** (%ld): specifies that the argument is interpreted as short (h) or as long (l) form of the basic data type.  
>
