#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z)
{
    double powVal = (double)pow(x, 2) + (double)pow(y, 2) + (double)pow(z, 2);
    return (double)sqrt(powVal);
}